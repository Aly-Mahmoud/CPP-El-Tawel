#include <iostream>
#include <cmath>

using namespace std;

class Complex 
{
    private:
        float real;
        float imag;

    public:

        Complex () : real(0), imag(0)
        {

        }

        Complex (float number) : real(number), imag(number)
        {

        }

        Complex (float Real, float Imag) : real {Real} , imag {Imag}
        {

        }

        void print ()
        {
            (imag<0)? 
            (cout << this->real << "-" << fabs(this->imag) << "i" <<endl)
            :
            (cout << this->real << "+" << this->imag << "i" <<endl);             
        }

        void set (float real, float imag)
        {
            this->real = real;
            this->imag = imag;
        }

        float getReal ()
        {
            return this->real;
        }

        float getImag ()
        {
            return this->imag;
        }

        ~Complex ()
        {
            cout <<"destructor is called" <<endl;
        }
};

Complex add (Complex C1, Complex C2)
{
    float real_1 = C1.getReal();
    float imag_1 = C1.getImag();

    float real_2 = C2.getReal();
    float imag_2 = C2.getImag();

    Complex temp = Complex ( real_1+real_2 , imag_1+imag_2 );

    return temp;
}

Complex subtract (Complex C1, Complex C2)
{
    float real_1 = C1.getReal();
    float imag_1 = C1.getImag();

    float real_2 = C2.getReal();
    float imag_2 = C2.getImag();

    Complex temp = Complex ( real_1-real_2 , imag_1-imag_2 );

    return temp;
}

int main() 
{
    Complex myCompl(5,5);
    Complex myComp2(5,10);
    Complex resultComp;

    myCompl.print();
    myComp2.print();

    resultComp = add (myCompl, myComp2); 

    resultComp.print();

    resultComp = subtract (myCompl, myComp2); 

    resultComp.print();

    return 0;
}