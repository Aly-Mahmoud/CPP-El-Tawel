#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

class Account 
{
    private:
        string name;
        int ID;
    public:
        Account (string n="None", int id=0) : name(n), ID(id)
        {
            cout << "Para constru" <<endl; 
        }

        void print()
        {
            cout << "Person" << endl;
            cout << name << endl;
            cout << ID << endl;
            cout << "----" << endl;
        }

        Account (const Account &lhs)
        {
            name = lhs.name;
            ID = lhs.ID;
            cout << " Copy constructor " << endl;
        }
};

int main ()
{
    Account p1 ("Adora",27);

    deque <Account> d (4);

    cout << d.size() << endl;

    d.push_back(p1); // temp object is made to copy

    cout << d.size() << endl;

    d.emplace_back("Aly",24); //no temp obj will be made

    cout << d.size() << endl;
    
    return 0;
}
