/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaine <eelaine@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:26:18 by eelaine           #+#    #+#             */
/*   Updated: 2025/06/10 16:01:44 by eelaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static void	checkArgCount(int ac) {

	if (ac != 4) {
		std::cerr << "Error: Invalid number of arguments\n";
		exit (1);
	}
}

static void	checkEmptyString(const std::string& infile, const std::string& s1, const std::string& s2) {

	if (infile.empty() || s1.empty() || s2.empty()) {
		std::cerr << "Error: Empty argument(s)\n";
		exit (1);
	}
}

std::string copyFile(const std::string& infile) {

	std::ifstream file(infile, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Can't open file: " + infile);
    }
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	std::string contents;
	try {
		file.seekg(0, std::ios::end);
		std::streamsize size = file.tellg();
		file.seekg(0, std::ios::beg);
		contents.reserve(size);
		contents.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
		if (file.bad()) {
			throw std::runtime_error("Error reading file");
		}
	}
	catch (const std::exception& e) {
		throw std::runtime_error("File read error: " + std::string(e.what()));
	}
	return contents;
}

static void createReplace(const std::string& newFilename, const std::string& content) {

	std::ofstream file(newFilename);
	if (!file) {
		throw std::runtime_error("Error creating .replace file: " + newFilename);
	}
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	try {
		file << content;
	}
	catch (const std::exception& e) {
		throw std::runtime_error("Error while writing: " + std::string(e.what()));
	}
}

int	main(int ac, char **av) {

	checkArgCount(ac);
	checkEmptyString(av[1], av[2], av[3]);

	std::string copiedFile;
	std::string infile = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	try {
		copiedFile = copyFile(av[1]);
		if (copiedFile.empty()) {
			std::cerr << "Error: empty infile\n";
			return 1;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
	size_t pos = 0;
	while ((pos = copiedFile.find(s1, pos)) != copiedFile.npos) {
    	copiedFile.erase(pos, s1.length());
    	copiedFile.insert(pos, s2);
    	pos += s2.length();
	}
	createReplace(infile + ".replace", copiedFile);
	return 0;
}
