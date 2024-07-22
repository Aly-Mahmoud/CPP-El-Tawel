#include <iostream>

using namespace std;

template <typename T>
T get_max(T x , T y)
{
    return (x>y) ? x : y;
}

template <typename T>
class ptr 
{
    T* m_p;
    public:
        ptr() : m_p{new T}{}
};

int main ()
{
    cout << get_max<int>(5,10) << endl;
    cout << get_max<float> (5.3,5.8) << endl;
}