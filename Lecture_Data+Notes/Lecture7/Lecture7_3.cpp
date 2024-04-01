#include <iostream>

class Account
{
private:    
    double balance;

public:
    // a function used to be able to implemnt dynmaic binding, it can be overriden by other function in an inherted class during runtime
    virtual void Withdraw()
    {
        std::cout <<"Account::Withdraw()" << std::endl;
    }
    virtual void Deposite()
    {
        std::cout <<"Account::Deposite()" <<std::endl;
    }

    // ~Account()
    // {
    //     std::cout << "Account::destructor" <<std::endl;
    // }

    // if you have virtual function you must have virtual destructor other wise you would have undefined behvior 
    virtual ~Account()
    {
        std::cout << "Account::destructor" <<std::endl;
    }


};

class Saving : public Account 
{
    private:

    public :
    //override during runtime capability as the function with the same signature in the parent class is virtual
    virtual void Withdraw() override
    {
        std::cout << "Saving:Withdraw()" << std::endl;
    }

    void Deposite()
    {
        std::cout << "Saving::Deposite" << std::endl;
    }

    ~Saving()
    {
        std::cout << "Saving::destructor" <<std::endl;
    }

};

class Trusted : public Account
{
    private:

    public :

    void Withdraw()
    {
        std::cout << "Trusted:Withdraw()" << std::endl;
    }

    void Deposite()
    {
        std::cout << "Trusted::Deposite" << std::endl;
    }   

    ~Trusted()
    {
        std::cout << "Trusted::destructor" <<std::endl;
    }     
};
// the old way 
void change_balance(Account *acc)
{
    acc -> Withdraw();
    acc -> Withdraw();
}

int main ()
{
    //Account a;
    //Saving b;
    //Static binding -> compile time polymorphism
    //a.Deposite();
    //b.Deposite();
    //Binding Binding -> 
    Account *ptr = new Saving; 
    //ptr->Deposite();
    delete ptr;
    return 0;
}