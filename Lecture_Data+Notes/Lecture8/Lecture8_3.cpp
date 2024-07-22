#include <iostream>

using namespace std;

template <typename T>

class type
{
    private:
        T* P_Type;
    public:
        type()
        {
            P_Type = new T;
        }

        ~type()
        {
            delete P_Type;
        }

        void Set_value (const T & val)
        {
            *P_Type = val;
        }

        T Get_value (void) const 
        {
            return *P_Type;
        }
};

int main ()
{
    type<double> a;
    type<int> b;
    a.Set_value(4.1);
    b.Set_value(2);

    cout << a.Get_value() << endl;
    cout << b.Get_value() << endl;

    return 0;
}