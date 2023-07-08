#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>

class Date
{

private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
public:
	class WrongParsingFormat : public std::exception {virtual const char* what() const throw() {return "Error: could not parse date";}};
	class ExceptionInvalidDate : public std::exception {virtual const char* what() const throw() {return "Error: date is not a valid date";}};
	class ExceptionYearReachZero : public std::exception {virtual const char* what() const throw() {return "Error: date is younger than first date in database";}};

	Date();
	~Date();
	Date(const Date &date);
	Date &operator=(const Date &date);

	Date(std::string formated_date);
	bool operator<(const Date& rhs) const;
	void ToPreviousDate();
	void Print() const;
	void VerifyDate();
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
	std::map<class Date, float> date_database;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &btc_exchange);
	BitcoinExchange &operator=(const BitcoinExchange &btc_exchange);

	void RunFile(std::string filepath);
};

#endif