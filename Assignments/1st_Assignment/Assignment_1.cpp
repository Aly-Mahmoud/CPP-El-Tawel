#include <iostream>

class Date
{
    private:
        int day;
        int month;
        int year;

    public:

        Date() : Date(1,1,1990)
        {
            std::cout <<"the defult constructor has been called"<<std::endl;
        }

        Date(int source1 , int source2, int source3 ) 
        {
            day=source1;
            month=source2;
            year=source3;
        }

        ~Date()
        {
            std::cout<<"the defult destructor has been called"<<std::endl;
        }

        void setDay(int source1)
        {
            day=source1;
            std::cout<<"Input day: "<<source1<<std::endl;
        }

        void setMonth(int source2)
        {
            month=source2;
            std::cout<<"Input month: "<<source2<<std::endl;            
        }

        void setYear(int source3)
        {
            year=source3;
            std::cout<<"Input year: "<<source3<<std::endl;            
        }   

        void Display_Date()
        {
            if(1<=day<=31 && 1<=month<=12 && 1995<=year<=2000)
            std::cout<< "Date: " << day <<"/"<< month <<"/"<< year << std::endl;    
            std::cout<<"The date is valid."<<std::endl;                         
        }

    protected:    

};


int main ()
{
    Date D1;
    D1.setDay(28);
    D1.setMonth(7);
    D1.setYear(2000);
    D1.Display_Date();
}