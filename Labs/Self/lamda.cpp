#include <iostream>
#include <functional>
using namespace std;

int studnets [10] = {0};

void reward ( int x , function<void(int)> l )   // auto = function<void(int)> = void (*l) (int) 
{
    l(x);
    cout << endl << "Reward has been made" << endl;
}

auto punishment()// function<void(int)
{
    cout << "You have been naughty, take this punishment" << endl;
    return [] (int x) {for (auto &stud : studnets) {stud-=x; cout << stud << ", " ;} };
}


void bouns (int x)
{
    for (auto &stud : studnets)
    {
        stud += x;
        cout << stud << ", ";
    }
}

void applaus ( int time )
{
    for ( int i=0 ; i< time; i++)
    {
        cout << "Clap" << " " ;
    }
}

void print_if(vector<int> nums, bool (*predicate) (int) )
{
    cout<<"\n";
    for (int i : nums)
        if (predicate(i))
            cout << i << " ";
}
 
int main()
{
    // reward(10 , bouns );
    // reward(5 , applaus);

    // void (*K)(int) = punishment();
    // auto a = punishment();
    // function<void(int)> M = punishment();

    // K(2);
    // a(1);
    // M(3);

    // reward(3, bouns);

    vector<int> nums {1,2,3,4,5,6,7,8,9,10};
    print_if(nums, [](auto x){return x % 2 == 0;});
    print_if(nums, [](auto x){return x % 2 != 0;});

    return 0;
}