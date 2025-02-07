#include <iostream>
using namespace std;

class Shape
{
    private:
        std::string color;

    public:
        Shape(std::string C = "") : color(C)
        {

        }

        void setColor (std::string& C) 
        {
           color  = C;
        }   
};

class Point : public Shape
{
    private:
        int x;
        int y;

    public:
        Point(int x1 = 0, int y1 = 0) : x{x1} , y{y1}
        {
            cout << " Point Constructor " << endl;
        }

        void setX(int x1)
        {
            x=x1;
        }

        void setY(int y1)
        {
            y=y1;
        }

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }

        Point (const Point& p)
        {
            x = p.x; 
            y = p.y;
            cout << "Copy construcotr has been called" << endl;
        }

        ~Point()
        {
            cout << "Point destructor" << endl;
        } 
};

class Line : public Shape
{
    private:
        Point start;
        Point end;

    public:

        Line (const Point &p1,const Point &p2) : start(p1) , end (p2)
        {
            cout << "Line Parametrized constructor with points" <<endl;
        }

        Line(int x1 =0, int y1 =0, int x2 =0, int y2 =0) : start(x1,y1) , end(x2,y2)
        {
            cout <<"Line construtor with int" <<endl;
        }

        void draw()
        {
            cout <<"Point coordinations : " <<endl;
            cout <<"Start :"<<"("<<start.getX() <<","<< start.getY() <<")"<< endl;
            cout <<"End : "<<"("<< end.getX() <<","<< end.getY() <<")"<<endl;
        }
};

class Rectangle : public Shape
{
    private:
        Point UpperLeft;
        Point LowerRight;

    public:
        Rectangle(int x1=0, int y1=0, int x2=0, int y2=0) : UpperLeft(x1,y1) , LowerRight(x2,y2)
        {
            cout <<"Rectangle Constructor" <<endl;
        }

        void draw()
        {
            cout <<"Rectangle coordiantions : " <<endl;
            cout <<"Upper Left point : "<<"("<<UpperLeft.getX() <<","<< UpperLeft.getY() <<")"<<endl;
            cout <<"Lower Right point : "<<"("<<LowerRight.getX() <<","<< LowerRight.getY() <<")"<<endl;
        }      

        ~Rectangle()
        {
            cout <<"Rectangle Destructor"<<endl;
        }
};

class Circle : public Shape
{
    private:
        Point Center;
        int radious;

    public:
        Circle (int m = 0, int n = 0 , int r = 0) : Center{m,n} , radious{r}
        {
            cout << "Circle Construtor" << endl;
        }

        void draw()
        {
            cout <<"Circle Coorinations : " << endl;
            cout <<"Center : (" << Center.getX() << "," << Center.getY() << ")" <<endl;
            cout <<"radious : " << radious << endl;
        }

        ~Circle()
        {
            cout << "Circle destructor" <<endl;
        }
};

class Picture
{
    private:
        int L_num;
        int R_num;
        int C_num;

        Line* line;
        Rectangle* rectagle;
        Circle* circle;

    public:
        Picture() : L_num(0), R_num(0), C_num(0), line(nullptr), rectagle(nullptr), circle(nullptr)
        {
            cout << "Picture constructor" <<endl;
        }

        void SetLines (int n, Line* l)
        {
            L_num = n;
            line = l;
        }

        void SetRectangles (int n, Rectangle* r)
        {
            R_num = n;
            rectagle = r;
        }

        void SetCircles (int n, Circle* c) 
        {
            C_num = n;
            circle = c;
        }   

        void print()
        {
            if (line != nullptr && L_num!= 0)
            {
                for (int i =0; i<L_num; i++)
                {
                    line[i].draw();
                }
            }

            if (rectagle != nullptr && R_num!=0)
            {
                for (int i =0; i<R_num; i++)
                {
                    rectagle[i].draw();
                }
            }

            if (circle != nullptr && C_num!=0)
            {
                for (int i=0; i<C_num; i++)
                {
                    circle[i].draw();
                }
            }
        }

        ~Picture()
        {
            cout << "Picture destructor" <<endl;
        }
};

int main ()
{
    Picture myPic;

    Line* lArr;
    lArr = new Line[2];
    lArr[0] = Line ( Point(420,50) , Point(300,300) );
    lArr[1] = Line (40,500,500,400);
    myPic.SetLines(2,lArr);


    Circle* cArr;
    cArr = new Circle[2];
    cArr[0] = Circle ( 3 , 2 , 10 );
    cArr[1] = Circle ( 6 , 4 , 20 );
    myPic.SetCircles(2,cArr);

    Rectangle* rArr;
    rArr = new Rectangle[2];
    rArr[0] = Rectangle();
    rArr[1] = Rectangle(1, 2, 3, 4);
    myPic.SetRectangles(2,rArr);

    myPic.print();

    delete[] lArr;
    delete[] cArr;
    delete[] rArr;
}