#include<bits/stdc++.h>
#include<graphics.h>
#define ll long long int
#define ld long double

//For outer loop
#define fr(i, start, stop, increment) for(i = start; i < stop; i += increment)
#define dfr(i, start, stop ,decrement) for( i = start; i >= stop; i -= decrement)

using namespace std;

void floodFillUtil(vector<vector<ll>> &v, ll x, ll y, ll pc, ll nc)
{
  if(x < 0 || x >= v.size() || y < 0 || y >= v[0].size()) return;
  if(v[x][y] != pc) return;
  if(v[x][y] == nc) return;
  v[x][y] = nc;
  floodFillUtil(v, x+1, y, pc, nc);
  floodFillUtil(v, x-1, y, pc, nc);
  floodFillUtil(v, x, y+1, pc, nc);
  floodFillUtil(v, x, y-1, pc, nc);
}

void floodFill(vector<vector<ll>> &v, ll x, ll y, ll nc)
{
    ll pc = v[x][y];
    floodFillUtil(v, x, y, pc, nc);
}

int main()
{
    int gd = DETECT, gm;

    ll  n = 0, m = 0, i, j;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m, 0));

    fr(i, 0, n, 1)
    {
      v[i][0] = 2;
      v[i][m - 1] = 3;
    }

    fr(i, 0, m, 1)
    {
      v[0][i] = 4;
      v[n - 1][i] = 5;
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

    floodFill(v, 4, 4, 8);

    fr(i, 0, n, 1)
    {
      fr(j, 0, m, 1)
      {
        putpixel(100 + i, 100 + j, v[i][j]);
      }
    }


    //draw ends
    getche();
    closegraph();
    return 0;
}
