//
// Created by Lowell Zima on 3/18/23.
//

#include<iostream>
#include<cmath>
#include<stack>
#include<climits>

int scanNum(char ch){
	int value;
	value = ch;
	return int(value - '0');
}

int isOperand(char c) {
	if(c >= '0' && c <= '9')
		return (1);
	return (-1);
}

int isOperator(char op) {
	if (op == '+' || op == '-' || op == '*' || op == '/') {
		return (1);
	}
	return (-1);
}

int operation(int a , int b, char op)
{
	if (op == '+')
		return (b + a);
	if (op == '-')
		return (b - a);
	if (op == '*')
		return (b * a);
	if (op == '/')
		return (b / a);
	return (INT_MIN);
}

int bad_input(char *s)
{
	int t = 0;
	int digit = 0;
	int op = 0;

	for (size_t i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' '){
			t = 0;
			continue;
		}
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			op++;
			continue;
		}
		if (std::isdigit(s[i])) {
			t++;
			digit++;
			if (t == 2) {
				return (1);
			}
		}
		else
			return (1);
	}
	if ((digit - 1) != op) {
		return (1);
	}
	return (0);
}

int calculate(std::string input){
	int a, b;
	std::stack<int> stk;
	std::string::iterator it;

	for(it = input.begin(); it != input.end(); it++)
	{
		if (*it == ' '){
			continue;
		}
		if(isOperator(*it) != -1 ){
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(operation(a, b, *it));
		}
		else if(isOperand(*it) > 0){
			stk.push(scanNum(*it));
		}
	}
	return stk.top();
}

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: one arg to rule them all 👁 and in the darkness bind them" << std::endl;
		return (1);
	}
	if (bad_input(av[1])) {
		std::cout << "Error" << std::endl;
		return (0);
	}
	int result = calculate(av[1]);
	std::cout << result << std::endl;
}
