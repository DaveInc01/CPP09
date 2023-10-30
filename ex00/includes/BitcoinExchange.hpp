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
	static void calcLine();
	static std::map<std::string, std::string> data;
	static std::string date;
	static std::string value;
	static std::string year;
	static std::string month;
	static std::string day;
};

int checkLine (std::string line);
std::string date_decrement(const std::string&);
void create_data_map( std::map<int, std::string>);

#endif
