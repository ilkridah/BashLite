
#include <iostream>

class demo_op
{
    private:
        int _value;
        int bits = 8;
    public:
        void input()
        {
            std::cout << "enter value: ";
            std::cin >> _value;
        }
        void operator +(int x)
        {
            _value = _value + x;
        }

        void operator -(int x)
        {
            _value = _value - x;
        }
        void toInt(float value)
        {
            this->_value = _value >> bits;
            std::cout << "value: " << _value << std::endl;
        }
        void display()
        {
            std::cout << "value is: " << _value << "\n";
        }
};

int main()
{
    demo_op obj;
    float x;

    std::cin >> x;
    obj.toInt(x);
    // obj.display();
    return 0;
}
