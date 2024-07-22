/*a Code to test ambiguty

    no ambiguty against expectations

*/
#include <iostream>

using namespace std;


class A
{
    private:

    public:
        int a;
    protected:
};

class B : public A
{
    private:

    public:
        int b;
    protected:
};

class C : public B
{
    private:

    public:
        int a;
    protected:    
};

int  main()
{
    C z;

    /*Wrong code that result in amguity error*/
        z.a=10;                                  //no error occures for some reason
    /*---------------------------------------*/

    /*Right code that specifies which variable to be accessed*/
        z.A::a=10;
    /*-------------------------------------------------------*/    
}