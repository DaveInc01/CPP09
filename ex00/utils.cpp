#include "includes/BitcoinExchange.hpp"

int check_symbols(std::string line){
	unsigned int i = 0;
	while (i < line.length())
	{
		if ((line[i] >= '0' && line[i] <= '9')
		|| (line[i] == '-') || (line[i] == '|')
		|| (line[i] == ' ') || (line[i] == '\n')
		|| (line[i] == '.') || (line[i] == '\t'))
			i++;
		else
			return -1;
	}
	return 0;
}

int checkLine (std::string line) {
	if (check_symbols(line) == -1)
		std::cout << "Error: bad input => " << line << std::endl;
	
	return 0;
}
