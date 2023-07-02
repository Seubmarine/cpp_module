#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>

class Date
{
class WrongParsingFormat : public std::exception {virtual const char* what() const throw() {return "couldn't parse date, input must be incorrect";}};

private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
public:
	Date();
	~Date();

	Date(std::string formated_date);
	bool operator<(const Date& rhs) const;
	void ToPreviousDate();
	void Print() const;
};

class BitcoinExchange
{
class ExceptionDatabasePath : public std::exception {virtual const char* what() const throw() {return "Error: could not open data.csv.";}};
class ExceptionInputPath : public std::exception {virtual const char* what() const throw() {return "Error: could not open file.";}};
class ExceptionValue : public std::exception {virtual const char* what() const throw() {return "Error: could not parse value.";}};
class ExceptionDate : public std::exception {virtual const char* what() const throw() {return "Error: could not parse date.";}};
class ExceptionLine : public std::exception {virtual const char* what() const throw() {return "Error: bad input";}};
class ExceptionValueLow : public std::exception {virtual const char* what() const throw() {return "Error: not a positive number.";}};
class ExceptionValueHigh : public std::exception {virtual const char* what() const throw() {return "Error: too large a number.";}};

private:
	std::map<struct Date, float> date_database;
public:
	BitcoinExchange();
	~BitcoinExchange();
	void DoSomething();
	void RunFile(std::string filepath);
};

#endif