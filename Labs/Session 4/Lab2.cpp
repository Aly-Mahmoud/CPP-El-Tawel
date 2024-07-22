#include <iostream>
using namespace std;
#include "Dog.hpp"


int main (void)
{
    Dog d1;
    //d1.set_name ("Rex");
    //d1.set_age (2);

    string Dog_name = d1.get_name();
    std::cout <<"Dog Name is : "<<Dog_name<<std::endl;
    int Dog_age = d1.get_age();
    std::cout <<"Dog age is : "<<Dog_age<<std::endl;
    int Dog_age_Dog = d1.get_dog_years();
    std::cout <<"Dog age is in Dog years : "<<Dog_age_Dog<<std::endl;

    string Dog_Sound = d1.speak ();
    std::cout <<"The Dog sound is : "<<Dog_Sound<<std::endl;

}