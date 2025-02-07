#include <iostream>

using namespace std;

float pi = 3.1415;

class Circle
{
    private:
        float radius;
    public:

        void set_radius()
        {
            cout << "Enter the Circle radius: ";
            cin >> radius;
            cout << endl;
        }

        void Calc_area(Circle obj)
        {
            float area = pi*radius*radius;
            cout << "Circle area : " << area << endl;
        }
};

int main ()
{
    Circle C1;
    while (1)
    {
    C1.set_radius();
    C1.Calc_area(C1);
    }
    return 0;
}