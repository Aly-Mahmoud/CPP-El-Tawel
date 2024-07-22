#include <iostream>
#include <limits>
using namespace std;

class Rectangle {
private:
    float Length;
    float Width;

public:
    void set_length() 
    {
        cout << "Enter the Length: ";
        cin >> Length;
        cout << endl;
    }

    void set_width() 
    {
        cout << "Enter the Width: ";
        cin >> Width;
        cout << endl;
    }

    void calc_area() 
    {
        float area = Length * Width;
        cout << "Area: " << area << endl;
    }
};

int main () 
{
    int Termination_var;

    Rectangle R1;

    do 
    {
        cout << "Press 0 to terminate, or any other key to start: ";
        cin >> Termination_var;

        switch (Termination_var)
        {
            case 0:
                /*Terminate in while*/
            break;

            default:
                R1.set_length();
                R1.set_width();
                R1.calc_area();
            break;
        } 



    } while (Termination_var != 0);

    return 0;
}
