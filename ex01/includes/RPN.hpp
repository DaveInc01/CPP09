#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
class RPN{
public:
	RPN(){};
	RPN( const RPN &);
	RPN & operator=(const RPN &);
	~RPN(){};
	static std::stack<int> st;
};

int do_operations(char *argv);
int pars_argv(char *str);

#endif
