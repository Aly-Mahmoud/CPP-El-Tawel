#include <iostream>
#include <math.h>

using namespace std;

class Shape
{
    protected:
        float d1;
        float d2;

    public:
        Shape (float D1 = 0, float D2 = 0) : d1(D1), d2(D2) 
        {}

        void setDimi_1(float D1)
        {
            d1 = D1;
        }

        void setDimi_2(float D2)
        {
            d2 = D2;
        } 

        float getDimi_1 ()
        {
            return d1;
        }

        float getDimi_2 ()
        {
            return d2;
        }

        virtual float Area()=0;
};

class Triangle : public Shape
{
    public:
        Triangle (float base = 0, float height = 0) : Shape(base,height)
        {
        } 

        float Area() override final
        {
            return (0.5*d1*d2);
        }
};

class Rectangle : public Shape
{
    public:
        Rectangle(float D1 = 0, float D2 = 0) 
        {
            d1 = D1;
            d2 = D2;
        }

        float Area() override
        {
            return (d1*d2);
        }
};

class Square : private Rectangle
{
    private:
        float d1;

    public:
        Square( float D1 = 0)
        {
            d1 = D1;
        }

        void setDimi(float D1)
        {
            d1 = D1;
        }

        float getDimi()
        {
            return d1;
        }

        float Area() override final
        {
            return Rectangle::Area(); // return (d1*d1);
        }
};

class Circle : private Shape
{
    public:
        Circle (float R = 0) : Shape(R)
        {}

        void setR (float r)
        {
            d1 = r;
        }

        float getR ()
        {
            return d1;
        }

        float Area() override final
        {
            return ((22.0/7.0)*d1*d1) ;
        }
};

float Calc_Area (Shape* Ptr_1 , Shape* Ptr_2 )
{
    float area_1 =  Ptr_1->Area();
    float area_2 = Ptr_2->Area();

    cout << "Area : " << area_1+area_2 << endl;
}

int main ()
{
    Triangle T;
    Square S;
    Rectangle R;
    Circle C;

    Shape* T_ptr = &T;
    T_ptr->setDimi_1(1);
    T_ptr->setDimi_2(2);

    // Shape* S_ptr = &S;

    Shape* R_ptr = &R;
    R_ptr->setDimi_1(2);
    R_ptr->setDimi_2(2);

    // Shape* C_ptr = &C;

    Calc_Area ( T_ptr , R_ptr );
    
    return 0;
}