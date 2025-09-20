#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    double P, r, A;
    int n, t;

    cout << "Ingrese el capital inicial (P): ";
    cin >> P;

    cout << "Ingrese la tasa de interes anual en decimal (ej: 0.05 para 5%): ";
    cin >> r;

    cout << "Ingrese el numero de veces que se aplica el interes al año (n): ";
    cin >> n;

    cout << "Ingrese el numero de años (t): ";
    cin >> t;

    // Fórmula del interés compuesto
    A = P * pow((1 + r / n), n * t);

    cout << "El monto final (A) es: " << A << endl;

    return 0;
}
