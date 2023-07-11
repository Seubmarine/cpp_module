#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Error: couldn't open file." << std::endl;
        return 1;
    }
	try
	{
    	BitcoinExchange btc_exchange;
    	btc_exchange.RunFile(std::string(argv[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}
