#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
#define ll long long int
#define ld long double
using namespace std;

void tranlate(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty)
{
  float mat[3][3] = {{1, 0, tx},{0, 1, ty},{0, 0, 1}};
  float npt[3][3] = {{x1, y1, 1},{x2, y2, 1},{x3, y3, 1}};
  float npt[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

  for(int k = 0; k < 3; k++)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        npt[k][i] = mat[i][j] * pt[k][j];
      }
    }
  }

  for(int i = 0; i < 3; i++)
  {
    line(100 + pt[i][0], 100 + pt[i][1], 100 + pt[(i + 1) % 3][0], 100 + pt[(i + 1) % 3][1]);
  }

  for(int i = 0; i < 3; i++)
  {
    line(300 + npt[i][0], 300 + npt[i][1], 300 + npt[(i + 1) % 3][0], 300 + npt[(i + 1) % 3][1]);
  }
}

void rotate(int x1, int y1, int x2, int y2, int x3, int y3, int ang)
{
  float a = (3.14 * ang) / 180;
  float mat[3][3] = {{cos(a), -sin(a), 0}, {sin(a), cos(a), 0}, {0, 0, 1}};
  float npt[3][3] = {{x1, y1, 1},{x2, y2, 1},{x3, y3, 1}};
  float npt[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

  for(int k = 0; k < 3; k++)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        npt[k][i] = mat[i][j] * pt[k][j];
      }
    }
  }

  for(int i = 0; i < 3; i++)
  {
    line(100 + pt[i][0], 100 + pt[i][1], 100 + pt[(i + 1) % 3][0], 100 + pt[(i + 1) % 3][1]);
  }

  for(int i = 0; i < 3; i++)
  {
    line(300 + npt[i][0], 300 + npt[i][1], 300 + npt[(i + 1) % 3][0], 300 + npt[(i + 1) % 3][1]);
  }

}

void scale(int x1, int y1, int x2, int y2, int x3, int y3, int sx, int sy)
{
  float mat[3][3] = {{sx, 0, 0},{0, sy, 0},{0, 0, 1}};
  float npt[3][3] = {{x1, y1, 1},{x2, y2, 1},{x3, y3, 1}};
  float npt[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

  for(int k = 0; k < 3; k++)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        npt[k][i] = mat[i][j] * pt[k][j];
      }
    }
  }

  for(int i = 0; i < 3; i++)
  {
    line(100 + pt[i][0], 100 + pt[i][1], 100 + pt[(i + 1) % 3][0], 100 + pt[(i + 1) % 3][1]);
  }

  for(int i = 0; i < 3; i++)
  {
    line(300 + npt[i][0], 300 + npt[i][1], 300 + npt[(i + 1) % 3][0], 300 + npt[(i + 1) % 3][1]);
  }

}

void reflect(int x1, int y1, int x2, int y2, int x3, int y3, int rx, int ry)
{
  float mat[3][3] = {{rx, 0, 0},{0, ry, 0},{0, 0, 1}};
  float npt[3][3] = {{x1, y1, 1},{x2, y2, 1},{x3, y3, 1}};
  float npt[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

  for(int k = 0; k < 3; k++)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        npt[k][i] = mat[i][j] * pt[k][j];
      }
    }
  }

  for(int i = 0; i < 3; i++)
  {
    line(100 + pt[i][0], 100 + pt[i][1], 100 + pt[(i + 1) % 3][0], 100 + pt[(i + 1) % 3][1]);
  }

  for(int i = 0; i < 3; i++)
  {
    line(300 + npt[i][0], 300 + npt[i][1], 300 + npt[(i + 1) % 3][0], 300 + npt[(i + 1) % 3][1]);
  }

}

int main()
{
    int gd = DETECT, gm, tmp = 0;

    cout << "Enter the points = " << "\n";
    cout << x1 << y1 << x2 << y2 << x3 << y3;

    int ch = 0;
    cout << "Enter:" << "\n";
    cout << "1: Scaling" << "\n";
    cout << "2: Rotation" << "\n";
    cout << "3: Translation" << "\n";
    cout << "4: Shearing" << "\n";
    cout << "5: Reflection" << "\n";
    cin >> ch;

    //declare all variables before it
    initgraph(&gd,&gm, NULL);
    //draw here

    switch(ch)
    {
      case 1:
      scale(x1, y1, x2, y2, x3, y3, sx, sy);
      break;
      case 2:
      rotate(x1, y1, x2, y2, x3, y3, ang);
      break;
      case 3:
      tranlate(x1, y1, x2, y2, x3, y3, tx, ty);
      break;
      case 4:
      shear(x1, y1, x2, y2, x3, y3, sx, sy);
      break;
      case 5:
      reflect(x1, y1, x2, y2, x3, y3, rx, ry);
      break;
      default:
      cout << "Invalid Choice\n";
    }

    //draw ends
    getche();
    return 0;
}
