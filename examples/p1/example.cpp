#include<iostream>
#include<cmath>
using namespace std;
main(){
    cout << "Increse el x de partida: ";
    int x;
    cin >> x;
    cout << "Increse el y de partida: ";
    int y;
    cin >> y;
    cout << "Increse x1: ";
    int x1;
    cin >> x1;
    cout << "Increse y1: ";
    int y1;
    cin >> y1;
    cout << "Increse x2: ";
    int x2;
    cin >> x2;
    cout << "Increse y2: ";
    int y2;
    cin >> y2;
    cout << "Increse x3: ";
    int x3;
    cin >> x3;
    cout << "Increse y3: ";
    int y3;
    cin >> y3;
    double d1 = sqrt(pow((x1-x),2)+pow((y1-y),2));
    double d2 = sqrt(pow((x2-x),2)+pow((y2-y),2));
    double d3 = sqrt(pow((x3-x),2)+pow((y3-y),2));
    if (d1<d2 && d1<d3){
        cout<<"El punto mas cercano es: ("<<x1<<","<<y1<<")"<<endl;
    } else if (d2<d1 && d2<d3){
        cout<<"El punto mas cercano es: ("<<x2<<","<<y2<<")"<<endl;
    }
    else {
        cout<<"El punto mas cercano es: ("<<x3<<","<<y3<<")"<<endl;
    }
    return 0;    
}