#include<bits/stdc++.h>
#include<graphics.h>
#define ll long long int
#define ld long double
using namespace std;

void tranlate(float x1, float y1, float x2, float y2, float x3, float y3, float tx, float ty)
{
  float mat[3][3] = {{1, 0, tx},{0, 1, ty},{0, 0, 1}};
  float pt[3][3] = {{x1, y1, 1},{x2, y2, 1},{x3, y3, 1}};
  float npt[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

  for(int k = 0; k < 3; k++)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        npt[k][i] += mat[i][j] * pt[k][j];
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

void rotate(float x1, float y1, float x2, float y2, float x3, float y3, float ang)
{
  float a = (3.14 * ang) / 180;
  float mat[3][3] = {{cos(a), -sin(a), 0}, {sin(a), cos(a), 0}, {0, 0, 1}};
  float pt[3][3] = {{x1, y1, 1},{x2, y2, 1},{x3, y3, 1}};
  float npt[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

  for(int k = 0; k < 3; k++)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        npt[k][i] += mat[i][j] * pt[k][j];
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

void scale(float x1, float y1, float x2, float y2, float x3, float y3, float sx, float sy)
{
  float mat[3][3] = {{sx, 0, 0},{0, sy, 0},{0, 0, 1}};
  float pt[3][3] = {{x1, y1, 1},{x2, y2, 1},{x3, y3, 1}};
  float npt[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

  for(int k = 0; k < 3; k++)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        npt[k][i] += mat[i][j] * pt[k][j];
      }
    }
  }

  for(int i = 0; i < 3; i++)
  {
    line(200 + pt[i][0], 200 + pt[i][1], 200 + pt[(i + 1) % 3][0], 200 + pt[(i + 1) % 3][1]);
  }

  for(int i = 0; i < 3; i++)
  {
    cout << 100 + npt[i][0] << " " << 100 + npt[i][1] << " " << 100 + npt[(i + 1) % 3][0] << " " << 100 + npt[(i + 1) % 3][1] << "\n";
    line(300 + npt[i][0], 300 + npt[i][1], 300 + npt[(i + 1) % 3][0], 300 + npt[(i + 1) % 3][1]);
  }

}

void reflect(float x1, float y1, float x2, float y2, float x3, float y3, float rx, float ry)
{
  float mat[3][3] = {{rx, 0, 0},{0, ry, 0},{0, 0, 1}};
  float pt[3][3] = {{x1, y1, 1},{x2, y2, 1},{x3, y3, 1}};
  float npt[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

  for(int k = 0; k < 3; k++)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        npt[k][i] += mat[i][j] * pt[k][j];
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

void shear(float x1, float y1, float x2, float y2, float x3, float y3, float sx, float sy)
{
  float mat[3][3] = {{1, sx, 0},{sy, 1, 0},{0, 0, 1}};
  float pt[3][3] = {{x1, y1, 1},{x2, y2, 1},{x3, y3, 1}};
  float npt[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

  for(int k = 0; k < 3; k++)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        npt[k][i] += mat[i][j] * pt[k][j];
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
    float x1, y1, x2, y2, x3, y3, sx, sy, rx, ry, tx, ty, ang;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int ch = 0;
    cout << "Enter:" << "\n";
    cout << "1: Scaling" << "\n";
    cout << "2: Rotation" << "\n";
    cout << "3: Translation" << "\n";
    cout << "4: Shearing" << "\n";
    cout << "5: Reflection" << "\n";
    cin >> ch;

    switch(ch)
    {
      case 1:
      cin >> sx >> sy;
      break;

      case 2:
      cin >> ang;
      break;

      case 3:
      cin >> tx >> ty;
      break;

      case 4:
      cin >> sx >> sy;
      break;

      case 5:
      cin >> rx >> ry;
      break;

      default:
      cout << "Invalid Choice\n";
    }

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
      cout << "";
    }

    //draw ends
    getche();
    closegraph();
    return 0;
}
