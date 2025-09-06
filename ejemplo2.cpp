#include <iostream>
using namespace std;
struct Point {
    int x, y;
};

int main() {
    Point p1, p2;
    p1.x = 10;
    p1.y = 20;
    p2.x = 30;
    p2.y = 40;
    char character = 't';
    int a = 89;
    float b = 3.14;
    cout<<"char + int:" <<character + a << endl;
    cout<<"float + int:" <<(float) (b +a)<< endl;
    cout<<"char + float:" <<character + b << endl;
    cout<<"2 char + float:" <<(int)(character) + b << endl;
    p2.x++;
    a =p2.y++;
    int c=++a;
    c+= 8;
    c *= 3;  

    return 0;


}