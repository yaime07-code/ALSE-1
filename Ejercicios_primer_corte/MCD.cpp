#include <iostream>
#include <cmath> 

using namespace std;

int mcd(int a, int b) {
    
   while (a!=0 && b!=0) {
        int m = b;
        b = a % b;
        a = m;
    }
    return a;
}

int main() {
    int a, b;

    cout << "Ingrese el primer numero: ";
    cin >> a;

    cout << "Ingrese el segundo numero: ";
    cin >> b;

    cout << "El MCD de " << a << " y " << b << " es: " << mcd(a, b) << endl;

    return 0;
}