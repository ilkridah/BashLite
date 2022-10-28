#include <iostream>

int main()
{
    class Foo
    {
        public:
            Foo (int data)
            {
                this->data = data;
            }
            ~Foo(){};
        Foo& operator=(const Foo& rhs)
        {
            data = rhs.data;
            return *this;
        }
        int data;
    }
    
}
