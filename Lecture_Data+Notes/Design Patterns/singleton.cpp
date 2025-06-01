#include <iostream>

using namespace std;

class Singleton
{
    protected:
        Singleton() = default;

    public:

        int data;

        static Singleton& get_instance()
        {
            static Singleton instance;
            return instance;
        }

        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;
};

int main ()
{
    Singleton &singleton1 = Singleton::get_instance();

    cout << "data = " << singleton1.data << endl;;

    Singleton &singleton2 = Singleton::get_instance();

    singleton1.data = 20;

    cout << "data2 = " << singleton2.data << endl;

    return 0;
}