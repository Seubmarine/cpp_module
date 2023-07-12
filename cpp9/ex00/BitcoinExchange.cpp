#include "BitcoinExchange.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#define DATABASE_PATH "data.csv"

bool Date::operator<(const Date &rhs) const {
	if (year < rhs.year)
		return true;
	else if (year == rhs.year && month < rhs.month)
		return true;
	else if (year == rhs.year && month == rhs.month && day < rhs.day)
		return true;
	else
		return false;
}

Date::Date() :
		year(0), month(0), day(0) {}
Date::~Date() {}
Date::Date(const Date &date) {
	*this = date;
}

Date &Date::operator=(const Date &date) {
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
	return *this;
}

void Date::ToPreviousDate() {
	if (day == 1) {
		if (month == 1) {
			if (year == 0)
				throw Date::ExceptionYearIsTooYoung();
			year--;
			month = 12;
		} else
			month--;
		unsigned int final_day_of_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		day = final_day_of_month[month - 1];
	} else
		day--;
}

void Date::VerifyDate() {
	unsigned int final_day_of_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (this->month > 12 || this->month == 0)
		throw Date::ExceptionInvalidDate();
	else if (this->day == 0 || this->day > final_day_of_month[this->month - 1])
		throw Date::ExceptionInvalidDate();
}

void Date::Print() const {
	std::cout << this->year << '-' << this->month << '-' << this->day;
}

Date::Date(std::string s) {
	std::string year_string(s.begin(), s.begin() + s.find("-")); // take the value token
	s.erase(s.begin(), s.begin() + s.find("-") + 1);
	std::string month_string(s.begin(), s.begin() + s.find("-")); // take the value token
	s.erase(s.begin(), s.begin() + s.find("-") + 1);
	std::string day_string(s.begin(), s.end()); // take the value token

	std::stringstream ss_year(year_string);
	if (!(ss_year >> this->year))
		throw Date::WrongParsingFormat();
	std::stringstream ss_month(month_string);
	if (!(ss_month >> this->month))
		throw Date::WrongParsingFormat();
	std::stringstream ss_day(day_string);
	if (!(ss_day >> this->day))
		throw Date::WrongParsingFormat();

	// std::cout << date.year << " m:" << date.month << " d:" << date.day << std::endl;
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream database_file(DATABASE_PATH);
	if (!database_file)
		throw BitcoinExchange::ExceptionDatabasePath();
	std::string line;
	std::getline(database_file, line);
	while (std::getline(database_file, line)) {
		//Parsing the price value
		std::string float_string(line.begin() + line.find(",") + 1, line.end()); // take the value token
		float value = 0.0f;
		std::stringstream ss(float_string);
		if (!(ss >> value))
			throw BitcoinExchange::ExceptionValue();
		line.erase(line.begin() + line.find(","), line.end());

		//Parsing the date
		class Date date(line);
		date_database.insert(std::pair<class Date, float>(date, value));
	}

	database_file.close();
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc_exchange) {
	*this = btc_exchange;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc_exchange) {
	this->date_database = btc_exchange.date_database;
	return *this;
}

void BitcoinExchange::RunFile(std::string filepath) {
	std::ifstream database_file(filepath.c_str());
	if (!database_file)
		throw BitcoinExchange::ExceptionInputPath();
	std::string line;
	std::getline(database_file, line);
	if (line != "date | value")
		throw BitcoinExchange::ExceptionLine();
	while (std::getline(database_file, line)) {
		try {
			//Parsing the price value
			if (line.find('|') == std::string::npos)
				throw BitcoinExchange::ExceptionLine();
			std::string float_string(line.begin() + line.find("|") + 1, line.end()); // take the value token
			float value = 0.0f;
			std::stringstream ss(float_string);
			if (!(ss >> value))
				throw BitcoinExchange::ExceptionValue();
			line.erase(line.begin() + line.find("|"), line.end());

			//Parsing the date
			class Date date(line);
			if (value < 0)
				throw BitcoinExchange::ExceptionValueLow();
			else if (value > 1000)
				throw BitcoinExchange::ExceptionValueHigh();
			date.VerifyDate();

			std::map<Date, float>::iterator search = date_database.upper_bound(date);
			if (search == date_database.begin())
				throw Date::ExceptionYearIsTooYoung();

			std::cout << line << "=> " << value << " = ";
			std::cout << ((*(--search)).second * value) << std::endl;

		} catch (const BitcoinExchange::ExceptionLine &e) {
			std::cerr << ((const std::exception &)e).what() << " => " << line << std::endl;
		} catch (const Date::ExceptionInvalidDate &e) {
			std::cerr << ((const std::exception &)e).what() << " => " << line << std::endl;
		} catch (const Date::ExceptionYearIsTooYoung &e) {
			std::cerr << ((const std::exception &)e).what() << " => " << line << std::endl;
		} catch (const Date::WrongParsingFormat &e) {
			std::cerr << ((const std::exception &)e).what() << " => " << line << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
	}
	database_file.close();
}
