#include <iostream>
using namespace std;

class Base
{
	public:
		Base()
		{
			cout<<"Base Constructor" << endl;
		}
};

class Base1 :  public Base
{
	protected:
		int b;
	
	public:
		Base1()
		{
			cout<<"Base1 Constructor" << endl;
		}
};

class Base2 :  public Base
{
	protected:
		int c;

	public:
		Base2()
		{
			cout<<"Base2 Constructor" << endl;
		}
};

class Derived : public Base1 , public Base2
{
	public:
    	int d;
    
    int product()
    {
        return  b * c * d;
    }

	Derived()
	{
		cout<<"Derived Constructor" << endl;
	}

};

int main ()
{
	Derived d1;
	return 0;
}