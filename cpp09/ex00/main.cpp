#include "BitcoinExchange.hpp"

void checkArgs(int ac) {
	if (ac != 2)
		throw std::runtime_error("invalid arguments");
}

void checkInput(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("could not open file");
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("invalid input format");
	while (std::getline(file, line)) {
		if ((line.length() < 14) || (line.substr(10, 3) != " | "))  // minimum: "YYYY-MM-DD | n"
			throw std::runtime_error("invalid input format");
	}
	file.close();
}

int main(int ac, char **av) {

	try {
		checkArgs(ac);
		checkInput(av[1]);
		BitcoinExchange btc(av[1]);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}