#include <iostream>

using namespace std;

class Base 
{
    // private:
        // int x;
    public:
        int x;
        /*Default Constructor with pre-set value of 10*/
            Base() : x{10}
            {
                cout << "Base:Base() " <<" Pre-set value of" << x <<endl;   
            }    
        /*--------------------------------------------*/

        /*Parametrized constructor with default value of x*/
            Base (int x) : x{x}                                      // :x{x} initialization before it goes to what is in the bractes
            {
                cout << "Base::Base(int)" <<"Value = " << x << endl;
            }
        /*------------------------------------------------*/

        /*Copy Constructor*/
            Base(const Base &source)
            {
                this->x = source.x;
                cout << "Copy Constructor of the Base class" <<endl;
            }
        /*----------------*/

        /*Copy assignment operator*/
            Base &operator=(const Base &source)
            {
                x= source.x;
                return *this;
            }
        /*------------------------*/     

        /*Method to set the private variable x*/
            void setX(int val)
            {
                x= val;
            }
        /*------------------------------------*/    

        /*Method to get the private varaible x*/
            int getX(void)
            {
                return x;
            }
        /*-----------------------------------*/

        /*Destructor*/
            ~Base ()
            {
                cout << "Base:Destructor()" << endl;
            }
        /*----------*/
};

class Derived : public Base 
{
    // private:
        // int y;
    public:
        int y;
        /*Constructor with a preset value of the private data y = 15*/
            Derived() : y{15}                       // will initialize the part of the derived part
            {   
                cout << "Derived:Derived()" << endl;   
            }    
        /*---------------------------------------------------------*/
   
        /*Parametrized Constructor to fill data of child class only*/
            Derived (int y)
            {
                this->y=y;
                cout << "Derived::Derived(int)" <<endl;
            }
        /*---------------------------------------------------------*/

        /*parametrized constructor to fill data of the parent and child class*/
            Derived (int y, int x) : Base(x) , y{y}
            {
                cout << "Derived::Derived(int,int)::Base(y)" << endl;
            }   
        /*-------------------------------------------------------------------*/         

        /*Copy constructor*/
            Derived(const Derived &source) : Base(source)  // casting source to base instead of Derived
            {
                this->y = source.y;
                cout << "Copy Constructor of the Derived class" << endl;
            }
        /*----------------*/

        /*Copy assignment operator*/
            Derived &operator=(const Derived &source) // Methods can not have initliaztion after :
            {
                Base::operator=(source);
                y = source.y;
                return *this;
            }
        /*------------------------*/            

        /*Method to set the private varaible y*/
            void setY(int val) 
            { 
                y= val;
            }
        /*------------------------------------*/

        /*Method to get the private varaible y*/
            int getY(void)
            {
                return y;
            }   
        /*------------------------------------*/

        /*Constructor*/
            ~Derived ()
            {
                cout << "Derived:Destructor()" << endl;
            }         
        /*-----------*/    
};

int main ()
{

    Base    x ;
    Base    y {9};
    Base    z {x};

    Derived a {40};    // a-> x : 10 default pre set value (TRUE) , a->y : 40 paramterized constructor (False) 
                       // debug session to see varabiles.

    Derived b {20,2};  // 

    Derived c {a};     //x : a5d al default as expected , y = a5d al paramter as expected

    Derived d {b};     //x : a5d al default msh al set as a parameter , y = a5d al paramter as expected

}
