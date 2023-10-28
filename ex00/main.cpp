#include "includes/BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
	}
	else
		BitcoinExchange::openFile(argv[1])
	}
}
