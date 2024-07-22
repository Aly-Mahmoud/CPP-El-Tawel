#include <iostream>
#include <cstring>


using namespace std;

class Mystring
{
    private:
        char *str;

    public:

            //defult constructor
            Mystring()
            {
                str = new char('\0');
            }

            //Move constructor
            Mystring(Mystring &&src)
            {
                str=src.str;
                src.str = nullptr;
            }

            //Move Assigment operator
            Mystring & operator= (Mystring &&src)
            {
                //to avoid self movement 
                if (this != &src)
                {
                    delete []str;
                    str = src.str;
                    src.str = nullptr;
                }
            }

            //Parameterized constructor 
            Mystring(char *src)  
            {
                str = new char [strlen(src)+1];
                strcpy(str,src);
            
            }

            //copy constructor operator
            Mystring(const Mystring &src)
            {
                str = new char [strlen(src.str)+1];
                strcpy(str,src.str);
            }

            //copy assignment operator
            Mystring &operator= (const Mystring &src)
            {
                //to avoid self copy
                if (this != &src)
                {
                    delete[]str;                          // to free what this object had allocated before
                    str = new char [strlen(src.str)+1];
                    strcpy(str,src.str);
                }
                    return *this;              
            }

            //destructor
            ~Mystring()
            {
                delete[]str;
            }

            void display_info() const
            {
                // std::cout <<"The name is :"<< name << std::endl;
                // std::cout <<"The ID is :" << ID << std::endl;
            }

            int get_length() const
            {

            }
};

int main (void)
{

    Mystring S1 {"Ahmed"};
    Mystring S2 = "Mohamed";
    
    S2 = S1;

return 0;
}
