#include <iostream>
#include "1.hpp"

MyClass::MyClass() : m_value (0)
{
    std::cout<<"The default constructor has been called"<<std::endl;
}

MyClass::MyClass (int value) : m_value(value)
{
    std::cout<<"The Parametrized constructor has been called"<<std::endl;
}

void MyClass::display()
{
    std::cout<<"The value of the object is : "<< m_value <<std::endl;
}

int main ()
{
    MyClass Aly = 3;
    MyClass EL3w(10);

    Aly.display();
    EL3w.display();

    return 0;
}