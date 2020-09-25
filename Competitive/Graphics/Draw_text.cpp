#include<bits/stdc++.h>
#include<graphics.h>
#define ll long long int
using namespace std;

int main()
{
    int gd = DETECT, gm, tmp = 0;

    //declare all variables before it
    initgraph(&gd,&gm, NULL);
    //draw here

    char sen[]= "I am a Coder";

    ll x = 75, y = 75, f = 0;

    for (f = 0; f <= 15; f++)
  	{
      setcolor(f);
  		outtextxy(x, y, sen);
      delay(300);
  		y = y + 20;
  	}


    //draw ends
    getche();
    closegraph();
    return 0;
}
