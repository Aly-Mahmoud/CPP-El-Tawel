#include <iostream>

using namespace std;

class Integer
{
    private:

        int *ptr;

    public:

        //Default Constructor 
        Integer()
        {
            ptr = new int;
            cout << " Integer: Default Constructor " << endl;
        }

        //Paramtarized Constructor
        Integer (int *src)
        {
           ptr = src;
           cout << " Integer: Paramtarized Constructor " <<endl;
        }

        //Copy Constructor
        Integer (const Integer &src)       
        {
            if (src.ptr != nullptr) 
            {
                ptr = new int(*src.ptr);    //Deep Copy
            }
            else 
            {
                ptr = nullptr;
            }

            cout << " Integer: Copy Constructor " << endl;            
        }

        //Move Constructor 
        Integer ( Integer &&src )
        {
            ptr = src.ptr;
            src.ptr = nullptr;
            cout << " Integer: Move Constructor " << endl;
        }

        //Copy assigment operator 
        Integer & operator= ( const Integer &src )
        {
            if (this != &src) // to avoid self assigning
            {
                delete ptr;
                if (src.ptr != nullptr) // to avoid segmentation fault when assiging data to a nullptrr
                {
                    ptr = new int (*src.ptr);
                }
                else
                {
                    ptr = nullptr;
                }
            }
            return *this;
        }

        //Move assigment operator
        Integer& operator= ( Integer &&src )
        {
            if (this != &src)         // to aviod self assigning
            {
                delete ptr;
                if (src.ptr != nullptr)     // to avoid segmentation fault when assiging data to from nullptr
                {
                    ptr = src.ptr;
                    src.ptr = nullptr;
                    cout << "Intger &&" << endl;
                }
            }
            return *this;
        }

        // Overloading prefix increment operator (++num)
        Integer& operator++() 
        {
            ++(*ptr);
            return *this;
        }

        // Overloading postfix increment operator (num++)
        Integer operator++(int) 
        {
            Integer temp(*ptr);
            ++(*ptr);
            return temp;
        }

        void Set_Value(const int x)
        {
            *ptr = x;
            cout << "The Value is set by: " << x << endl;            
        }

        void Get_Value()
        {
            if ( ptr != nullptr )  // to check if the object still exist or not  or to check if the pointer inside that object still exist or not
            {
                cout << "The Value is: " << *ptr << endl;                              
            }
            else 
            {
                cout << " Such data does not exist " << endl;  
            }
        }

        //Destructor
        ~Integer()
        {
            delete ptr;            
            cout << " Integer: Destructor " << endl;
        }        
    protected:

};

int main()
{
    Integer I1;
    Integer I2;

    I1.Set_Value(5);
    I2.Set_Value(10);

    //I2 = I1;
    I2 = std::move(I1); 

    I1.Get_Value();

    I2.Get_Value();

    return 0;
}