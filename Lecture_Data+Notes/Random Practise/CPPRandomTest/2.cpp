#include <iostream>

class MyClass
{
public:
    MyClass()
    {
        std::cout << "Constructor called" << std::endl;
    }

    ~MyClass()
    {
        std::cout << "Destructor called" << std::endl;
    }

    void show()
    {
        std::cout << "Static function called" << std::endl;
    }
};

int main()
{
    // Create a temporary object and call the static function
    MyClass().show(); // Temporary object created here

    return 0;
}
