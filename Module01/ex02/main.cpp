
#include<iostream>
int main()
{
   std::string str = "HI THIS IS BRAIN";
   std::string *stringPTR = &str;
   std::string &stringREF = str;

   std::cout << "String = " << str << std::endl;
   std::cout << "Adress of String = " << &str << std::endl;

    std::cout << "StringPTR = " << *stringPTR << std::endl;
    std::cout << "Adress of StringPTR = " << &stringPTR << std::endl;

    std::cout << "StringREF = " << stringREF << std::endl;
    std::cout << "Adress of StringREF = " << &stringREF << std::endl;
}