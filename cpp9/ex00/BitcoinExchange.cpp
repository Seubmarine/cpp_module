#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define DATABASE_PATH "data.csv"


bool Date::operator<(const Date& rhs) const {
	if (year < rhs.year)
        return true;
    else if (year == rhs.year && month < rhs.month)
        return true;
    else if (year == rhs.year && month == rhs.month && day < rhs.day)
        return true;
    else
        return false;
}

Date::Date() : year(0), month(0), day(0) {}
Date::~Date() {}

void Date::ToPreviousDate() {
	if (day == 1) {
		if (month == 1) {
			if (year == 0)
				throw std::exception();
			year--;
			month = 12;
		}
		else
			month--;
		unsigned int final_day_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		day = final_day_of_month[month - 1];
	}
	else
		day--;
}

void Date::Print() const {
	std::cout << this->year << '-' << this->month << '-' << this->day;
}


Date::Date(std::string s)
{
	std::string year_string(s.begin(), s.begin() + s.find("-")); // take the value token
	s.erase(s.begin(), s.begin() + s.find("-") + 1);
	std::string month_string(s.begin(), s.begin() + s.find("-")); // take the value token
	s.erase(s.begin(), s.begin() + s.find("-") + 1);
	std::string day_string(s.begin(), s.end()); // take the value token

	std::stringstream ss_year(year_string);
	if (!(ss_year >> this->year))
		throw std::exception();
	std::stringstream ss_month(month_string);
	if (!(ss_month >> this->month))
		throw std::exception();
	std::stringstream ss_day(day_string);
	if (!(ss_day >> this->day))
		throw std::exception();
	
	// std::cout << date.year << " m:" << date.month << " d:" << date.day << std::endl;
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream database_file(DATABASE_PATH);
	if (!database_file)
		throw BitcoinExchange::ExceptionDatabasePath();
	std::string line;
	std::getline(database_file, line);
	while (std::getline(database_file, line)) {
		
		//Parsing the price value
		std::string float_string(line.begin() + line.find(",") + 1 , line.end()); // take the value token
		float value = 0.0f;
		std::stringstream ss(float_string);
		if (!(ss >> value))
			throw BitcoinExchange::ExceptionValue();
		line.erase(line.begin() + line.find(",") , line.end());
		
		//Parsing the date
		struct Date date(line);
		date_database.insert(std::pair<struct Date, float>(date, value));
	}
	
	database_file.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::DoSomething()
{
    // std::cout << "size: " << this->date_database.size() << std::endl;

	// // Get an iterator pointing to the first element in the map
  	// std::map<Date, float>::iterator it = this->date_database.begin();
 
	// // Iterate through the map and print the elements
	// while (it != this->date_database.end())
	// {
	// 	std::cout << "Key: ";
	// 	it->first.Print();
	// 	std::cout << ", Value: " << it->second << std::endl;
	// 	++it;
	// }
	// std::cout << std::endl;
}

void BitcoinExchange::RunFile(std::string filepath) {
	std::ifstream database_file(filepath.c_str());
	if (!database_file)
		throw BitcoinExchange::ExceptionInputPath();
	std::string line;
	std::getline(database_file, line);
	while (std::getline(database_file, line)) {
		
		try
		{
			//Parsing the price value
			if (line.find('|') == std::string::npos)
				throw BitcoinExchange::ExceptionLine(); 
			std::string float_string(line.begin() + line.find("|") + 1 , line.end()); // take the value token
			float value = 0.0f;
			std::stringstream ss(float_string);
			if (!(ss >> value))
				throw BitcoinExchange::ExceptionValue();
			line.erase(line.begin() + line.find("|") , line.end());
			
			//Parsing the date
			struct Date date(line);
			if (value < 0)
				throw BitcoinExchange::ExceptionValueLow();
			else if (value > 1000)
				throw BitcoinExchange::ExceptionValueHigh();

			while (true) {
				std::map<Date, float>::iterator search = date_database.find(date);
				if (search != date_database.end()) {
					std::cout << line << " => " << ((*search).second * value) << std::endl;
					break;
				}
				date.ToPreviousDate();
			}
		}
		catch(const BitcoinExchange::ExceptionLine& e)
		{
			std::cerr << ((const std::exception&)e).what() << " => " << line << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	database_file.close();
}
