#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    Point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 5;
    char character = 't';
    int a = 89;
    float b = 152461.58;
    cout<<"char + int:" <<character + a << endl;
    cout<<"float + int:" <<(float) (b +a)<< endl;
    cout<<"char + float:" <<character + b << endl;
    cout<<"2 char + float:" <<(int)(character) + b << endl;
    p2.x++;
    cout<<"p2 - x:" <<p2.x <<" y:" <<p2.y << endl;
    int d = (int)b;
    a =p2.y++;
    cout<<"p2 - x:" <<p2.x <<" y:" <<p2.y << endl;
    cout<<"a:" <<a << endl; 
    int c=++a;
    cout<<"c:" <<c << endl;
    cout<<"a:" <<a << endl;  
    c+= 8;
    cout<<"c:" <<c << endl;
    c *= 3;
    cout<<"c:" <<c << endl;

    return 0;
}