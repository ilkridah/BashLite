#include <iostream>

class xxx
{
    public:
        int a = 1008;
        int b = 2905;
  
    xxx operator + (xxx &uu)
    {
        xxx temp;
        temp.a = a + uu.b;
        return temp;
    }
    bool operator == (xxx uu)
    {
        if (a == uu.a && b == uu.b)
            return true;
        else
            return false;
    }
    bool operator < (xxx uu)
    {
        if (a < uu.a && b < uu.b)
            return true;
        else
            return false;
    }

};

    int main()
    {
        xxx obj1,obj2,obj3;

        obj3 = obj1 + obj2;
        std::cout << obj3.b << std::endl;
        if( obj1 < obj2)
        {
            std::cout << "obj1 is less than obj2" << std::endl;
        }
        else
        {
            std::cout << "obj1 is greater than obj2" << std::endl;
        }
        if(obj1 == obj2)
        {
            std::cout << "Equal" << std::endl;
        }
        else
        {
            std::cout << "Not Equal" << std::endl;
        }
    }