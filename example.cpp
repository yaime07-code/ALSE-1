#include <iostream>
#define debug
long double largeDecimal = 0x1452759F12C3LL; // Hexadecimal long long literal

int main() {
    int height = 1.8;
    char character = 'H';
    bool opened = false;

    unsigned int count = 0;
    short score = 0;
    int x, y;

    int aux;

    std::cout << "colocando texto entre comillas dobles" << "\n";
    std::cin >> x >> y;
    aux = x;
    x = y;
    y = aux;
    std::cout << "x: " << x << " y: " << y << std::endl;
    std::cout << "floating point number: " << height << std::endl;
    std::cout << "char variable: " << character << std::endl;
    std::cout << "boolean variable: " << opened << std::endl;
    std::cout << "long double variable: " << largeDecimal << std::endl;
    return 0;
}