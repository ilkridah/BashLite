#include<iostream>
#include<cmath>
#include<stack>
#include<climits>

int is_operator(char op)
{
    if(op == '+' || op == '-' || op == '*' || op == '/')
        return(1);
    return (-1);
}

int ft_operators(int x, int y, char op)
{
    if (op == '+')
        return(y + x);
    if (op == '-')
        return(y - x);
    if (op == '*')
        return(y * x);
    if (op == '/'){
        if(x == 0)
        {
            std::cout << "Error 120" << std::endl;
            exit(1);
        }
        return(y / x);
    }
    return (0);
}


int main(int ac, char **av)
{
    int x ;
    int y ;
    std::string in;
    std::stack<int> st;
    std::string::iterator iter;
    int res;
    
    if(av[1])
        in  = av[1];
    if(ac == 1 || in.empty() || !in.find_first_not_of("0123456789*/+-"))
    {
        std::cout << "Error" << std::endl;
        return (0);
    }
      
    for(iter = in.begin(); iter != in.end(); iter++)
    {
        if(*iter  == ' ')
            continue;
        if(is_operator(*iter) != -1)
        {
            if(st.size() < 2)
            {
                std::cout << "Error 122" << std::endl;
                exit(1);
            }
            x  = st.top();
            st.pop();
            y = st.top();             
            st.pop();
            st.push(ft_operators(x, y, *iter));
        }
        else if(isdigit(*iter))
                st.push(*iter - '0');
    }
    if(st.size() > 1)
    {
        std::cout << "Error 124" << std::endl;
        exit(1);
    }
    res = st.top();
    std::cout << res << std::endl;
    return (0);
}