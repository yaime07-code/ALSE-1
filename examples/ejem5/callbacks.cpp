#include <iostream>
using namespace std;


 

void performAction(int (*callback)(int,int), int x, int y)
{    
    cout<<"El resultado de la acción es:"<<callback(x,1)<<endl;
    cout<<"El resultado de la acción es:"<<callback(1,y)<<endl;
    cout<<"El resultado de la acción es:"<<callback(x,y)<<endl;
}   

int main()
{
    // Ejemplo de uso
    performAction([](int a, int b) { return a + b; }, 5, 10);
    return 0;
}