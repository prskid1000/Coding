#include<bits/stdc++.h>
#include<graphics.h>
#define ll long long int
#define ld long double
using namespace std;

int main()
{
    int gd = DETECT, gm, tmp = 0;

    ld r = 0;
    cin >> r;

    ld x = 0, y = r, d = 1.25 - r;

    //declare all variables before it
    initgraph(&gd,&gm, NULL);
    //draw here

    do
    {
      putpixel(100 + x, 100 + y, 15);
      putpixel(100 - x, 100 - y, 15);
      putpixel(100 - x, 100 + y, 15);
      putpixel(100 + x, 100 - y, 15);

      putpixel(100 + y, 100 + x, 15);
      putpixel(100 - y, 100 - x, 15);
      putpixel(100 - y, 100 + x, 15);
      putpixel(100 + y, 100 - x, 15);
      if(d < 0)
      {
        x = x + 1;
        y = y;
        d = d + 2 * x + 1;
      }
      else
      {
        x = x + 1;
        y = y - 1;
        d = d + 2 * x - 2 * y + 1;
      }
      delay(300);
    }while(x < y);

    //draw ends
    getche();
    closegraph();
    return 0;
}
