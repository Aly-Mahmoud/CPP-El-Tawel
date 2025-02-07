#include <string>
#include <iostream>

using namespace std;

class Person 
{
    private: 
        string Name;
        int Age;
        string* Tool; // Pointer to dynamically allocate an array of strings
        int ToolCount;

    public:
        Person () : Person (0)
        {
            cout << "Delgating to parametrized"<<endl;
        }

        Person(int toolCount) : Name("NULL"), Age(0), ToolCount(toolCount)
        {
            cout << "This is a paramertized constructor" << endl;
            Tool = new string[ToolCount]; // Allocate an array of strings
            for (int i = 0; i < ToolCount; ++i)
            {
                Tool[i] = "";
            }
            cout << "Dynamic allocation for tools completed with " << ToolCount << " tools." << endl;
        }

        Person (const Person &other)
        {
            Name = other.Name;
            Age = other.Age;
            ToolCount = other.ToolCount;
            Tool = new string[ToolCount];
            for (int i = 0 ; i < ToolCount ; i++)
            {
                Tool[i] = other.Tool[i];
            }
        }

        Person (Person&& other) noexcept
        {
            Name = other.Name;
            Age = other.Age;
            ToolCount = other.ToolCount;
            Tool = other.Tool;

            other.Tool = NULL;
            cout << "Move Constructor has been called" <<endl;
        }

        void displaytool()
        {
            cout << "The tool is : " << Tool[0] << " The length of the tool is " << Tool[0].length() << endl;
            cout << "The tool is : " << Tool[1] << " The length of the tool is " << Tool[1].length() << endl;
            cout << "The tool is : " << Tool[2] << " The length of the tool is " << Tool[2].length() << endl;
        }
        
        void add_Tool (int tool_number, string tool_name)
        {
            Tool[tool_number] = tool_name;
        }

        ~Person()
        {
            cout << "The default destructor is called" << endl;
            delete[] Tool;
        }
        
};

int main ()
{
    Person p1(3);

    p1.add_Tool(0,"Mina");
    p1.add_Tool(1,"Aly");
    p1.add_Tool(2,"El3aw");

    Person p2 = move(p1);
    cout << "The tools of 2nd person" << endl;
    p2.displaytool();

    // cout << "The tools of 1st person" << endl;
    // p1.displaytool();

    return 0;
}