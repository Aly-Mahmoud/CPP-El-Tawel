#include <iostream>
#include <string>
using namespace std;

// Decalre class 


class player{
    private:

        std::string name;
        int health;
        int *ptr;

    public:

        player() : player(0,"none",0)
        {
            std::cout <<"constructor has been called"<<std::endl;
        }

        player (int source) : player(source,"none",0)
        {
            std::cout << " player::player(int)"<<std::endl;
        }

        player (std::string source) : player(0,"source",0)
        {
            std::cout << " player::player(string)"<<std::endl;
        }

        player (int source1, std::string source2, int source3 ) : health {source1}, name {source2}, ptr {new int(source3)}
        {
            std::cout << " player::player(int,string,ptr)"<<std::endl;
        }

        ~player()
        {
            std::cout <<"Destructor has been called"<<std::endl;
        }

        void display_data(void)
        {
            std::cout <<"The health is :"<< health << std::endl;
            std::cout <<"The  name :" << name << std::endl;
            std::cout <<"ptr value :" << *ptr<< std::endl;
        }        

        player(const player &source) 
        {
            std::cout <<"copy Constructor has been called"<<std::endl;
            name = source.name;
            health = source.health;
            ptr = new int;
            *ptr = *(source.ptr);
        }

        
        player (player &&source)
        {
            name = source.name;
            health = source.health;
            ptr = source.ptr;
            source.ptr = nullptr;
            std::cout <<"Move Constructor has been called"<<std::endl;
        }


};


int main (void)
{

player p1{100,"Ahmed",0};                   //   
player p2=p1;                               //   invoke copy constructor                                    Lvalue
p2.display_data();                          //   
player p3{std::move(player{70,"Aly",0})};   // optimizatio occur so we add std::move() to force the         Rvalue
p3.display_data();  

return 0;
}
