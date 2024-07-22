#include <iostream>

using namespace std;

class Car 
{
    private :
        string Brand_Name;
        string Model_Name;
        int Man_Year;
    public:

        Car() : Brand_Name {"Audi"}, Model_Name {"C9"}, Man_Year{2009}
        {
            cout << "Default Constructor" << endl; 
        }

        void set_BrandName(string name) 
        {
            Brand_Name = name;
        }

        void set_ModelName(string name)
        {
            Model_Name = name;
        }

        void set_ManYear(int year)
        {
            Man_Year = year;
        }

        string get_BrandName()
        {
            return Brand_Name;
        }

        string get_ModelName()
        {
            return Model_Name;
        }

        int get_ManYear()
        {
            return Man_Year;
        }
};

int main()
{
    int Options;
    Car C1;
    string brand;
    string model;
    int year;
do
{ 
    cout << " Press 0 to terminate, or any other key to start: "<< endl;
    cout << " Press 1 to See the registered Car data " << endl;
    cout << " Press 2 to update the car data " << endl;
    cin >> Options;

    switch (Options)
    {
        case 0:
            /*Terminate in While*/
        break;

        case 1:
            brand = C1.get_BrandName();

                cout << "Company" << brand <<endl; 

            model = C1.get_ModelName();

                cout << "Model" << model << endl;

            year = C1.get_ManYear();

                cout << "Year" << year <<endl;

        break;

        case 2:
            cout << "set brand name" << endl;

                cin >> brand ;

            cout << "set Model name" << endl;

                cin >> model ;

            cout << "set Model Year" << endl;

                cin >> year;        
        
            C1.set_BrandName(brand);

                cout << "Updated Company" << brand <<endl; 

            C1.set_ModelName(model);

                cout << "Model" << model << endl;

            C1.set_ManYear(year);

                cout << "Year" << year <<endl;

        break;
    }

} while (Options != 0);
}