#include "includes/BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	std::map<int, std::string> inputFileMap = BitcoinExchange::openFile(argv[1]);
	std::map<int, std::string> dataFileMap = BitcoinExchange::openFile((char *)"data.csv");
	if (!inputFileMap.size() || !dataFileMap.size())
		std::cout << "The file is not found\n";
	else
		BitcoinExchange::runProgram(inputFileMap, dataFileMap);
	return 0;
}
