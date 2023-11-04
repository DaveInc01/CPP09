#include "includes/PmergeMe.hpp"

void print_stat(float vect_time, float list_time, char **argv, int argc)
{
	--argc;
	int i = 1;
	std::cout << "Before:\t";
	while (argv[i])
		std::cout << argv[i++] << " ";
	std::cout << "\nAfter:\t";
	std::vector<unsigned long>::iterator it = PmergeMe::vect.begin();
	while (it != PmergeMe::vect.end())
		std::cout << *it++ << " ";
	std::cout << "\nTime to process a range of " << argc <<" elements with std::vector : " << vect_time << " us\n";
	std::cout << "Time to process a range of " << argc <<" elements with std::list   : " << list_time << " us\n";
}
int main(int argc, char **argv)
{
	int i = 1;
	if (argc < 2){
		std::cout << "Type the numbers for sorting" << std::endl;
		return 0;
	}
	// if (argv[i][])
	while(argv[i])
	{
		if (check_arg(argv[i]) == -1)
		{
			std::cout << "Invalid arguments!" << std::endl;
			return 0;
		}
		i++;
	}
	struct timeval start, end;
	gettimeofday(&start, 0);
	i = 1;
	while (argv[i])
		PmergeMe::vect.push_back((unsigned long)atol(argv[i++]));
	sort_vect(PmergeMe::vect);
	gettimeofday(&end, 0);
	float vect_time = end.tv_usec - start.tv_usec;
	gettimeofday(&start, 0);
	i = 1;
	while (argv[i])
		PmergeMe::lst.push_back((unsigned long)atol(argv[i++]));
	sort_list(PmergeMe::lst);
	gettimeofday(&end, 0);
	float list_time = end.tv_usec - start.tv_usec;
	print_stat(vect_time, list_time, argv, argc);
	return 0;
}
