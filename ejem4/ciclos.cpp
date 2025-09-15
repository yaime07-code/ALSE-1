#include <iostream>
using namespace std;

int main() {
    // Declaración de variables
    char userInput; // Almacena la respuesta del usuario
    int count = 0;  // Contador para los ciclos

    // --- CICLO WHILE ---
    cout << "CICLO WHILE" << endl;
    cout << "Ingrese 'y' para continuar o 'n' para salir:" << endl;
    cin >> userInput;

    /*
     * El ciclo while se ejecuta mientras el usuario ingrese 'y' o 'Y'.
     * En cada iteración, muestra el valor del contador y pregunta si desea continuar.
     * Si el usuario ingresa 'n' o cualquier otra tecla, el ciclo termina.
     */
    while (userInput == 'y' || userInput == 'Y') {
        cout << "Contador vale: " << count << endl; // Muestra el valor actual del contador
        count++;
        cout << "¿Deseas continuar (y/n)?: "; // Pregunta si desea continuar
        cin >> userInput;
    }

    // --- CICLO DO-WHILE ---
    cout << "\nCICLO DO-WHILE" << endl;
    count = 0; // Reinicia el contador para el ciclo do-while

    /*
     * El ciclo do-while se ejecuta al menos una vez, sin importar la condición inicial.
     * En cada iteración, muestra el valor del contador y pregunta si desea continuar.
     * Si el usuario ingresa 'q' o 'Q', el ciclo continúa; cualquier otra tecla lo termina.
     */
    do {
        cout << "Contador vale: " << count << endl; // Muestra el valor actual del contador
        count++;
        cout << "Para continuar oprima 'q', para salir otra tecla: "; // Indica cómo continuar o salir
        cin >> userInput;
    } while (userInput == 'q' || userInput == 'Q');

    // --- SWITCH CON CÓDIGOS HTTP ---
    cout << "\nSWITCH CON CODIGOS HTTP" << endl;

    short httpResponseCode = 200; // Variable para almacenar el código HTTP
    cout << "Ingrese un CODE HTTP: ";
    cin >> httpResponseCode;
    /*
     * El switch evalúa el código HTTP ingresado por el usuario.
     * Dependiendo del valor, muestra un mensaje correspondiente:
     * 200 -> OK
     * 404 -> Not Found
     * 500 -> Internal Server Error
     * Otro valor -> Unknown Error
     */
    switch (httpResponseCode) {
        case 200:
            cout << "OK" << endl; // Respuesta para código 200
            break;
        case 404:
            cout << "Not Found" << endl; // Respuesta para código 404
            break;
        case 500:
            cout << "Internal Server Error" << endl; // Respuesta para código 500
            break;
        default:
            cout << "Unknown Error" << endl; // Respuesta para cualquier otro código
            break;
    }

    // --- MATRIZ 3x3 ---
    cout << "\nMATRIZ 3x3" << endl;

    // Declaración e inicialización de una matriz de caracteres 3x3
    char matrix[3][3] = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'}
    };

    bool found = false; // Variable para indicar si se encontró la letra 'e'
    char flags = 0b0000'0011; // Ejemplo de uso de literales binarios

    /*
     * Recorre la matriz buscando la letra 'e'.
     * Si la encuentra, marca 'found' como true y sale de ambos ciclos.
     * Muestra el valor de cada celda de la matriz.
     */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Matrix [" << i << "][" << j << "]: " << matrix[i][j] << endl; // Muestra el valor de cada celda
            if (matrix[i][j] == 'e') {
                found = true; // Marca que se encontró la letra 'e'
                break; // Sale del ciclo interno
            }
        }
        if (found) break; // Sale del ciclo externo si se encontró
    }

    // Muestra el resultado de la búsqueda en la matriz
    if (found)
        cout << "Se encontró la letra 'e' en la matriz." << endl;
    else
        cout << "No se encontró la letra 'e' en la matriz." << endl;

    return 0; // Fin del programa
}
