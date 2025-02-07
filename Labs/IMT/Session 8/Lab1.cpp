#include <iostream>

using namespace std;

template <typename T>
T multiples (T x, int n)
{
    T sum ;
    for (int i=0 ; i < n ; i++)
    {
        sum += i*x;
        if (i == n-1)
        {
            sum += 1;
        }
    }
    return sum;
}

int main ()
{
    cout << "******************************************" << endl;
    cout << "This application Calculates This Formula: " << endl;
    cout << "    Sum = 1 + x + 2x + 3x + ... + nx      " << endl;
    cout << "******************************************" << endl;

    
    cout << multiples<int>( 5, 3 ) << endl;
    cout << multiples<float>( 5.5 , 3) << endl;
}