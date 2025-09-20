#include <iostream>
using namespace std;

int main() {
    int numeros[5];
    cout << "Ingresa 5 numeros enteros:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }


    int suma = 0;
    for (int i = 0; i < 5; i++) {
        suma += numeros[i];
    }


    cout << "La suma de los elementos es: " << suma << endl;

    return 0;
}
