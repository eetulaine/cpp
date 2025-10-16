#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& input) {
	validateDatabase();
	std::cout << "\n";
	std::cout << "╔═════════════════════════════╗\n";
	std::cout << "║      BITCOIN EXCHANGE       ║\n";
	std::cout << "║     Open For Business 💰    ║\n";
	std::cout << "╚═════════════════════════════╝\n\n";
	validateInput(input);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::validateDatabase() {
	
	std::ifstream database("data.csv");
	if (!database.is_open())
		throw std::runtime_error("unable to open database");
	std::string line;

	std::getline(database, line); //skip the header line
	if (line != "date,exchange_rate")
		throw std::runtime_error("invalid database format");
	while (std::getline(database, line)) {
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			throw std::runtime_error("Error: invalid database format");
		std::string date = line.substr(0, commaPos);
		float value;
		try {
			value = std::stof(line.substr(commaPos + 1));
		} catch (const std::exception& e) {
			throw std::runtime_error("invalid value format");
		}
		auto ret = data_.insert(std::pair<std::string, float>(date, value));
		if (!ret.second)
			throw std::runtime_error("duplicate database entry found");
	}
}

bool BitcoinExchange::isValidFloat(const std::string& valueStr) {
	if (valueStr.empty()) {
		std::cerr << "Error: no amount provided\n";
		return false;
	}
	try {
		size_t pos;
		std::stof(valueStr, &pos);
		if (pos != valueStr.length()) {// confirm the entire string is consumed
			std::cerr << "Error: invalid format\n";
			return false;
		}
		return true;
	} catch (...) {
		std::cerr << "Error: invalid format\n";
		return false;
	}
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) {
	if (dateStr.substr(0,2) != "20")
		return false;
	struct tm tm{};
	if (!strptime(dateStr.c_str(), "%Y-%m-%d", &tm))
		return false;
	int year = tm.tm_year;
	int mon = tm.tm_mon;
	int day = tm.tm_mday;
	if (mktime(&tm) == -1)
		return false;
	return tm.tm_year == year && tm.tm_mon == mon && tm.tm_mday == day;
}

bool BitcoinExchange::isValidAmount(const float& amount) {
	if (amount < 0) {
		std::cerr << "Error: not a positive number.\n";
		return false;
	}
	if (amount > 1000) {
		std::cerr << "Error: too large a number.\n";
		return false;
	}
	return true;
}

void BitcoinExchange::validateInput(const std::string& inputFile) {
	std::ifstream input(inputFile);
	std::string line;
	std::getline(input, line); //validate header line
	if (line != "date | value")
		throw std::runtime_error("invalid input format");
	while (std::getline(input, line)) {
		if ((line.length() < 14) || (line.substr(10, 3) != " | ")) {  // minimum: "YYYY-MM-DD | "
			std::cerr << "Error: invalid input format\n";
			continue;
		}
		std::string date = line.substr(0, 10);  //get the first 10 chars of the line (date)
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << "\n";
			continue;
		}
		std::string valueStr = line.substr(13); // store values after date and divider |
		if (!isValidFloat(valueStr))
			continue;
		float coinAmount = std::stof(valueStr);
		if (!isValidAmount(coinAmount))
			continue;
		else {
			float value = getValue(date);
			if (value == -1) {
				std::cerr << "Error: no data available for date => " << date << "\n";
				continue;
			}
			float finalValue = value * coinAmount;
			if (std::isinf(value)) {
				std::cerr << "Error: Final value too large\n";
				continue;
			}
			else
				std::cout << date << " => " << coinAmount << " = " << finalValue << "\n";
		}
	}
}

float BitcoinExchange::getValue(const std::string& date) {
	auto it = data_.lower_bound(date);

	if (it != data_.end() && it->first == date)
		return it->second;
	if (it == data_.begin())
		return -1;
	--it;
	return it->second;
}