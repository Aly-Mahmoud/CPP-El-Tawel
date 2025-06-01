#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    vector<int> vec {1,2,3};

    auto it1 = vec.begin();
    auto it2 = vec.rbegin();

    while (it2 != vec.rend())
    {
        cout << *it2 << endl;
        ++it2;
    }

    while (it1 != vec.end())
    {
        cout << *it1 << endl;
        ++it1;
    }
    
    return 0;
}