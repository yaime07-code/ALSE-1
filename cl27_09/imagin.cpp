#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {
            /* real =r;
            imag= i;*/
    }
    // Overload + operator to add two Complex objects
    Complex operator + (const Complex& obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void setReal(double r) { 
        real = r; 
    }
    void getReal() { 
        return real;
     }
     void display() {
        cout << real << " + i" << imag << endl;
     }
     int main(){
        Complex c1(3, 4), c2(1, 2);
        //c1.real =8;
        c1.setReal(8);
        c1.display();
        c2.display();
        cout<<"Real: "<<c2.getReal()<<endl;
        Complex sum = c1 + c2; // An example call to "operator+()"
        sum.display();
        return 0;
     }
}