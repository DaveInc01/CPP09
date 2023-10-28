#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <fstream>
#include <iostream>
#include <map>

class BitcoinExchange{
public:
	BitcoinExchange(){};
	BitcoinExchange( const BitcoinExchange &);
	BitcoinExchange & operator=(const BitcoinExchange &);
	~BitcoinExchange(){};
	static int readFile(char *);
};

#endif
