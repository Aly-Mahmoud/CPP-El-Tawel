#include <iostream>

using namespace std;

template <typename T>
void func ()
{
	static T x = 0;
    x++;
    cout << x << endl; 
}

int main ()
{
    func<int>();
    func<double>();
    func<float>();

    func<int>();
    func<double>();
    func<float>();
}