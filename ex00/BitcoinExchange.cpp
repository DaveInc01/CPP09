#include "includes/BitcoinExchange.hpp"

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
	}
	return (myMap);
}

void BitcoinExchange::calcLine(std::map<int, std::string>, std::map<int, std::string>){}

void BitcoinExchange::runProgram(std::map<int, std::string> inputFile, std::map<int, std::string> dataFile){
	int i = 0;
	if (inputFile[0].find("date | value") != std::string::npos)
		i++;
	while (inputFile[i])
	{
		if (checkLine(inputFile[i]) == 0)
			calcLine(inputFile[i], dataFile);
		i++;
	}
}
