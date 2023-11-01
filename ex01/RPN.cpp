#include "includes/RPN.hpp"

std::stack<int> RPN::st;

RPN::RPN( const RPN &copy)
{
	this->st = copy.st;
}

RPN & RPN::operator=(const RPN &obj)
{
	this->st = obj.st;
	return *this;
}

int calc(char sign)
{
    int a;
    int b;
    int res = 0;

    if(!RPN::st.empty())
    {
        b = RPN::st.top();
        RPN::st.pop();
    }
    else
        return -1;
    if (!RPN::st.empty())
    {
        a = RPN::st.top();
        RPN::st.pop();
    }
    else
        return -1;
    switch(sign)
    {
        case '-':
        {
            res = a - b;
            break;
        }
        case '+':
        {
            res = a + b;
            break;
        }
        case '/':
        {
            res = a / b;
            break;
        }
        case '*':
        {
            res = a * b;
            break;
        }
    }
    RPN::st.push(res);
    return 0;
}

int do_operations(char *argv)
{
	int i  = 0; 
	while (argv[i])
	{
		if (argv[i] == ' ')
			i++;
		if (argv[i] >= '0' && argv[i] <= '9')
            RPN::st.push(argv[i] - '0');
        else {
            if (calc(argv[i]) == -1)
            {
                std::cout << "Error\n";
                return -1;
            }
        }
        i++;
	}
    return 0;
}