#pragma once

#include<iostream>
#include<cmath>
#include<stack>
#include<climits>

class RPN
{
    public:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &rhs);
        ~RPN();
};

