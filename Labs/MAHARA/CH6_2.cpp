#include <iostream>

using namespace std;

class Base
{
    private:
        int a;

    protected:
        int b;

    public:
        void setA(int x) 
        {
            a=x;
        }

        void setB(int y) 
        {
            b=y;
        }

        int getA ()
        {
            return a;
        }

        int getB ()
        {
            return b;
        }

        int getProduct()
        {
            cout << "a*b : " << a*b << endl;
            return a*b;
        }
};

class Derived : public Base
{
    private:
        int c;

    public:
        int getProduct()
        {
            cout << "a*b*c" << getA()*b*c << endl;
            return getA()*b*c;
        }

        void setC(int C)
        {
            c = C;
        }

        int getC()
        {
            return c;
        }
};

class Derived_2 : public Derived
{
    private:
        int d;

    public:
        void setD(int D)
        {
            d=D;
        }

        int getProduct()
        {
            cout << "a*b*c*d" << Derived::getProduct()*d << endl;
            return Derived::getProduct()*d;
            //return getA()*b*getC()*d;
        }
};

void someFunction (Base& t)
{
    t.getProduct();
}

int main()
{
    Base b1;
    b1.setA(1);
    b1.setB(2);
    Derived d1;
    d1.setC(3);
    Derived_2 d2;
    d2.setD(4);
    someFunction(d2);

    return 0;
}