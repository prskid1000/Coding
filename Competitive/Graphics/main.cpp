#include<bits/stdc++.h>
#include<graphics.h>
#define ll long long int
using namespace std;

int main()
{
    int gd = DETECT, gm, tmp = 0;

    ll x1 = 0, x2 = 0, y1 = 0, y2 = 0, dx = 0, dy = 0, p;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    dx = x2 - x1;
    dy = y2 - y1;

    //declare all variables before it
    initgraph(&gd,&gm, NULL);
    //draw here

    if(dy > dx)
    {
      p = 2*(dy - dx);
      for(; x1 <= x2; x1++)
      {
        if(p < 0)
        {
          p = p + 2 * dy;
        }
        else
        {
          y1++;
          p = p + 2 * dy - dx;
        }
        putpixel(100 + x1, 100 + y1, 15);
        delay(300);
      }
    }
    else
    {
      p = 2*(dx - dy);
      for(; y1 <= y2; y1++)
      {
        if(p < 0)
        {
          p = p + 2 * dx;
        }
        else
        {
          x1++;
          p = p + 2 * dx - dy;
        }
        putpixel(100 + x1, 100 + y1, 15);
        delay(300);
      }
    }

    //draw ends
    getche();
    closegraph();
    return 0;
}
