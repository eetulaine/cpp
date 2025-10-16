#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>

class BitcoinExchange {

	private:
		std::map<std::string, float> data_;
		void validateDatabase();
		void validateInput(const std::string& input);
		float getValue(const std::string& date);
		static bool isValidFloat(const std::string& valueStr);
		static bool isValidDate(const std::string& dateStr);
		static bool isValidAmount(const float& amount);
		
	public:
		BitcoinExchange() = delete;
		BitcoinExchange(const std::string& input);
		BitcoinExchange(const BitcoinExchange& other) = delete;
		BitcoinExchange& operator=(const BitcoinExchange& other) = delete;
		~BitcoinExchange();
};