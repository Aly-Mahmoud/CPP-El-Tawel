#include <iostream>
using namespace std;

class Stack 
{
    private:
        int top;
        int size;
        int *ptr;
        static int counter;

    public:
        Stack(int n = 10) : size(n)
        {
            top = 0;
            ptr = new int [size];
            counter++;

            cout <<"This is constructor" << endl;
        }

        // Stack (const Stack &S)
        // {
        //     if (size!=0)
        //     {
        //         ptr = new int [S.size];
        //         size = S.size;
        //         top = S.top;
        //         for (int i=0; i<top; i++)
        //         {
        //             ptr[i] = S.ptr[i];
        //         }
        //         counter++;
        //     }

        //     cout << "Copy constructor is called" <<endl;
        // }

        int isFull()
        {
            return (top == size);
        }

        int isEmpty()
        {
            return (top == 0);
        }

        static int getCounter()
        {
            return counter;
        }

        int push(int n)
        {
            if (!isFull())
            {
                ptr[top] = n;
                top++;
                return true;            
            }
            return false;
        }

        int pop(int &n)
        {
            if (!isEmpty())
            {
                top--;
                n = ptr[top];
                return true;
            }
            return false;
        }

        ~Stack()
        {
            delete[] ptr;
            cout << "Destructor called" << endl;
            counter--;
        }

        friend void viewContent (const Stack s1)
        {
            for (int i=0 ; i<s1.top; i++)
            {
                cout << "the value of element " << i << " is: " <<s1.ptr[i] << endl;
            }
            // call destructor
        }

        // friend void viewContent (const Stack &s1)
        // {
        //     for (int i=0 ; i<s1.top; i++)
        //     {
        //         cout << "the value of element " << i << " is: " <<s1.ptr[i] << endl;
        //     }
        // }

};

int Stack::counter =0;

int main ()
{
    Stack s1(5);

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    viewContent(s1);

    int pop_v = 0;
    s1.pop(pop_v);
    s1.pop(pop_v);

    viewContent(s1);

    s1.pop(pop_v);

    return 0;
}