#include<bits/stdc++.h>
#include<graphics.h>
#define ll long long int
#define ld long double

//For outer loop
#define fr(i, start, stop, increment) for(i = start; i < stop; i += increment)
#define dfr(i, start, stop ,decrement) for( i = start; i >= stop; i -= decrement)

using namespace std;

void boundaryFill(ll x, ll y, ll fc, ll bc)
{
  if(getpixel(x, y) != bc && getpixel(x, y) != fc)
    {
        putpixel(x, y, fc);
        boundaryFill(x + 1, y, fc, bc);
        boundaryFill(x, y + 1, fc, bc);
        boundaryFill(x - 1, y, fc, bc);
        boundaryFill(x, y - 1, fc, bc);
        boundaryFill(x - 1, y - 1, fc, bc);
        boundaryFill(x - 1, y + 1, fc, bc);
        boundaryFill(x + 1, y - 1, fc, bc);
        boundaryFill(x + 1, y + 1, fc, bc);
    }
}

int main()
{
    int gd = DETECT, gm;

    ll  n = 0, m = 0, i, j;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m, 0));

    fr(i, 0, n, 1)
    {
      v[i][0] = 1;
      v[i][m - 1] = 1;
    }

    fr(i, 0, m, 1)
    {
      v[0][i] = 1;
      v[n - 1][i] = 1;
    }

    //declare all variables before it

    initgraph(&gd,&gm, NULL);
    //draw here

    fr(i, 0, n, 1)
    {
      fr(j, 0, m, 1)
      {
        putpixel(100 + i, 100 + j, v[i][j]);
      }
    }

    boundaryFill(104, 104, 8, 1);

    //draw ends
    getche();
    closegraph();
    return 0;
}
