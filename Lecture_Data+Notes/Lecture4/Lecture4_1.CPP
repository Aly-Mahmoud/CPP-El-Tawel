#include <iostream>
#include <cstring>


using namespace std;



class Mystring
{
    private:
        char *str;
        friend Mystring operator+ (const Mystring &lhs,const Mystring &rhs);
        friend std::ostream & operator<<(std::ostream &output,const Mystring &obj);

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
                return *this;
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

            //overloading (-) operator 
            Mystring operator- ()
            {
                char *buffer = new char [std::strlen(str)+1];
                std::strcpy(buffer,str);
                for (size_t i=0 ; i<strlen(str) ; ++i )
                {
                    buffer[i] = std::tolower(str[i]);
                }
                Mystring temp = Mystring(buffer);
                delete[] buffer;
                return temp;
            }

            // //overloading (+) operator 
            // Mystring operator+ (const Mystring &rhs)
            // {
            //     char *buffer = new char [std::strlen(str)+std::strlen(rhs.str)+1];  // hwa amta ast5m al this pointer?
            //     std::strcpy(buffer,str);
            //     std::strcat(buffer,rhs.str);
            //     Mystring temp = Mystring(buffer);
            //     delete[] buffer;
            //     return temp;
            // }

            //overload the operator ==
            bool operator == (const Mystring&rhs)
            {
                return (std::strcmp(this->str,rhs.str)==0);
            }

            //destructor
            ~Mystring()
            {
                delete[]str;
            }

            void display_info() const
            {
                std::cout <<"string value :"<< str << std::endl;
            }

};


//global function ... not related to any class
Mystring operator+ (const Mystring &lhs,const Mystring &rhs)
{
    char *buffer = new char [std::strlen(lhs.str)+std::strlen(rhs.str)+1]; 
    std::strcpy(buffer,lhs.str);
    std::strcat(buffer,rhs.str);
    Mystring temp = Mystring(buffer);
    delete[] buffer;
    return temp;
}

//overload for the insertion operator
std::ostream & operator<<(std::ostream &output,const Mystring &obj)
{
    output <<" The String in the class is "<<obj.str;
    return output;
}

int main (void)
{

    Mystring S1 {"ALY"};
    Mystring S2; 
    S2 = -S1;                 // convert the string into lower case
                              // covert the object and update itself with lowercase    

    S1.display_info();
    S2.display_info();

    Mystring S3;
    S3 = S1+S2;          //overloading the + operator //|Transled to -> S1.str(S2)
    
    S3.display_info();

    Mystring S4;

    S4 = S3;

    if (S1 == S2)
    {
        cout << "The two strings are different " << endl;
    }

    cout << S1 <<endl;;             // we want to overload the insertion operator
                                    // we can not implement memeber operator for insertion and extraction
                                    // 
return 0;
}
