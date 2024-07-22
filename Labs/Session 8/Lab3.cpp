#include <iostream>

using namespace std;

int counter = 0;

template <typename T>
class Counter 
{
    private :
        T c1 = 0;
    public:

    Counter()
    {
        cout << "Default constructor" << endl;
        obj_count();
    }

    // ~Counter()
    // {
    //     cout << "Default destructor" << endl;
    // }

    void obj_count()
    {
        counter++;
    }

    T Get_counter()
    {
        return counter;
    }
};

int main ()
{
    Counter <int> a;
    Counter <int> b;
    Counter <int> c;

    cout << c.Get_counter() << endl;
}