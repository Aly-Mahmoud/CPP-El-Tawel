#include <string>
#include <utility>

using namespace std;

class Character 
{
    private:
        string Name;
        int Health;
        int Tools_count;
        string* Tools;
        static int players_on_server;
        static string map;

    public:
        Character();
        Character( string name , int health , int tool_count );
        Character(const Character& src);
        Character(Character&& src);
        ~Character();
        Character& operator=(const Character& src); //cascading
        Character& operator=(Character&& src);      //cascading

        void add_Name   (string name);
        void add_Health (int health);
        void add_Tool_Count (int tool_count); //Should not be used
        void add_Tool   (int pos, string tool_name);
        void display_character () const ;
        static void display_total_player_number ();
        //static void add_map (string map_name);
        static void display_map_name();

        friend ostream& operator<<(ostream& os, const Character& src);
        friend void Host_change_map (string map_name);
};



int Character::players_on_server=0;