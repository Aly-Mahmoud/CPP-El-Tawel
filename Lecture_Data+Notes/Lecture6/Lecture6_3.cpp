#include <iostream>

using namespace std;

class A
{
    private:

    public:
        int a;
    protected:
};

class B : virtual public A
{
    private:

    public:
        int b;
    protected:
};

class C : virtual public A
{
    private:

    public:
        int c;
    protected:    
};

class D : public B, public C
{
    public:
        int d;
};

int  main()
{
    D obj;
    obj.a = 10;
}