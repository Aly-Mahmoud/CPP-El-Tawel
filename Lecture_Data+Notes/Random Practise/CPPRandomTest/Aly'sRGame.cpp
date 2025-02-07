#include "test.hpp"
#include <iostream>

using namespace std;

Character::Character() : Name("Player"), Health(0), Tools_count(0) , Tools(NULL)
{
    cout << "Default Constructor is Called" << endl;
    players_on_server++;
}

Character::Character( string name , int health , int tool_count )
{
    Name = name;
    Health = health;
    Tools_count = (tool_count >=0 ) ? tool_count : 0;

    if (Tools_count > 0)
    {
        Tools = new string [Tools_count];
        for (int i=0 ; i< Tools_count ; i++)
        {
            Tools[i] = "";
        }
    }
    cout << "Paramterized Construtor is called" << endl;
    players_on_server++;
}

Character::Character(const Character& src) //Copy constructor
{
    Name = src.Name;
    Health = src.Health;
    Tools_count = src.Tools_count;

    if(src.Tools != NULL && Tools_count != 0)
    {
        Tools = new string [Tools_count];
        for (int i=0 ; i<Tools_count ; i++)
        {
            Tools[i] = src.Tools[i];
        }
    }
    else
    {
        Tools = NULL;
    }
    players_on_server++;
}

Character::Character(Character&& src)
{
    Name = move(src.Name);
    Health = src.Health;
    Tools_count = src.Tools_count;
    Tools = src.Tools;

    src.Name = "DeletedCharacter";
    src.Health = 0;
    src.Tools_count =0;
    src.Tools = NULL;
}

Character::~Character()
{
    delete[] Tools;
    players_on_server--;
}

Character& Character::operator=(const Character& src)
{
    if (this != &src)
    {
        Name = src.Name;
        Health = src.Health;
        Tools_count = src.Tools_count;

        delete [] Tools;

        if (src.Tools != NULL)
        {
            Tools = new string [Tools_count];
            for (int i=0 ; i<Tools_count; i++)
            {
                Tools[i] = src.Tools[i];
            }
        }
        else
        {
            Tools = NULL;
        }
    }
    return *this;
}

Character& Character::operator=(Character&& src)
{
    if (this != &src)
    {
        if (Tools != NULL)
            delete[] Tools;

        Name = src.Name;
        Health = src.Health;
        Tools_count = src.Tools_count;
        Tools = src.Tools;

        src.Name = "DeletedCharacter";
        src.Health = 0;
        src.Tools_count =0;
        src.Tools = NULL;
    }
    return *this;
}

void Character::add_Name(string name)
{
    Name = name;
}

void Character::add_Health(int health)
{
    Health = health;
}

void Character::add_Tool_Count (int tool_count)
{
    if (tool_count >= 0)
    {
        string* new_Tools = (tool_count > 0) ? new string [tool_count] : NULL;

        for (int i = 0; i<min(Tools_count,tool_count); i++)
        {
            new_Tools[i] = Tools[i];
        }

        /*redundant code for empty initlization*/
            // if (Tools_count < tool_count)
            // {
            //     for(int i= Tools_count ; i < tool_count ; i++)
            //     {
            //         new_Tools[i] = "";
            //     }
            // }
        /*-------------------------------------*/

        if (Tools!=NULL)
        {
            delete[] Tools;
        }
        Tools = new_Tools;
        Tools_count = tool_count;
    }
}

void Character::add_Tool(int pos, string tool_name)
{
    if (Tools != NULL && Tools_count >= pos && pos>0)
    {
        Tools[pos-1]= tool_name;
    }
}

void Character::display_character () const
{
    cout << "Name: " << Name << endl;
    cout << "Health: " << Health << endl;
    cout << "Tools_count:" << Tools_count << endl;
    for (int i = 0; i< Tools_count; i++)
    {
        cout << "Tool No. " << i+1 << " :" << Tools[i] <<endl ;
    }
}

void Character::display_total_player_number ()
{
    cout << "The Total number on server is :" << Character::players_on_server << endl;
}

// void Character::add_map (string map_name)
// {
//     map = map_name;
// }

void Character::display_map_name()
{
    cout <<"The map is : "<< Character::map << endl;
}

ostream& operator<<(ostream& os, const Character& src)
{
    os << "Character Name : " << src.Name <<endl;
    os << "Charcter Health : " << src.Health << endl;
    os << "Charcter Tools_count : " << src.Tools_count << endl;
    for (int i = 0; i< src.Tools_count; i++)
    {
        cout << "Tool No. " << i+1 << " :" << src.Tools[i] <<endl ;
    }

    return os;
}

void Host_change_map (string map_name)
{
   Character::map = map_name;
}


