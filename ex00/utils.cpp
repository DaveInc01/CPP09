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

int check_date_parts(std::string year, std::string month, std::string day)
{
	if ((year >= "2009" && year <= "2023")
	&&  (month >= "01" && month <= "12")
	&&  (day >= "01" && day <= "31"))
		return 0;
	return -1;
}

int check_date(std::string date)
{
	int year_end = date.find('-');
	std::string year = date.substr(0, year_end);
	int month_end = date.find('-', ++year_end);
	std::string month = date.substr(year_end, (month_end - year_end));
	std::string day = date.substr(month_end + 1, ((date.length() - 2) - month_end));
	return (check_date_parts(year, month, day));
	// std::cout << "year - " << year 
	// << "\nmonth - " << month << "\nday - " << day <<"|" << std::endl;
}

int checkLine (std::string line) {
	std::string date;
	int date_end = line.find('|');
	if ((check_symbols(line) == -1) || (date_end == -1))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return -1;
	}
	date = line.substr(0, date_end);
	
	// std::cout << "date -" << date <<  std::endl;
	if (check_date(date) == -1)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return -1;
	}
	return 0;
}
