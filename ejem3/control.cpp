#include <iostream>
using namespace std;

int main() {
    int x = 12, y = 87;
    int num1,num2;
    if(x>y){
        cout<<"x es mayor que y"<<endl;
    }
    else if (y>x){
        cout<<"x no es mayor que y"<<endl;
    }

    else{
        cout<<"x es igual que y"<<endl;
    }

    cout<<"Ingrese dos numeros:"<<endl;
    
    cin>>num1;
    if(num%2==0){
        cout<<"El numero es par"<<endl;
    }
    else{
        cout<<"El numero es impar"<<endl;
    }

    cout<<"Ingrese otro numero:"<<endl;
    cin>>num2;
    if(num2%2==0 && num1%2==0){
        cout<<"Ambos numeros son pares"<<endl;
    }
    else if(num2%2==0 && num1%2!=0 || num1%2==0 && num2%2!=0){
        cout<<"Al menos uno de los numeros es impar"<<endl;
    }
    else{
        cout<<"Ambos numeros son impares"<<endl;
    }
    return 0;
}