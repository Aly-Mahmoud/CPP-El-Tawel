/*
    A code to redefine base class method
*/

#include <iostream>

using namespace std;

class Base 
{
    public: 
        void print()
        {
            cout<< "Base class say what " << endl;
        }
};

class Derived : public Base
{
    public:
        void print()
        {
            cout << "Derived class say what " << endl;
        }
};

int main ()
{
    Base a;
    Derived b;

    a.print();
    b.print();

    /*A valid operation*/
        Base* ptr_base = new Derived;   // derived has the entire data of base and some more  // not working why?
                                        // so when pointing with it to the base there will be no data that dervied don't already have 
    /*as Derived is a Base*/

    /*a non valid operation*/
    //   Derived* ptr_derived = new Base;    // base has his data & his data only 
                                           // so when pointing with it to the derived there will be data that the base class does not have 
    /*as base is not a dervied*/

    /*Which print will be used*/
        ptr_base->print();              // the one that will avtually be used is the base print 
                                        // as the pointer is from base type which will allow only the use of the methods of  it's type
                                        // it's like when you cast 
    /*the base or the derived*/

    /*Dynamic binding*/

    /*---------------*/
}