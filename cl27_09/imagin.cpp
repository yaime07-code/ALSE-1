#include <iostream>
using namespace std;

class Complex
{
    double real, imag;

public:
    Complex(double r, double i) : real(r), imag(i)
    {
        /* real = r;
        imag = i; */
    }
    // Overloading the '+' operator
    Complex operator+(const Complex &other)
    {        
        return Complex(real + other.real, imag + other.imag);
    }
    void setReal(double r)
    {
        real = r;
    }
    void setImag(double i)
    {
        imag = i;
    }
    double getReal(){
        return real;
    }
    double getImag(){
        return imag;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(3, 4), c2(1, 2);
    //c1.real = 8;
    c1.setReal(8);
    c1.display();
    c2.display();
    cout<<"Real: "<<c2.getReal()<<endl;
    Complex sum = c1 + c2;
    sum.display();
    return 0;
}