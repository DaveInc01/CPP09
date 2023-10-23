#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <vector>


class BitcoinExchange{
public:
	BitcoinExchange();
	BitcoinExchange( const BitcoinExchange &);
	BitcoinExchange & operator=(const BitcoinExchange &);
	~BitcoinExchange(){};
};

#endif
