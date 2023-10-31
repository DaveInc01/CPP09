#include "includes/BitcoinExchange.hpp"

std::string date_decrement(const std::string& date_str) {
    // Parse the input date string
    int year, month, day;
    sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day);

    // Decrement the day
    if (day > 1) {
        day--;
    } else {
        // If day is 1, we need to handle the case for previous month and leap years
        if (month > 1) {
            month--;
            switch (month) {
                case 4:
                case 6:
                case 9:
                case 11:
                    day = 30;
                    break;
                case 2:
                    // Check for leap year
                    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                        day = 29;
                    } else {
                        day = 28;
                    }
                    break;
                default:
                    day = 31;
                    break;
            }
        } else {
            // If month is 1 (January), go to previous year and set month to December
            year--;
            month = 12;
            day = 31;
        }
    }

    // Format the result string
    char result[11];
    snprintf(result, sizeof(result), "%04d-%02d-%02d", year, month, day);

    return std::string(result);
}

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

inline std::string& rtrim(std::string& s)
{
	const char* ws = " \t\n\r\f\v";
    s.erase(s.find_last_not_of(ws) + 1);
    return s;
}

inline std::string& ltrim(std::string& s)
{
	const char* ws = " \t\n\r\f\v";
    s.erase(0, s.find_first_not_of(ws));
    return s;
}

int check_date(std::string date)
{
	
	int year_end = date.find('-');
	std::string year = date.substr(0, year_end);
	if (year.length() != 4)
		return -1;
	int month_end = date.find('-', ++year_end);
	std::string month = date.substr(year_end, (month_end - year_end));
	if (month.length() != 2)
		return -1;
	std::string day = date.substr(month_end + 1, ((date.length() - 1) - month_end));
	if (day.length() != 2)
		return -1;
	if (date == "2009-01-01")
		return -1;
	return (check_date_parts(year, month, day));
}

int check_value(std::string &value)
{
	int i = 0;
	if ((value.length() > 9) && (value > "2147483647")){
		std::cout << "Error: too large a number." << std::endl;
		return -1;
	}
	while (i < (int)value.size())
	{
		if (value[i] == '-')
		{
			std::cout << "Error: not a positive number." << std::endl;
			return -1;
		}
		i++;
	}
	return 0;
}

int checkLine (std::string line) {
	std::string date;
	std::string value;
	line = ltrim(line);
	line = rtrim(line);
	int date_end = line.find('|');
	if ((check_symbols(line) == -1) || (date_end == -1))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return -1;
	}
	date = line.substr(0, date_end - 1);
	value = line.substr((date_end + 2), line.length() - (date_end + 2));
	if (check_date(date) == -1)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return -1;
	}
	if (check_value(value) == -1)
		return -1;
	BitcoinExchange::date = date;
	BitcoinExchange::date_2 = date;
	BitcoinExchange::value = value;
	return 0;
}

void create_data_map( std::map<int, std::string> data_file)
{
	int i = 0;
	int date_end;;
	std::string date;
	std::string value;
	while(i < (int)data_file.size())
	{
		date_end = data_file[i].find(',');
		date = data_file[i].substr(0, date_end);
		value = data_file[i].substr(date_end + 1, (data_file[i].length() - 1) - (date_end + 1));
		BitcoinExchange::data.insert(std::pair<std::string, std::string>(date, value));
		i++;
	}
}
