#include <iostream>

using namespace std;
// Decalre class 
class Person
{
    private:    

        std::string name;
        std::string ID;

    public:


        Person()
        {
            std::cout <<"constructor0 has been called"<<std::endl;
            name = "NULL";   // assignation
            ID = "NULL";     // assignation
        };

        //Parameterized Constructor 

        Person(std::string source){ name = source; std::cout<<"Constructor1 has been called"<<std::endl;};

        Person(std::string source, std::string source2){ name = source; ID = source2;std::cout<<"Constructor2 has been called"<<std::endl;};


        ~Person()
        {
            std::cout<<"Destructor has been called"<<std::endl;
        };

        void display_info(void);

};

void Person::display_info(void)
{
    std::cout <<"The name is :"<< name << std::endl;
    std::cout <<"The ID is :" << ID << std::endl;
}

class player{
    private:

        std::string name;
        int health;

    public:

        player() : player(0,"none")
        {
            std::cout <<"constructor has been called"<<std::endl;
        }

        player (int source) : player(source,"none")
        {
            std::cout << " player::player(int)"<<std::endl;
        }

        player (std::string source) : player(0,"source")
        {
            std::cout << " player::player(string)"<<std::endl;
        }

        player (int source1, std::string source2) : health {source1}, name {source2}
        {
            std::cout << " player::player(int,string)"<<std::endl;
        }

        ~player(){std::cout <<"Destructor has been called"<<std::endl;}

        void display_data(void);

};

void player::display_data(void)
{
    std::cout <<"The health is :"<< health << std::endl;
    std::cout <<"The  name :" << name << std::endl;
}

int main (void)
{

/*        Person p1;
        Person p2("Aly");
        Person p3("mohamed", "12345");
        p1.display_info();
*/

    player p1;
    p1.display_data();

    return 0;
}
