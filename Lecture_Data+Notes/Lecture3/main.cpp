#include <iostream>

using namespace std;
// Decalre class 

class Person
{

    private:    

        std::string name;
        std::string ID;
        static int counts; 
        friend class Animal;
        friend void func_test();


    public:

        //defult construtor
        Person()
        {
            std::cout <<"constructor0 has been called"<<std::endl;
            name = "NULL";   // assignation
            ID = "NULL";     // assignation
            counts++;
        };

        //Parameterized Constructor 
        Person(std::string source)  
        {
             name = source; std::cout<<"Parameterized Constructor 1 has been called"<<std::endl;
        };

        //Parameterized Constructor 
        Person(std::string name, std::string ID) 
        { 
            this->name = name;
            this->ID = ID;
            std::cout<<"Parameterized Constructor 2 has been called"<<std::endl;
            counts++;
        };

        //destructor
        ~Person()
        {
            std::cout<<"Destructor has been called"<<std::endl;
        };

        void Change_info(std::string name, std::string ID )
        {
            
            this->name = name;
            this->ID = ID;
            std::cout<<"Data Changed"<<std::endl;            
        }

        //function 
        void display_info(void);

        //static function can access static variables only
        static void display()
        {
            std::cout<<"Number of object created"<< counts << std::endl;
            //name = "Mohamed";
        }

        //copy constructor
        Person (const Person &source)
        {
            this->name = source.name;
            this ->ID = source.ID;
            std::cout<<"Person(const Person&)" << std::endl;
        }
        
        //Copy assigmnet overloading
        // = Opertaion overloading with the support of chaining -> the return data type is refrence to person class
        Person &operator= (const Person &source)
        {
                //body
                std::cout<<"Operator = (const person &source)"<<std::endl;
                name=source.name;
                ID=source.ID;
            return *this;
        }        

};

//class person method implementation
void Person::display_info(void)
{
    std::cout <<"The name is :"<< name << std::endl;
    std::cout <<"The ID is :" << ID << std::endl;
    // the function is constant so i can not change any of the data of the class 
    // name = "Ahmed";
}

//friend function implementation
void func_test()
{
    static int x = 10;
    x++;
    Person p1;
        p1.name="Omar";
    std::cout <<"Value of X is"<<x<<std::endl;
}

//assigning private data in class  person
int Person::counts =0;

//implementation of a friend class 
class Animal 
{
    public:
        void test(void)
        {
            Person p1;
                p1.name = "lion";
        }
};

int main (void)
{
    Person p1("Hussien" , "12345");
    p1.display_info();
    Person p2("Aly" , "12345");
    p2.display_info();
    Person p3("Mohamed", "12345");
    p3.display_info();

    Person p4{p2};

    p1=p3;

    p1.display_info();
    p2.display_info();
    p3.display_info();

    p3.Change_info("Hacked" , "Hacked");

    p1.display_info();
    p2.display_info();
    p3.display_info();

return 0;
}
