#include <iostream>

using namespace std;

        int Counter = 0;

class Test
{
    private:

    public:
        Test()
        {
            Counter++;
            cout<<"Constructor has been called, Counter value = "<<Counter<<endl;
        }

        ~Test()
        {
            Counter--;
            cout<<"Destructor has beebn called, Counter value = "<<Counter<<endl; 
        }
};

int main ()
{
    Test T1;
    Test T2;
    Test T3;
    Test T4;
}