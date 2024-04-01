#include <iostream>

using namespace std;

class Base 
{
    private:
        int x;
    public:
        Base() : x{10}
        {   
            cout << "Base:Base()" << endl;   
        }    

        Base (int x) : x{x}
        {
            cout << "Base::Base(int)" << endl;
        }

        Base(const Base &source)
        {
            this->x = source.x;
        }

        void setX(int val)
        {
            x= val;
        }

        int getX(void)
        {
            return x;
        }

        ~Base ()
        {
            cout << "Base:Destructor()" << endl;
        }
};

class Derived : public Base 
{
    private:
        int y;
    public:
        Derived() : y{15}                       // will initialize the part of the derived part
        {   
            cout << "Derived:Derived()" << endl;   
        }    
   
        Derived (int y, int x) : Base(x) , y{y}
        {
            cout << "Derived::Derived(int)::Base(y)" << endl;
        }        

        Derived(const Derived& source) 
        {
            this->y = source.y;
        }

        void setY(int val)
        {
            y= val;
        }

        int getY(void)
        {
            return y;
        }   

        ~Derived ()
        {
            cout << "Derived:Destructor()" << endl;
        }             
};

int main ()
{
    Base a{10};
    Derived b{20};
}
