#include<bits/stdc++.h>
#include<graphics.h>
#define ll long long int
#define ld long double
using namespace std;

int main()
{
    int gd = DETECT, gm, tmp = 0;

    //declare all variables before it
    initgraph(&gd,&gm, NULL);
    //draw here
    line(200,50, 300, 50);
    line(200, 50, 150, 80);
    line(300, 50, 400, 80);
    line(100, 80, 450, 80);
    line(100, 80, 100, 110);
    line(450, 80, 450, 110);
    circle(170, 110, 20);
    circle(390, 110, 20);
    line(100, 110, 150, 110);
    line(190, 110, 370, 110);
    line(410, 107, 450, 110);
    //draw ends

    getche();
    closegraph();
    return 0;
}
