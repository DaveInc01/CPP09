#include "includes/RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2)
	{
		std::cout << "Too many arguments!\n";
		return 0;
	}
	if (pars_argv(argv[1]) == -1)
	{
		std::cout << "Error\n";
		return 0;
	}
	if (do_operations(argv[1]) == 0)
	{
		std::cout << RPN::st.top() << std::endl;
	}
	return 0;
}
