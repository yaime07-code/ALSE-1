#include<iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;


class Figura {
private:
    int seleccion;

public:
    Figura(int opcion) {
        seleccion = opcion;
    }

    int getSeleccion() {
        return seleccion;
    }
    int setSeleccion(){
        if (1<=seleccion<=4){
            return seleccion;
        }
        else {
            cout << "El número no esta en las opciones" << endl;
        }
        
    }

    void mostrarFigura() {
        if (seleccion == 1)
            cout << "Has seleccionado un Círculo." << endl;
        else if (seleccion == 2)
            cout << "Has seleccionado un Cuadrado." << endl;
        else if (seleccion == 3)
            cout << "Has seleccionado un Rectángulo." << endl;
        else if (seleccion == 4)
            cout << "Has seleccionado un Triángulo." << endl;
        else
            cout << "Opción inválida." << endl;
    }
};
class Circulo{
    private: 
    double radio;
    public:
    Circulo (double r){
        radio =r;
    }
    double getRadio(){
        return radio;
    }
    double setRadio(){
        if (radio>0){
            return radio;
        }
        else{
            cout << "El radio debe ser positivo" << endl;
        }
    }
    double Area () const{
        return M_PI *(radio)*radio;
    }
    double Perimetro () const{
        return (2* M_PI *radio );
    }
    void medidas(){
        cout << "La medida del radio es "<< radio <<", su area es "<< Area() <<" y su perimetro es "<< Perimetro() << endl;
    }


};
class Cuadrado{
    private:
    double lado;
    public:
    Cuadrado (double l){
        lado = l;
    }
    double getLado(){
        return lado;
    }
    double setLado(){
        if (lado>0){
            return lado;
        }
        else{
            cout<< "El lado debe ser positivo" << endl;
        }
    }
    double Area () const{
        return lado * lado;
    }
    double Perimetro () const{
        return (4*lado);
    }
    void medidas(){
        cout << "La medida del lado es "<< lado <<", su area es "<< Area() <<" y su perimetro es "<< Perimetro() << endl;
    }


};
class Rectangulo{
    private:
    double base;
    double altura;
    public:
    Rectangulo (double b, double h){
        base = b ;
        altura = h ;
    }
    double getBase(){
        return base;
    }
    double getAltura(){
        return altura;
    }
    double setAltura(){
        if (altura>0){
            return altura;
        }
        else{
            cout<< "La altura debe ser positivo" << endl;
        }
    }
    double setBase(){
        if (base>0){
            return base;
        }
        else{
            cout << "la base debe ser positivo" << endl;
        }
    }
    double Area () const{
        return base * altura;
    }
    double Perimetro () const{
        return (2*base)+(2*altura);
    }
    void medidas(){
        cout << "La medida de la base es "<< base <<" su altura es "<< altura <<", su area es "<< Area() <<" y su perimetro es "<< Perimetro() << endl;
    }

};
class Triangulo{
    private:
    double base;
    double altura;
    double lado1;
    double lado2;
    public:
    Triangulo (double b, double a, double l1, double l2){
        base=b;
        altura=a;
        lado1=l1;
        lado2=l2;
    }
    double getBase(){
        return base;
    }
    double getAltura(){
        return altura;
    }
    double getLado1(){
        return lado1;
    }
    double getLado2(){
        return lado2;
    }
    double setBase(){
        if (base>0){
            return base;
        }
        else{
            cout << "la base debe ser positivo" << endl;
        }
    }
    double setAltura(){
        if (altura>0){
            return altura;
        }
        else{
            cout<< "La altura debe ser positivo" << endl;
        }
    }
    double setLado1(){
        if(lado1>9){
            return lado1;
        }
        else{
            cout<<"El lado 1 debe ser positivo" << endl;
        }
    }
    double setLado2(){
        if(lado2>9){
            return lado2;
        }
        else{
            cout<<"El lado 2 debe ser positivo" << endl;
        }
    }
    double Area () const{
        return (base * altura)/2;
    }
    double Perimetro () const{
        return base+lado1+lado2;
    }
    void medidas(){
        cout << "La medida de la base es "<< base <<" su altura es "<< altura<<" el lado 1 es "<<lado1 <<" el lado 2 es "<<lado2 <<", su area es "<< Area() <<" y su perimetro es "<< Perimetro() << endl;
    }

};
int main() {
    int seleccion;
    cout << "Selecciona una figura:" << endl;
    cout << "1. Círculo" << endl;
    cout << "2. Cuadrado" << endl;
    cout << "3. Rectángulo" << endl;
    cout << "4. Triángulo" << endl;
    cin >> seleccion;

    Figura figura(seleccion);
    figura.mostrarFigura();

    
    if (seleccion == 1) {
        double r;
        cout << "Ingresa el radio: ";
        cin >> r;
        Circulo c(r);
        c.medidas();
    }
    else if (seleccion == 2) {
        double l;
        cout << "Ingresa el lado: ";
        cin >> l;
        Cuadrado cu(l);
        cu.medidas();
    }
    else if (seleccion == 3) {
        double b, h;
        cout << "Ingresa la base: ";
        cin >> b;
        cout << "Ingresa la altura: ";
        cin >> h;
        Rectangulo r(b, h);
        r.medidas();
    }
    else if (seleccion == 4) {
        double b, a, l1, l2;
        cout << "Ingresa la base: ";
        cin >> b;
        cout << "Ingresa la altura: ";
        cin >> a;
        cout << "Ingresa el lado 1: ";
        cin >> l1;
        cout << "Ingresa el lado 2: ";
        cin >> l2;
        Triangulo t(b, a, l1, l2);
        t.medidas();
    }
    else {
        cout << "Opción no válida." << endl;
    }
    return 0;
}