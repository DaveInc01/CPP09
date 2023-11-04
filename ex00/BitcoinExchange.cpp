#include "includes/BitcoinExchange.hpp"

std::string BitcoinExchange::date;
std::string BitcoinExchange::date_2;
std::string BitcoinExchange::value;
std::map<std::string, std::string> BitcoinExchange::data;

BitcoinExchange::BitcoinExchange( const BitcoinExchange &copy)
{
	this->data = copy.data;
	this->date = copy.date;
	this->date_2 = copy.date_2;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	this->data = obj.data;
	this->date = obj.date;
	this->date_2 = obj.date_2;
	return *this;
}

std::map<int, std::string> BitcoinExchange::openFile(char *filename){
	std::fstream my_file;
	my_file.open(filename, std::ios::in);
	char c;
	std::string line;
	std::map<int, std::string> myMap;
	int i = 0;
	if (my_file)
	{
		while (my_file >> std::noskipws >> c)
		{
			line.push_back(c);
			if(c == '\n' || c == '\0')
			{
				myMap[i] = line;
				line.clear();
				i++;
			}
		}
		if (line.length() > 1)
			myMap[i] = line;
	}
	return (myMap);
}

void BitcoinExchange::calcLine(){
	std::map<std::string, std::string>::iterator found_it = BitcoinExchange::data.find(BitcoinExchange::date);
	if(found_it != BitcoinExchange::data.end())
	{
		std::stringstream ss1(found_it->second);
		long double found_value;
		ss1 >> found_value;
		std::stringstream ss2(BitcoinExchange::value);
		long double input_value;
		ss2 >> input_value;
		long double sum = input_value * found_value;
		std::cout << BitcoinExchange::date_2 << " => " << BitcoinExchange::value << " = " << sum << std::endl;
	}
	else {
		BitcoinExchange::date = date_decrement(BitcoinExchange::date);
		calcLine();
	}
}

void BitcoinExchange::runProgram(std::map<int, std::string> inputFile, std::map<int, std::string> dataFile){
	unsigned long int i = 0;
	create_data_map(dataFile);
	if (inputFile[0].find("date | value") != std::string::npos)
		i++;
	while (i < inputFile.size())
	{
		if (checkLine(inputFile[i]) == 0)
			calcLine();
		i++;
	}
}
