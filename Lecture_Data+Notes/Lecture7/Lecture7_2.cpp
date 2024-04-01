#include <iostream>

class Shape
{
private:    

    int dimention;

public:

    // Shape()
    // {
    //     std::cout << ""
    // }

    // Shape(int x)
    // {
    //     dimention = x;
    // };

    // a function used to be able to implemnt dynmaic binding, it can be overriden by other function in an inherted class during runtime
    virtual void Calculate_Area()
    {
        std::cout <<"Shape::Calculate_Area()" << std::endl;
    }

    // ~Shape()
    // {
    //     std::cout << "Shape::destructor" <<std::endl;
    // }

    // if you have virtual function you must have virtual destructor other wise you would have undefined behvior 
    virtual ~Shape()
    {
        std::cout << "Shape::V-destructor" <<std::endl;
    }


};

class Circle : public Shape 
{
    private:

        int diameter;

    public :

    // Circle (int d)
    // {
    //     diameter = d;
    // }
    //override during runtime capability as the function with the same signature in the parent class is virtual
    void Calculate_Area()
    {
        std::cout <<"Circle::Calculate_Area()" << std::endl;
        //return 3.14*diameter;
    }     

    ~Circle()
    {
        std::cout << "Circle::destructor" <<std::endl;
    }

};

class Rectangle : public Shape
{
    private:

        int Length;
        int Width;

    public :

    void Calculate_Area()
    {
        //Area = 
        std::cout <<"Rectangle::Calculate_Area()" << std::endl;
        //return Length*Width;
    } 

    ~Rectangle()
    {
        std::cout << "Rectangle::destructor" <<std::endl;
    }     
};


int main ()
{

    Shape *ptr1 = new Circle;
    Shape *ptr2 = new Rectangle;

    ptr1-> Calculate_Area();
    ptr2-> Calculate_Area();

    delete ptr1;
    delete ptr2;
    return 0;
}