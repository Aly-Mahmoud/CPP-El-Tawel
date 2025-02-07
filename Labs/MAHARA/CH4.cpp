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
            cout << "Constructor" << endl;
        }

        Complex (float number) : real(number), imag(number)
        {
            cout << "Constructor" << endl;
        }

        Complex (float Real, float Imag) : real {Real} , imag {Imag}
        {
            cout << "Constructor" << endl;
        }

        Complex (const Complex &C)
        {
            this->real = C.real;
            this->imag = C.imag;

            cout <<"Copy Constructor"<<endl;
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

        Complex operator+ (Complex c1)
        {
            Complex result;
            result.real = this->real + c1.real;
            result.imag = this->imag + c1.imag;

            return result;
        }

        Complex operator+ (float x)
        {
            Complex result;
            result.real = this->real + x;
            result.imag = this->imag;

            return result;
        }

        friend Complex operator+ (float x, Complex c)
        {
            Complex result;
            result.real = c.real + x;
            result.imag = c.imag;

            return result;
        }

        Complex operator- (Complex c1)
        {
            Complex result;
            result.real = this->real - c1.real;
            result.imag = this->imag - c1.imag;

            return result;
        }

        Complex operator- (float x)
        {
            Complex result;
            result.real = this->real - x;
            result.imag = this->imag;

            return result;
        }

        friend Complex operator- (float x, Complex c)
        {
            Complex result;
            result.real = x - c.real;
            result.imag = c.imag;

            return result;
        }

        Complex operator++ ()
        {
            this->real++;
            this->imag++;

            return *this;
        }

        Complex operator++ (int)
        {
            Complex C1;

            this->real++;
            this->imag++;

            return C1;
        }

        Complex operator-- ()
        {
            this->real--;
            this->imag--;

            return *this;
        }

        Complex operator-- (int)
        {
            Complex C;

            this->real--;
            this->imag--;

            return C;
        }

        void operator+= (Complex c1)
        {
            this->real += c1.real;
            this->imag += c1.imag;
        }

        void operator-= (Complex c1)
        {
            this->real -= c1.real;
            this->imag -= c1.imag; 
        }

        int operator == (Complex c)
        {
            if (this->real == c.real && this->imag == c.imag)
            {
                return 1;
            }
            return 0;
        }

        int operator() (float)
        {
            return this->real;
        }

        ~Complex ()
        {
            cout <<"destructor is called" <<endl;
        }

        void display ()
        {
            cout << "Real : " << this->real << endl;
            cout << "Imag : " << this->imag << endl;
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
    Complex C1(5,5);
    C1.display ();

    Complex C2(5,10);
    C2.display ();

    Complex C3 = C1+C2;
    C3.display();

    C3 = C1-C2;
    C3.display();

    C3 = C1+5;
    C3.display();

    C3 = C1-5;
    C3.display();

    C3 = 5-C1;
    C3.display();

    C3 = 5+C1;
    C3.display();

    C3-=C1;
    C3.display();

    C3+=C1;
    C3.display();

    C3++;
    C3.display();

    C3--;
    C3.display();

    cout << (C1==C2) << endl;


    return 0;
}