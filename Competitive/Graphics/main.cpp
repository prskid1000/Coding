#include<bits/stdc++.h>
#include<graphics.h>
#define ll long long int
using namespace std;
int main()
{
    int gd = DETECT, gm, tmp = 0;

    ll x1 = 0, x2 = 0, y1 = 0, y2 = 0, dx = 0, dy = 0;
    ll steps = 0, xinc = 0, yinc = 0, x = 0, y = 0;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx) > abs(dy)) steps = abs(dx);
    else steps = abs(dy);

    xinc = dx / steps;
    yinc = dy / steps;

    x += xinc;
    y += yinc;

    //declare all variables before it
    initgraph(&gd,&gm, NULL);
    //draw here

    for(ll i = 0; i < steps; i++)
    {
      x += xinc;
      y += yinc;
      putpixel(100 + x, 100 + y, 15);
      delay(10);
    }

    //draw ends
    getche();
    closegraph();
    return 0;
}
