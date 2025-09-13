#include <iostream>
using namespace std;

int main() {
    char userInput = 'q';
    int count = 0;
    cout<<"Ingrese 'q' para salir del ciclo:"<<endl;
    while (userInput=='y' || userInput=='Y' )
    {
        cout<<"deseas continuar (y/n):"<<endl;
        cin>>userInput;
        cout <<"Contador vale: "<<count<<endl;
        count++;    
    }
    userInput='q';
    do
    {
        cout<<"deseas continuar oprima q:"<<endl;
        cin>>userInput;
        cout <<"Contador vale: "<<count<<endl;
        count++;
    } while (userInput=='q' || userInput=='Q');

    return 0;
}   
    