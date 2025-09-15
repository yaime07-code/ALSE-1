#include <iostream>
using namespace std;


// --- Función que recibe un argumento por valor ---
// Las modificaciones dentro de la función NO afectan la variable original.
void byValue(int a)
{
    a = a * 2; // Modifica solo la copia local de 'a'
    cout << "Dentro de byValue, a = " << a << endl;
    cout << "Dirección local de a = " << &a << endl;
}

// --- Función que recibe un argumento por referencia ---
// Las modificaciones dentro de la función SÍ afectan la variable original.
void byReference(int &b)
{
    b = b * 2; // Modifica la variable original
    cout << "Dentro de byReference, b = " << b << endl;
    cout << "Dirección local de b = " << &b << endl;
}

// --- Función que recibe un argumento por referencia solo lectura ---
// No se puede modificar el valor de 'c' dentro de la función.
int byReferenceReadOnly(const int &c)
{
    //c = c * 2; // Esta línea causaría error de compilación
    cout << "Dentro de byReferenceReadOnly, c = " << c << endl;
    cout << "Usando c para calcular el cuadrado: " << c * c << endl;
    cout << "Dirección local de c = " << &c << endl;
    return c * c;
}


// Declaración de funciones
// Suma dos números
// Suma un número y le agrega 1
// Verifica si un número es primo
double add(double a, double b);
double add(double a);
bool isPrime(int n);


int main()
{
    // Variables de ejemplo
    int num1 = 5;
    int num2 = 10;

    cout << "Antes de llamar a las funciones:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "Dirección local de num1 = " << &num1 << ", Dirección local de num2 = " << &num2 << endl;

    // --- Llamada por valor ---
    // Solo se modifica la copia local, num1 no cambia fuera de la función
    byValue(num1);

    // --- Llamada por referencia ---
    // num2 se modifica dentro de la función y el cambio se refleja fuera
    byReference(num2);

    // --- Llamada por referencia solo lectura ---
    // num2 se pasa por referencia constante, no se puede modificar
    int square = byReferenceReadOnly(num2);
    cout << "Cuadrado de num2: " << square << endl;

    cout << "Después de llamar a las funciones:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    // --- Demostración de la función add ---
    double result = add(3.5, 2.5); // Suma dos números
    cout << "Resultado de add(3.5, 2.5) = " << result << endl;

    result = add(3.5); // Suma 3.5 + 1 usando el valor por defecto
    cout << "Resultado de add(3.5) = " << 3.5 + add(3.5) << endl;

    // --- Demostración de la función isPrime ---
    if (isPrime(num1))
    {
        cout << num1 << " es un número primo." << endl;
    }
    else
    {
        cout << num1 << " no es un número primo." << endl;
    }

    if (isPrime(num2))
    {
        cout << num2 << " es un número primo." << endl;
    }
    else
    {
        cout << num2 << " no es un número primo." << endl;
    }

    return 0;
}


// --- Función que suma dos números ---
// El segundo parámetro tiene valor por defecto 1
// Si se llama con un solo argumento, suma a + 1
// Si se llama con dos argumentos, suma ambos
// Ejemplo: add(3.5, 2.5) = 6.0, add(3.5) = 4.5
double add(double a, double b = 1)
{
    return a + b;
}

// --- Sobrecarga de la función add ---
// Suma a + 1 si solo se pasa un argumento
double add(double a)
{
    return a + 1;
}

// --- Función que verifica si un número es primo ---
// Devuelve true si n es primo, false si no lo es
// Un número primo solo es divisible por 1 y por sí mismo
// Se verifica divisibilidad desde 2 hasta la raíz cuadrada de n
bool isPrime(int n)
{
    // Casos especiales para números menores o iguales a 1
    if (n <= 1)
        return false;

    // Verifica divisibilidad
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false; // n es divisible por i, no es primo
        }
    }
    return true; // n es primo
}