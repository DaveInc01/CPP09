#include "includes/BitcoinExchange.hpp"

// BitcoinExchange::BitcoinExchange( const BitcoinExchange & copy)
// {
// }

int BitcoinExchange::readFile(char *file)
{
    std::map<std::string, std::string> m;
    std::fstream my_file;
    my_file.open(file, std::ios::in);
    if (my_file)
    {
        
    }
    else
        std::cout << "Error: could not open file.\n";
}
