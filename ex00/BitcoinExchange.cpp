#include "includes/BitcoinExchange.hpp"

std::string BitcoinExchange::date = "";
std::string BitcoinExchange::value = "";
std::string BitcoinExchange::year = "";
std::string BitcoinExchange::month = "";
std::string BitcoinExchange::day = "";
std::map<std::string, std::string> BitcoinExchange::data;

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
	std::map<std::string, std::string>::iterator it = BitcoinExchange::data.find(BitcoinExchange::date);
	if(it != BitcoinExchange::data.end())
	{

		std::cout << "found value" << it->second;
	}
	else {
		std::cout << "nothing is found\n";
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
	(void)dataFile;
}
