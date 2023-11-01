#include "includes/RPN.hpp"

int pars_argv(char *str){
	int i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if ((str[i + 1]) && str[i + 1] == ' ')
				i++;
			else
				return -1;
		}
		else if(str[i] == ' ' && str[i + 1] != ' ')
			i++;
		else if((str[i] == '/') || (str[i] == '*')
			||  (str[i] == '+')  || (str[i] == '-'))
		{
			if (str[i + 1] == '\0' || (str[i + 1] == ' '))
				i++;
			else
				return -1;
		}
		else
			return -1;
	}
	return 0;
}
