#include <iostream>

using namespace std;

class Person
{
    private:
        string Name;
        int Age;
        string Country;

    public:

        void set_name ()
        {
            cout << "Enter Your Name : "<<endl;
            cin >> Name ;
        }

        void set_Age ()
        {
            cout << "Enter Your Age : "<<endl;
            cin >> Age ;
        }

        void set_Country ()
        {
            cout << "Enter Your Counter : "<<endl;
            cin >> Country;
        }

        void get_Name()
        {
            cout << "Your name is : "<< Name << endl;
        }

        void get_Age()
        {
            cout << "Your age is : " << Age << endl;
        }

        void get_Country ()
        {
            cout << "Your country is " << Country <<endl;
        }
};

int main ()
{
    int Termination_Var;

    Person P1;

    do
    {
        cout << "Press 0 to terminate, or any other key to start: ";
        cin >> Termination_Var;

        switch (Termination_Var)
        {
            case 0:
                /*Terminate in While*/
            break;

            default:
                P1.set_name();
                P1.set_Age();
                P1.set_Country();

                P1.get_Name();
                P1.get_Age();
                P1.get_Country();
            break;
        }

    } while (Termination_Var != 0);

}