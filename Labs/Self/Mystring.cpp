#include "Mystring.hpp"
#include <iostream>

using namespace std;

Mystring::Mystring()
{
    cout << "Default constuctor has been called" << endl;
}

Mystring::Mystring(const char* s) 
{
    str = s;
}