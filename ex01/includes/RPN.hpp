#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

class RPN{
public:
	RPN(){};
	RPN( const RPN &);
	RPN & operator=(const RPN &);
	~RPN(){};
};

int pars_argv(char *str);

#endif
