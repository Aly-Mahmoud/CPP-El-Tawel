#include <iostream>

class Animal
{
private:    

public:

    virtual void Makesound()=0;

    virtual ~Animal()
    {
        std::cout << "Animal::V-destructor" <<std::endl;
    }


};

class Dog : public Animal 
{
    private:

    public :

    //override during runtime capability as the function with the same signature in the parent class is virtual
    virtual void Makesound() override
    {
        std::cout <<"Dog::Woof Woof()" << std::endl;
    }     

    ~Dog()
    {
        std::cout << "Dog::destructor" <<std::endl;
    }

};

class  Cat : public Animal
{
    private:

    public :

    virtual void Makesound() override
    {
        std::cout <<"Cat::Meow Meow()" << std::endl;
    } 

    ~Cat()
    {
        std::cout << "Cat::destructor" <<std::endl;
    }     
};

class bird : public Animal
{
    private:

    public :

    virtual void Makesound() override
    {
        std::cout <<"bird::Tweet Tweet()" << std::endl;
    } 

    ~bird()
    {
        std::cout << "bird::destructor" <<std::endl;
    }     
};

void make_sound(Animal & n)
{
    n.Makesound();
}


int main ()
{

    // Animal *ptr1 = new Cat;
    // Animal *ptr2 = new bird;

    // ptr1-> Makesound();
    // ptr2-> Makesound();

    // delete ptr1;
    // delete ptr2;

    Dog klb;
    Cat ota;

    make_sound(klb);
    make_sound(ota);   

    return 0;
}