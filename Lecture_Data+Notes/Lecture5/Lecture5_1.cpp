#include <iostream>

using namespace std;

class Base
{
    private:
        int x;
    public:
        int y;
    protected:
        int z;
};

class Pub_Derived : public Base
{
    private:
        int a;
    public:
        void display()
        {
            cout << "Value of x: " << x << endl;
            cout << "Value of y: " << y <<endl;
            cout << "Value of z: " << z <<endl;
        }
    protected:
};

class Pri_Derived : private Base
{
    private:
        int a;
    public:
        void display()
        {
            cout << "Value of x: " << x << endl;
            cout << "Value of y: " << y <<endl;
            cout << "Value of z: " << z <<endl;
        }
    protected:
};

class Pro_Derived : protected Base
{
    private:
        int a;
    public:
        void display()
        {
            cout << "Value of x: " << x << endl;
            cout << "Value of y: " << y <<endl;
            cout << "Value of z: " << z <<endl;
        }
    protected:
};


int main ()
{
    Base B1;
    B1.x = 10;
    B1.y = 20;
    B1.z = 30;

    Pub_Derived D1;
    D1.x = 10;
    D1.y = 20;
    D1.z = 30;
    D1.display();

    Pri_Derived D2;
    D2.x = 10;
    D2.y = 20;
    D2.z = 30;
    D2.display();

    Pro_Derived D3;
    D3.x = 10;
    D3.y = 20;
    D3.z = 30;
    D3.display();

    return 0;
}