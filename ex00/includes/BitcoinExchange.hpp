#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream> 


class BitcoinExchange{
public:
	BitcoinExchange(){};
	BitcoinExchange( const BitcoinExchange &);
	BitcoinExchange & operator=(const BitcoinExchange &);
	~BitcoinExchange(){};
	static std::map<int, std::string> openFile(char *);
	static void runProgram(std::map<int, std::string>, std::map<int, std::string>);
	static void calcLine(std::map<int, std::string>, std::map<int, std::string>);
};

int checkLine (std::string line);

#endif
