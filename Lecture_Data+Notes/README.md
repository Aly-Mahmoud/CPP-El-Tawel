# **CPP El-Taweel**

# Lecture 1



## 1.Class

1. **Definition**: A class is a blueprint for creating objects. It defines the properties (data members) and behaviors (member functions) that objects of that class will have.
2. **Memory Location**: The class definition itself is typically stored in the program's code segment (also known as the text segment). This segment contains the executable code of the program.
3. **When It's Saved**: The class definition is compiled into the program during the compilation process. It exists in the program's code even before any objects of that class are created.

## 2.Objects

1. **Instance of a Class**: An object is an instance of a class. It represents a specific instance of the data and behavior defined by the class.

2. **Memory Location**: When an object is created, memory is allocated to store its data members. The size of the memory allocated is determined by the size of the object, which depends on the size of its data members and any additional overhead.

3. **When It's Saved:**

    Objects are created during runtime, typically on the stack or the heap, depending on how they are created.

   - **Stack Allocation**: If an object is created as a local variable within a function or as a function parameter, it's usually allocated on the stack. When the function goes out of scope or returns, the memory for these objects is automatically deallocated.
   - **Heap Allocation**: If an object is created using dynamic memory allocation (e.g., `new` keyword), it's allocated on the heap. The programmer is responsible for deallocating this memory using `delete` when it's no longer needed to avoid memory leaks.

## 3.Constructor

->  it's a (special function = special method)
-> purpose: is to initialize the newly created object.
->  you can create it, if you did not compiler will and will give the constructor function the same name as the <class>
->  you do not call it, it calls itself automatically when creating an (instance = object) 
->  has no return type, not even void
->  can be overloaded,  meaning you can have multiple constructors with different parameter lists within the same class.

**Different method to call copy constructor in main** 

```
MyClass obj1;            // Default constructor
MyClass obj2 = obj1;     // Copy constructor called for initialization
```

```
int x = 5;
int y{x};  // Copy constructor called for initialization
```

### 3.1Types of Constructor

####      3.1.1 Default constructor (Zero Argument Constructor)

-> A constructor that does not take from me any parameters
-> Called once when creating an instance from a class

####      3.1.2Parameterized Constructor (Overloaded Constructor)

​        -> many functions with the same name however they have different signatures-> anything after the name of the function like (Parameters, attributes)
​        -> this concept of similar name different signatures is called name mangling -> handled by compiler in different ways according to your compiler used
​        -> if you made a Parameterized Constructor it prevents the compiler to create the default constructor, so if you need it you must create it on your own

####      3.1.3 Copy Constructor

​        ->  it's a (special function = special method)
​        ->  you can create it, if you did not, compiler will, and will give the constructor function the same name as the <class>
​        ->  you do not call it, it calls itself automatically when copying an (instance = object)   player p2=p1;
​        -> **you should pass by refrence when calling copy constructor as if you pass by value you will enter infinite recursion** 
​	-> **Responsible for deep copying if the class contains dynamically allocated resources.**
​	-> **if you created multiple copies for an object of a class the first copy to be destroyed** 
​            will delete the ptr pointning to the data of the object copied making it's location accessible for other parts of the program
​            / making it unreserved memory



####      3.1.4 Delegating Constructor

​        -> **I'm lazy** : if you call me, I will call another constructor to do my job
​        -> **it's a good practice**, you make default values for objects even if you just called in 

####      3.1.5 Move Constructor /move semantics(C++)

​        ->  it's a (special function = special method).
​        ->  you can create it, if you did not compiler will use copy Constructor
​        ->  you do not call it, it calls itself automatically when giving a temp (instance = object).
​        -> used in moving ownership of the data from one object to another 
​        -> benefits of using Moving Constructor over Copy Constructor is better memory use 

​            **in case of copy constructor**  when obj2 is created by copying obj1. During this process, a temporary object is created to hold the copied data, and then obj2 is initialized using this temporary object. Finally, the temporary object is destroyed once the copy construction is complete.

​            **in case of move Constructor** the authority of data is transferred from one obj1 to obj2, that takes less processing time, consume less memory, overall saves resources.

```cpp
Mystring(Mystring &&src)
{
    str=src.str;
    src.str = nullptr;
}
```



### 3.2 Constructor Initialization list

```cpp
int x = 5;  // C like
int x (5);  // Constructor like
int x {5};  // uniform Initilization -> check between the two types of data (expected to send) & (what was actually send) ensure no casting happens
    int x = {5.3} -> error -> no casting will happen

int x; // reseve empty space in memory
x = 5; // assignation

    int x=5; //reservation & assignation in the same line
```

**Can i do the same in the class?**
 	Yes,

in the following code we **reserve & initialize** at the very beginning of the creating an **(object-instance)** of this class

```cpp
 Person () : name {"None"}, ID{"None"}
    {
        implementation
    }
```

​    if not in order it will allocate and then initialize

## 4. Destructor 

->  it's a (special function = special method)
->  you can create it, if you did not compiler will and will give the constructor function the same name as the class but preceded with telda **<~class>**
->  you do not call it, it calls itself automatically when destroying an (instance = object) 
-> destruction will happen when the program gets out of the scope of the object whether it was `}` or `return 0;`
->  has no return type
-> can not be overload

## 5. L-R Values

### 5.1 L-value:

**What**

An L-value refers to an expression that identifies a **memory location** and can be assigned a value. L-values are typically variables or objects that have a persistent identity and can appear on the left-hand side of an assignment operation, They represent persistent values that can be modified or accessed.

**Why**

L-values are commonly used when assigning values to variables or objects, modifying the state of objects, or **passing arguments to functions that expect references.**

**Example**

Variables, objects, array elements, dereferenced pointers, and references 

**How**

```cpp
int x;                                                 
int &obj = x   // creating an alias for an existing variable               
/* obj = x */                                          
                                                       
{                                                      
int &ref = x;                                          
ref = 50;                                              
}                                                      
                                                       
int &x = 200; //not valid   
```



### 5.2 R-value:

**What**

R-value refers to an expression that represents a temporary or transient value. R-values are typically temporary results of expressions, literals, or values that cannot be directly assigned to.

**Why**

R-values are commonly used in expressions, such as arithmetic operations, function calls, and initializations.

**Example**

 Literals (such as numbers or strings), temporary objects, the result of expressions, and the return value of functions are all examples of R-values.

**How**

```
int &&x=200;  //valid        as we extend it's life time untill the scope of x ends & created a refrence out of it so i can access it
cout<<x<<endl;

{
int &&Ref = 3;
Ref = 43;    
}
```

**How to use R-Values and L-Values:**

```
int main() 
{
    int x = 5; // 'x' is an L-value
    int y = x + 3; // 'x + 3' is an R-value expression
    int& ref = x; // 'ref' is an L-value reference
    // '5' is an R-value literal in the following line
    int z = 5 + 2; // '5 + 2' is an R-value expression

return 0;

}
```

# Lecture 2



## 6. Constant Object 

**What**

it's a type to be assigned to a Object

**Why**

I have important data that I do want it change across time of the program

**How**

    const Person p1 ( "Aly" , "1234" );
    
    void Person::display_info(void) const
    {
        std::cout <<"The name is :"<< name << std::endl;
        std::cout <<"The ID is :" << ID << std::endl;
        // the function is constant so i can not change any of the data of the class 
        // name = "Ahmed";
    }



## 7. Constant function

**What**

it's a type to be assigned to a function 
It promises not to modify the state of the object on which it is called.
Constant member functions can be called on constant objects, as well as on non-constant objects.

**Why**

in read function to ensure that no function to be called can change any data

**How**

    class MyClass
    {
    public:
        void display_info(void) const 
    	{
              std::cout <<"The name is :"<< name << std::endl; 
       		  std::cout <<"The ID is :" << ID << std::endl;
    		   // the function is constant so i can not change any of the data of the class 
        }
    };




## 8. Static variable 

**What**

It's a variable that is shared among the whole class and all of it's objects

**Why**

Global data across all the class

**How**

```cpp
class Person
{
    public:

        static int counts;         //declaration

};

int Person::counts =0;            //Initilization 

int main()
{
    std::cout<<"the value of the static variable that is shared among the whole class and all of it's objects is: "<<Person::counts<<endl;
    p1.counts = 5;
    std::cout<<"the value of the static variable that is shared among the whole class and all of it's objects is: "<<Person::counts<<endl;
    p2.counts++;
    std::cout<<"the value of the static variable that is shared among the whole class and all of it's objects is: "<<Person::counts<<endl;

                                    //Printing out the value of 

}
```



## 9. Static Function 

**What**

It's a functions that is shared among the whole class and all of it's objects and can access the static private data 
Static functions can be called using the class name, without needing to create an object of the class.

**Why**

They are typically used for utility functions or operations that do not require access to the non-static members of the class.

normally you won't be able to access private data however to be able to access private data
-> you can make it static variable.
-> you can access it through Static function.

**How** (try to run this code and see the results)

```cpp
#include <iostream>

class MyClass 
{
    private:
        static int count; // Static data member

    public:
        // Static function to increment the count
        static void incrementCount() 
		{
            count++; // Accessing and modifying the static data member
        }

        // Static function to get the current count
        static int getCount() 
		{
            return count; // Accessing the static data member
        }
};

// Initializing static data member outside the class definition
int MyClass::count = 0;

int main() 
{
    std::cout << "Initial count: " << MyClass::getCount() << std::endl;

    // Call the static function to increment the count
    MyClass::incrementCount();
    std::cout << "Count after increment: " << MyClass::getCount() << std::endl;

    // Call the static function to increment the count again
    MyClass::incrementCount();
    std::cout << "Count after second increment: " << MyClass::getCount() << std::endl;

    return 0;
}
```



## 10. this  pointer

**What**

it's a pointer that points to the data of the class, and of  the class only

**why**

it's the normal way to access your class data if you did not do it compiler will do it for you
it helps differentiate between local variables and class data

**How**

```
Person(std::string name, std::string ID) 
{ 
    this->name = name;
    this->ID = ID;
    std::cout<<"Constructor2 has been called"<<std::endl;
};

```

in case of operator overloading 

# Lecture 3

## 11. friend function/Class

**What**

A friend function in C++ is a function that is not a member of a class but has access to the private and protected members of that class. Friend functions are declared inside a class and preceded by the `friend` keyword. They can access private and protected members of the class as if they were regular member functions.

**Why**

Friend functions are useful in situations where a function needs to access private or protected members of a class, but it is not appropriate or possible to make that function a member of the class. Some common use cases for friend functions include:

1. **Accessing Private Data**: When a function needs to access private data members of a class to perform a specific operation.
2. **Non-member Function**: When a function logically belongs outside the class but still needs access to its private or protected members.
3. **Overloading Operators**: When overloading certain operators (such as `<<` or `>>`), friend functions are often used to allow the operator to access private members of a class.

**How to declare, implement, and use friend functions:** (try to run this code)

```C++
#include <iostream>

class MyClass {
private:
    int data;

public:
    MyClass(int d) : data(d) {}

// Declare friend function inside the class
friend void friendFunction(MyClass obj);

};

// Implement the friend function outside the class
void friendFunction(MyClass obj) {
    // Friend function can access private members of MyClass
    std::cout << "Friend function accessed private data: " << obj.data << std::endl;
}

int main() {
    MyClass obj(10);
    // Call the friend function
    friendFunction(obj);

return 0;

}
```



## **12**. operator overloading

**What**

-> Using traditional operators with user-defined data types.
 -> Allow user-defined data types to behave similarly to built-in types.
 -> Can make code more readable and writable.
->Not done automatically (except for the assignment operator).
-> They must be explicitly defined.

**Why**

-> Suppose that we have a Number class that models any number
 -->Using function

```
Number result = multiply(divide(a,b),divide(c,d));
```

-->Using operator overloading

```
 Number result = (a/b) * (c/d);
```

**Constraints:**

Some basic rules:

-> Precedence and Associativity can not be changed
->Polarity can not be changed
->Can not create new operators
-> Can not overload operators for primitive types

The following Operators can not be overloaded

```
::						//Scope resolution
:?						//Conditional Operator
.*						//Pointer to Member Operator
. 						//Dot Operator
sizeof					//Size of Operator
```

**How in the past**

```
class Company
{
    Private:

         int salaries;

     Public:

         Multiply (int Mul)
         {
             salaries*=Mul;
         }
         Divide (int dev)
         {
             salaries /= dev;
         }

};

int main 
{
    Company employee1;

    employee1.Multiple(10);
    employee1.Divide(10);

}
```



### Operator overloading types 

#### 1- Copy assignment operator

the compiler by default creates a Copy assignment operator the problem with this default copy assignment operator is that it makes a shallow copy operation 

if you want to make a deep copy version of it you have to implement one yourself 

```cpp
Mystring &operator= (const Mystring &src)
{
    //to avoid self copy
    if (this != &src)
    {
        delete[]str;                          // to free what this object had allocated before -> if i did not make this step won't it overwrite the previous data in the next step?
        str = new char [strlen(src.str)+1];   // allocate new space for the object data ? // why don't we allocate data normally when creating the object 
        strcpy(str,src.str);				// copying data from src to destination
    }
    return *this;              
}

```

```cpp
int main
{
P1=P2  // p1.operator=();
}
```

while the above piece of code is technically correct but it is not used and it violates the conventions 
a better way to implement Operator overloading is 

```cpp
<Classname> &operator= (const <classname> &source)
{
	//body

return *this
}
```

```cpp
int main 
{
	S1=S2=S3=S4  
}
```

this code follows the standard and enables the **chaining**
why did we use constant?
ask yourself in this situation when you are S2 = S1 for example, do you want the value of S1 to be changed by this operation, the answer should be no so you use constant to make sure that the value will not be changed.

#### **2-move assignment operation**

copy constructor copy or move, left and right values !!!!

```cpp
Mystring & operator= (Mystring &&src)
{
    //to avoid self movement 
    if (this != &src)
    {
        delete []str;   //deallocation of memory to be filled by the src data -> 3shan abd2 3la ndafa -> mn 8erha msh h overwrite? 
        str = src.str;  // assign data from source to the object calling this method
        src.str = nullptr; .
    }
}

```



# Lecture 4

#### 2. Arithmetic operator

##### 2.1 Unary Operator (++ , --)



**Constraints:** 
you can not overload it into binary 

##### 2.2 Binary

**Operation overloading for (-)**

```
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
```

**Operation overloading for (+)**

```
Mystring operator+ (const Mystring &rhs)
{
char *buffer = new char [std::strlen(str)+std::strlen(rhs.str)+1];  // hwa amta ast5m al this pointer?
std::strcpy(buffer,str);
std::strcat(buffer,rhs.str);
Mystring temp = Mystring(buffer);
delete[] buffer;
return temp;
}
```

**Operation overloading for (==)**



# Lecture 5

## Concepts of OOP 

#### Abstraction

#### Encapsulation

### Data hiding 

### Inheritance 

**Polymorphism**

#### What?

It's a method to create a class from an existing class with properties and characteristics and it gives me the ability to extend and modify.

#### Terminology 

**1-Base Class - Parent class - Superclass:**
class from which we inherit another class.

**2-Derived class - child class - Subclass** 
class that inherits from the Base class 

#### Why?



#### How?

```cpp
class A
{
private:
int x; 
public:
void display();
};

class B : public A
{
private:
int y;
public:
display_y();
};
```

**how is that mapped in the memory?**
data ( not functions ) of Class parents exist in memory whenever you create an instance of the class + whenever you create an instance of a child class from that parent 

when creating multiple instances of a class functions are not created multiple times however, they are created once and then the functions have a pointer pointing to it 

**Access modifiers:**
the default access modifier is **private**

![Access modifiers](.\Cache\Access_modifiers.png)

in struct default access modifier is **public** 

# Lecture 6

# Lecture 7

**note** function signature is the combination of function type, function name, and function parameters similar to function prototype, or API

### **Polymorphism** 

#### What ?

same function with different behavior ( **function overloading**, **Operator overloading** )

##### Polymorphism types 

###### Compile time Polymorphism - Static binding - early binding

Apply concept during compilation.

example

```C
#include <iostream>

class Account
{
private:    
    double balance;

public:
    void Withdraw()
    {
        std::cout <<"Account::Withdraw()" << std::endl;
    }
    void Deposite()
    {
        std::cout <<"Account::Deposite()" <<std::endl;
    }
};

class Saving : public Account 
{
    private:

    public :

    void Withdraw()
    {
        std::cout << "Saving:Withdraw()" << std::endl;
    }

    void Deposite()
    {
        std::cout << "Saving::Deposite" << std::endl;
    }

};

int main ()
{
    Account a;
    Saving b;
    a.Deposite();
    b.Deposite();

    Account *ptr = new Saving;
    ptr->Deposite();              // here the pointer will call the deposite of Deposite function of Account not the saving, as the ptr types is Account not Saving
    return 0;
}
```

###### Runtime Polymorphism - dynamic binding - late binding

Apply binding during runtime.

example

```
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
    void Withdraw()
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
    //Binding Binding -> 
    Account *ptr = new Saving; 
    ptr->Deposite();
    delete ptr;
    return 0;
}
```

#### V-Table , Virtual Table 

for each child class there is a v-table for the virtual functions 

#### V-Pointer 

created in the child class it's for the parent class, it points at the virtual function that can override the virtual function

**4 cases**

1-pointer from the parent class pointing to an object from the parent class too, it simply calls the function in the parent class

2- pointer from parent class pointing to object from child class, which function will be called using this pointer?
  i- if this function is a virtual function in the parent class, then the function in the child class is the one that will be called
  ii- if this function is NOT virtual in the parent class, then the function in the parent class is the one that will be called

3- pointer from child class pointing to object from parent class, well this is INVALID

4- pointer from child class pointing to object from child class too, it simply calls the function in the child class

#### **override Keyword** 

​	**for function**

```
derived class:
{ 
public:
 virtual void Withdraw() override
  {
    std::cout << "Saving:Withdraw()" << std::endl;
  }
}
```

it notifies you if the function which is meant to override another virtual function has found the virtual function to be overridden, it helps me to overcome typos errors

​	**for class** !!!!!!!!!!!!!

```
derived class: override f
{ 
public:
 virtual void Withdraw() override
  {
    std::cout << "Saving:Withdraw()" << std::endl;
  }
}
```

​	**override final Keyword**

```
derived class:
{ 
public:
 virtual void Withdraw() override final
  {
    std::cout << "Saving:Withdraw()" << std::endl;
  }
}
```

the withdraw function can not be overridden by any other function 

​	**for class** 

```
derived class: final
{ 
public:
 virtual void Withdraw() override
  {
    std::cout << "Saving:Withdraw()" << std::endl;
  }
}
```

any function inside this class can not be overridden 

#### **base class refrence**  !!!!!!!!!!!!

#### **Pure virtual function** 

```
virtual void pureVirtualFunction() = 0; // Pure virtual function
```

-> No implementation
-> 

#### **abstract class** 

-> it's a class that has at least **Pure Virtual function** it is good for abstraction of the code.
-> can not create object from this class.

#### **Interface class**

-> it's when a class has all **Pure Virtual function**
-> Can not create object from this class.

**Concrete class**

-> can create object from this class. 
-> have no pure virtual function.
