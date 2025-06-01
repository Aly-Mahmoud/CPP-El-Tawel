#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using namespace std;

class Session
{
    private:
        int *IP;
        int size;

    public:
        explicit  Session(int n = 0) : size(n) 
        {
            cout << "Session constructor of size : " << size << endl;
            IP = new int[size];
            cout << "constructor of IP : "<< IP << endl;
        }

        void set_ip (float ip, int position)
        {
            if (position > size)
            {
                cout << "Error: Position > size" << endl;
            }
            else
            {
                IP[position] = ip;
            }
        }

        Session (Session &s)
        {
            cout << "Copy Construtor" << endl;

            this->size = s.size;
            this->IP = new int [this->size];

            for(int i=0; i<this->size; i++)
            {
                this->IP[i] = s.IP[i];
            }
            
        }

        Session (Session &&s) 
        {
            cout << "Move construtor" << endl;
            this->size = s.size;
            this->IP = new int [this->size];
            s.IP = nullptr;
        }

        Session& operator= (Session &s1) // this=s1; 
        {
            cout << "Copy assignmnet" << endl;
            this->size = s1.size;

            delete [] this->IP;
            this->IP = new int [this->size];

            for (int i = 0; i < size ; i++)
            {
                this->IP[i] = s1.IP[i];
            }

            return *this;
        }

        Session& operator= (Session &&src) // this=src;
        {
            cout << "Move assignmnet " << endl;
            this->size = src.size;
            delete []IP;
            this->IP = src.IP;
            src.IP = nullptr;

            return *this;
        }

        ~Session ()
        {
            cout<<"Destructor is called of size :" << size <<endl;
            delete []IP;
        }
};

int main()
{
    Session S1 = (Session)100;

    char  x0 = 5;
    int x1 = 500;

    x0 = x1;

    cout << "x0 : " << sizeof(x0) << endl;
    cout << "x1 : " << sizeof(x1) << endl;
    cout << x0 << endl;

    return 0;
}

