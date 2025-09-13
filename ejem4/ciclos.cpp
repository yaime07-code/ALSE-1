#include <iostream>
using namespace std;

int main() {
    char userInput;
    int count = 0;

    cout << "CICLO WHILE" << endl;
    cout << "Ingrese 'y' para continuar o 'n' para salir:" << endl;
    cin >> userInput;

    // while: solo entra si el usuario ingresa 'y' o 'Y'
    while (userInput == 'y' || userInput == 'Y') {
        cout << "Contador vale: " << count << endl;
        count++;
        cout << "¿Deseas continuar (y/n)?: ";
        cin >> userInput;
    }

    cout << "\nCICLO DO-WHILE" << endl;
    count = 0; // reinicio el contador para este ciclo

    // do-while: se ejecuta al menos una vez
    do {
        cout << "Contador vale: " << count << endl;
        count++;
        cout << "Para continuar oprima 'q', para salir otra tecla: ";
        cin >> userInput;
    } while (userInput == 'q' || userInput == 'Q');

    cout << "\nSWITCH CON CODIGOS HTTP" << endl;

    short httpResponseCode = 200;
    cout << "Ingrese un CODE HTTP: ";
    cin >> httpResponseCode;
    switch (httpResponseCode) {
        case 200:
            cout << "OK" << endl;
            break;
        case 404:
            cout << "Not Found" << endl;
            break;
        case 500:
            cout << "Internal Server Error" << endl;
            break;
        default:
            cout << "Unknown Error" << endl;
            break;
    }

    cout << "\nMATRIZ 3x3" << endl;

    char matrix[3][3] = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'}
    };

    bool found = false;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Matrix [" << i << "][" << j << "]: " << matrix[i][j] << endl;
            if (matrix[i][j] == 'e') {
                found = true;
                break; // sale del ciclo interno
            }
        }

        if (found) break; // rompe también el ciclo externo
    }

    if (found)
        cout << "Se encontró la letra 'e' en la matriz." << endl;
    else
        cout << "No se encontró la letra 'e' en la matriz." << endl;

    return 0;
}
