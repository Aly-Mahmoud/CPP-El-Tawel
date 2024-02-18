#include <iostream>

class Student
{
    private:
        std::string name;
        std::string Class;
        int roll_number;
        int marks;

    public:
        Student()
        {
            std::cout<<"the defult constructor has been called"<<std::endl;
        }

        ~Student()
        {
            std::cout<<"the defult distructor has been called"<<std::endl;
        }

        void set_name(std::string source)
        {
            name = source;
            std::cout<<"Name: "<<name<<std::endl;            
        }

        void set_class(std::string source)
        {
            Class = source;
            std::cout<<"class: "<<Class<<std::endl;            
        }

        void set_rollnumber(int source)
        {
            roll_number = source;
            std::cout<<"rollnumber: "<<roll_number<<std::endl;            
        }

        void set_marks (int source)
        {
            marks = source;
            std::cout<<"Marks"<<marks<<std::endl; 

            if (90<=marks<=100)     
            {
                std::cout<<"Grade: A"<<std::endl;     
            } 
            else if (80<=marks<=89)  
            {
                std::cout<<"Grade: B"<<std::endl;     
            }    
            else if (70<=marks<=79)
            {
                std::cout<<"Grade: C"<<std::endl; 
            } 
            else if (60<=marks<=69)
            {
                std::cout<<"Grade: D"<<std::endl; 
            } 
            else
            {
                std::cout<<"Grade: F"<<std::endl;                 
            }
        }        

};

int main ()
{
Student S1;
S1.set_name("Mohamed Ali");
S1.set_class("A");
S1.set_rollnumber(3);
S1.set_marks(98);
}