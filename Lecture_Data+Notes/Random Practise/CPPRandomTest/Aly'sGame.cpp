#include "test.hpp"
#include <iostream>

using namespace std;

Character::Character() : Name("Player") , Health(100), Tools_count(0)
{
    Tools = NULL;

    cout << "The default constructor has been called" << endl;
}

Character::Character( string name , int health , int tool_count )
{
    Name = name;
    Health = health;
    Tools_count = (tool_count>=0) ? tool_count : 0;

    if (Tools_count > 0)
    {
        Tools = new string [Tools_count];
        for (int i = 0 ; i < tool_count ; i++)
        {
            Tools[i] = "";
        }
    }

    cout << "The Parameterized constructor initiated values are : Name " << Name << " Health " << Health << " Tools_count " << Tools_count << endl;
}

Character::Character(const Character& src)
{
    Name = src.Name;
    Health = src.Health;
    Tools_count = src.Tools_count;
    
    if (Tools_count > 0)
    {
        Tools = new string [src.Tools_count];
        for (int i = 0 ; i < Tools_count ; i++)
        {
            Tools[i] = src.Tools[i];
        }
    }
    else
    {
        Tools = NULL;
    }
    cout << "Copy Constructor completed succefully" << endl;
}

Character::Character(Character&& src)
{
    if (this != &src)  // prevent self assignation 
    {
        Name = move(src.Name);
        Health = src.Health;
        Tools_count = src.Tools_count;
        Tools = src.Tools;
        src.Tools = NULL;

        cout << "Move constructor has been completed succefully" << endl;
    }
    else
    {
        cout << "Self assignation is prohebited" << endl;
    }
}

Character::~Character()
{
    delete [] Tools;
    cout << "Destructor is being called" << endl;
}

Character& Character::operator=(const Character& src)
{
    if (this != &src) // prevent self assignation
    {
        Name = src.Name;
        Health = src.Health;
        Tools_count = src.Tools_count;
        if (Tools != NULL)
        {
            delete [] Tools;
        }

        if (src.Tools_count > 0 && src.Tools != NULL)
        {
            Tools = new string [src.Tools_count];
            for (int i = 0 ; i < Tools_count ; i++)
            {
                Tools[i] = src.Tools[i];
            }
        }
        else
        {
            Tools = NULL;
        }
        cout << "Copy Constructor completed succefully" << endl;
    }
    else
    {
        cerr << "Self assignation is prohebited" << endl;
    }
}

Character& Character::operator=(Character&& src)
{
    if ( this != &src )
    {
        delete[] Tools;
        Name = move(src.Name);
        Health = src.Health;
        Tools_count = src.Tools_count;

        Tools = src.Tools;
        // Nullify source
        src.Tools = nullptr;
        src.Tools_count = 0;
        src.Health = 0;

        cout << "Copy Constructor completed succefully" << endl;
    }
    else
    {
        cerr << "Self assignation is prohebited" << endl;
    }

}

void Character::add_Name(string name)
{
    Name = name;
}

void Character::add_Health (int health)
{
    Health = health;
}

void Character::add_Tool_Count (int tool_count)
{
    if (Health > 0)
    {
        string *tools = new string [tool_count];

        for (int i= 0 ; i<tool_count ; i++)
        {
            if (i < Tools_count)
            {
                tools[i] = Tools[i];
            }        
            else
            {
                tools[i] = "";
            }
        }
        delete [] Tools;
        Tools = tools;

        Tools_count = tool_count;
    }

}

void Character::add_Tool(int pos, string tool_name)
{
    if (Health > 0)
    {
        if (pos <= Tools_count && pos > 0)
        {
            Tools[pos-1] = tool_name;
        }
        else
        {
            cerr << "Out of capacity for tools" << endl;
        }
    }
    else
    {
        cerr << "Cannot add tools; character's health is zero or less." << endl;
    }

}

void Character::display_character () const
{
    cout <<"Name   : " << Name << endl;
    cout <<"Health : " << Health << endl;
    cout <<"Tools number :" << Tools_count << endl;
    
    for (int i=0 ; i<Tools_count ; i++)
    {
        cout << "Tool Number " << i+1 << " :" << Tools[i] <<endl;
    }

}

int main()
{
    // Default constructor
    Character C1;
    C1.display_character();

    // Parameterized constructor
    Character C2("Hero", 150, 3);
    C2.display_character();

    // Adding tools
    C2.add_Tool(1, "Sword");
    C2.add_Tool(2, "Shield");
    C2.add_Tool(3, "Potion");
    C2.display_character();

    // Increasing tool count
    C2.add_Tool_Count(5);
    C2.add_Tool(4, "Bow");
    C2.add_Tool(5, "Arrows");
    C2.display_character();

    // Copy constructor
    Character C3(C2);
    C3.display_character();

    // Move constructor
    Character C4(std::move(C3));
    C4.display_character();

    // Copy assignment operator
    C1 = C4;
    C1.display_character();

    // Move assignment operator
    C3 = std::move(C4);
    C3.display_character();

    return 0;
}