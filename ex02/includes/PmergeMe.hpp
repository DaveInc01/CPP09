#ifndef PM_HPP
#define PM_HPP

#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <ctime>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>


class PmergeMe{
public:
	PmergeMe(){};
	PmergeMe( const PmergeMe &);
	PmergeMe & operator=(const PmergeMe &);
	~PmergeMe(){};
	static std::vector<unsigned long> vect;
	static std::list<unsigned long> lst;
};

int		check_arg(char* arg);
void	sort_vect(std::vector<unsigned long> &vect);
void 	sort_list(std::list<unsigned long> &lst);

#endif
