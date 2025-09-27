#include <iostream>
#include <cmath>
using namespace std;

struct Complejo {
float real;
float imag;
};

// Funciones auxiliares
float magnitud(Complejo c) {
return sqrt(c.real * c.real + c.imag * c.imag);
}

float angulo(Complejo c) {
return atan2(c.imag, c.real) * 180.0 / M_PI;  // en grados
}

// División de complejos: (a+bi) / (c+di)
Complejo division(Complejo a, Complejo b) {
Complejo res;
float denom = b.real * b.real + b.imag * b.imag;
res.real = (a.real * b.real + a.imag * b.imag) / denom;
res.imag = (a.imag * b.real - a.real * b.imag) / denom;
return res;
}

// Producto de complejos: (a+bi) * (c+di)
Complejo multiplicacion(Complejo a, Complejo b) {
Complejo res;
res.real = (a.real * b.real) - (a.imag * b.imag);
res.imag = (a.real * b.imag) + (a.imag * b.real);
return res;
}

// Suma de complejos
Complejo sumaC(Complejo a, Complejo b) {
return {a.real + b.real, a.imag + b.imag};
}

// Paralelo: (Z1 * Z2) / (Z1 + Z2)
Complejo paralelo(Complejo z1, Complejo z2) {
return division(multiplicacion(z1, z2), sumaC(z1, z2));
}

int main() {
Complejo num1, num2, suma, resta, producto, z_paralelo;

```
cout << "Ingrese la parte real del primer numero complejo: ";
cin >> num1.real;
cout << "Ingrese la parte imaginaria del primer numero complejo: ";
cin >> num1.imag;
cout << "Ingrese la parte real del segundo numero complejo: ";
cin >> num2.real;
cout << "Ingrese la parte imaginaria del segundo numero complejo: ";
cin >> num2.imag;

// Operaciones
suma = sumaC(num1, num2);

resta.real = num1.real - num2.real;
resta.imag = num1.imag - num2.imag;

producto = multiplicacion(num1, num2);

z_paralelo = paralelo(num1, num2);

// Resultados en forma rectangular
cout << "\n--- Forma rectangular ---\n";
cout << "Suma: " << suma.real << " + " << suma.imag << "i" << endl;
cout << "Resta: " << resta.real << " + " << resta.imag << "i" << endl;
cout << "Producto: " << producto.real << " + " << producto.imag << "i" << endl;
cout << "Paralelo: " << z_paralelo.real << " + " << z_paralelo.imag << "i" << endl;

// Resultados en forma fasorial (polar)
cout << "\n--- Forma fasorial (r ∠ θ°) ---\n";
cout << "Num1: " << magnitud(num1) << " ∠ " << angulo(num1) << "°" << endl;
cout << "Num2: " << magnitud(num2) << " ∠ " << angulo(num2) << "°" << endl;
cout << "Suma: " << magnitud(suma) << " ∠ " << angulo(suma) << "°" << endl;
cout << "Resta: " << magnitud(resta) << " ∠ " << angulo(resta) << "°" << endl;
cout << "Producto: " << magnitud(producto) << " ∠ " << angulo(producto) << "°" << endl;
cout << "Paralelo: " << magnitud(z_paralelo) << " ∠ " << angulo(z_paralelo) << "°" << endl;

return 0;
```

}
