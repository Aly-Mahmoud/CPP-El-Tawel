#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Vehicle
{
    private:
        string brand;
        T fuelCapacity;
        int topSpeed;

    public:
        Vehicle(string b, T f_c , int top ) : brand(b), fuelCapacity(f_c), topSpeed(top)
        {
            cout << "General Template constructor" << endl;
        }

        void displayInfo() const
        {
            cout << "Car Info : " << endl;
            cout << "Brand : " << brand << endl;
            cout << "Fuel Capacity : " << fuelCapacity << " L " <<endl;
            cout << "Top Speed : " << topSpeed << " Km/hr " <<endl;
        }
};

template <>
class Vehicle<void>
{
    private:
        string brand;
        int batteryCapacity ;
        int topSpeed;

    public:
        Vehicle(string b, int b_c , int top ) : brand(b), batteryCapacity(b_c), topSpeed(top)
        {
            cout << "Special Template constructor" << endl;
        }

        void displayInfo() const
        {
            cout << "Car Info : " << endl;
            cout << "Brand : " << brand << endl;
            cout << "Battery Capacity : " << batteryCapacity << " kWh " <<endl;
            cout << "Top Speed : " << topSpeed << " Km/hr " <<endl;
        }
};

template <typename T>
void showVehicleInfo( const Vehicle<T>& v )
{
    v.displayInfo();
}


int main ()
{
    Vehicle<int> Mina  ( "Jaguar" , 70 , 320 );
    Vehicle<int> Adora ( "Toyota" , 50 , 180 );
    Vehicle<void> Aly  ( "Tesla"  , 75 , 220 );

    showVehicleInfo (Mina);
    showVehicleInfo (Adora);
    showVehicleInfo (Aly);

    return 0;
}