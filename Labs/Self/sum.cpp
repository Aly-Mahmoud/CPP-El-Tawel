#include <memory>
#include <utility>
#include <iostream>

using namespace std;


class Person
{
    private:
        string name;
    public:
        Person (string n = "") : name (n)
        {
            cout << "constructor" << endl;
        }

        Person (const Person&rhs) 
        {
            cout << " copy constructor " << endl; 
        } 
};

int main ()
{
    // shared_ptr<int> el3w = make_unique<int>(100);

    // Person p1;

    shared_ptr<Person> el3w = make_shared<Person>("el3w");
    shared_ptr<Person> noby = el3w;
    shared_ptr<Person> aly = noby;

    shared_ptr<int> hamada = make_shared<int> (100);

    cout << aly.use_count() << endl;

    return 0;
}