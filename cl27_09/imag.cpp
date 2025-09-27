#include <iostream>
using namespace std;

int main(){
    struct Complejo{
        float real;
        float imag;
    };

    Complejo num1, num2, suma, resta, producto;
    cout<<"Ingrese la parte real del primer numero complejo: ";
    cin>>num1.real;
    cout<<"Ingrese la parte imaginaria del primer numero complejo: ";
    cin>>num1.imag;
    cout<<"Ingrese la parte real del segundo numero complejo: ";
    cin>>num2.real;
    cout<<"Ingrese la parte imaginaria del segundo numero complejo: ";
    cin>>num2.imag;

    suma.real = num1.real + num2.real;
    suma.imag = num1.imag + num2.imag;

    resta.real = num1.real - num2.real;
    resta.imag = num1.imag - num2.imag;

    producto.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    producto.imag = (num1.real * num2.imag) + (num1.imag * num2.real);

    cout<<"Suma: "<<suma.real<<" + "<<suma.imag<<"i"<<std::endl;
    cout<<"Resta: "<<resta.real<<" + "<<resta.imag<<"i"<<std::endl;
    cout<<"Producto: "<<producto.real<<" + "<<producto.imag<<"i"<<std::endl;

    return 0;
}