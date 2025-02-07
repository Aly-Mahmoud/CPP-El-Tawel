#include<iostream>
#include "test.hpp"

using namespace std;


Character::Character() : Health(100), Tools_count(0), Name("")
{
    Tools = nullptr;

    cout<<"This is default Constructor"<<endl;

    players_on_server++;
}

Character::Character( string name , int health , int tool_count) : Health(health), Tools_count(tool_count), Name(name)
{
    Tools = new string[Tools_count];
    for(int i=0; i<Tools_count; i++)
    {
        Tools[i]= "";
    }

    cout<<"This is parametrized Constructor"<<endl;
    players_on_server++;
}

Character::Character(const Character& src)
{
    Health = src.Health;
    Name = src.Name;
    Tools_count = src.Tools_count;

    Tools = new string [Tools_count];

    for(int i=0; i<Tools_count; i++)
    {
        Tools[i] = src.Tools[i];
    }

    cout<<"This is Copy Constructor"<<endl;
    players_on_server++;
}

Character::Character(Character&& src) 
{
    Health = src.Health;
    Name = std::move(src.Name);
    Tools_count = src.Tools_count;
   
    Tools = src.Tools;
    src.Tools = nullptr;
    src.Tools_count = 0;

    cout<<"This is Move Constructor"<<endl;
    players_on_server++;
}

Character::~Character()
{
    delete[] Tools;

    cout<<"This is The Destructor"<<endl;
    players_on_server--;
}

Character& Character::operator=(const Character& src)
{

    if(this != &src)
    {
        Health = src.Health;
        Name = src.Name;
        Tools_count = src.Tools_count;

        delete[] Tools;

        if(src.Tools != nullptr)
        {
            Tools = new string[Tools_count];

            for(int i=0; i<Tools_count; i++)
            {
                Tools[i] = src.Tools[i];
            }
        }
        else
        {
            Tools = nullptr;
        }
    }
cout<<"This is Copy assigment"<<endl;
}

Character& Character::operator=(Character&& src)
{
    if(this!= &src)
    {
        Health = src.Health;
        Name = std::move(src.Name);
        Tools_count = src.Tools_count;

        delete[] Tools;

        if(src.Tools != nullptr)
        {
            Tools = src.Tools;
            src.Tools = nullptr;
            src.Tools_count = 0; 
            src.Health = 0;
        }
        else
        {
            Tools = nullptr;
        }
    }

    cout<<"This is Move assigment"<<endl;
}


void Character::add_Name(string name)
{
    Name = name;
}
void Character::add_Health(int health)
{
    Health = health;
}
void Character::add_Tool_Count(int tool_count)
{
    if (tool_count > 0)
    {
        string* newTools = new string[tool_count];
        for (int i = 0; i < (tool_count < Tools_count ? tool_count : Tools_count); ++i)
        {
            newTools[i] = Tools[i];
        }
        delete[] Tools;
        Tools = newTools;
        Tools_count = tool_count;
    }
}

void Character::add_Tool(int pos, string tool_name)
{
    if( (pos < Tools_count) && (pos >= 0) )
    {
        Tools[pos] = tool_name;
    }
}

void Character::display_character() const
{
    cout << "Name : " << Name << endl;
    cout << "Health : " << Health << endl;
    cout << "Number of Tools : " << Tools_count << endl;
    for(int i=0; i<Tools_count; i++)
    {
        cout << "Tool number " << (i+1) <<" : "<<Tools[i]<< endl; 
    }

}

void Character::display_total_player_number()
{
    cout << "The Number of players is: " << Character::players_on_server << endl;
}
/*
void Character::add_map (string map_name)
{
    Character::map = map_name;
}
*/
void Character::display_map_name()
{
    cout << "The name of the map is: "<< Character::map << endl;
}

ostream& operator<<(ostream& os, const Character& src)
{
    os << "Player Name: " << src.Name << endl;
    os << "Player Health: " << src.Health << endl;
    os << "Number of Tools: " << src.Tools_count << endl;
    for(int i=0; i<src.Tools_count; i++)
    {
        os << "Tool number " << (i+1) <<" : "<<src.Tools[i]<< endl; 
    }

    return os; 
}

void Host_change_map (string map_name)
{
    Character::map = map_name;
}

int main (void)
{
    Character c1("El3aw",68,4);

    c1.add_Tool(0,"Knife");
    c1.add_Tool(1,"Sniper");
    c1.add_Tool(2,"RBG");
    c1.add_Tool(3,"MP7");
    
    Character c2("Aly",100,5);
    
    c2.add_Tool(0,"Gun");
    c2.add_Tool(1,"Pistol");
    c2.add_Tool(2,"M4");
    c2.add_Tool(3,"MP5");
    c2.add_Tool(4,"Uzi");
    

    c2 = std::move(c1);

    c2.display_character();

    

    return 0;
}