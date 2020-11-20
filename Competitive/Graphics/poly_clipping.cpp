#include <bits/stdc++.h>
#include <graphics.h>

#define TRUE 1
#define FALSE 0

using namespace std;

typedef unsigned int outcode;
outcode CompOutCode(float x,float y);

enum
{
TOP = 0x1,
BOTTOM = 0x2,
RIGHT = 0x4,
LEFT = 0x8
};

float xmin,xmax,ymin,ymax;

void clip(float x0,float y0,float x1,float y1)
{
  outcode outcode0,outcode1,outcodeOut;
  int accept = FALSE,done = FALSE;
  outcode0 = CompOutCode(x0,y0);
  outcode1 = CompOutCode(x1,y1);
  do
  {
    if(!(outcode0|outcode1))
    {
        accept = TRUE;
        done = TRUE;
    }
    else
    if(outcode0 & outcode1)
        done = TRUE;
    else
    {
        float x,y;
        outcodeOut = outcode0?outcode0:outcode1;
        if(outcodeOut & TOP)
        {
            x = x0+(x1-x0)*(ymax-y0)/(y1-y0);
            y = ymax;
        }
        else if(outcodeOut & BOTTOM)
        {
            x = x0+(x1-x0)*(ymin-y0)/(y1-y0);
            y = ymin;
        }
        else if(outcodeOut & RIGHT)
        {
            y = y0+(y1-y0)*(xmax-x0)/(x1-x0);
            x = xmax;
        }
        else
        {
            y = y0+(y1-y0)*(xmin-x0)/(x1-x0);
            x = xmin;
        }
        if(outcodeOut==outcode0)
        {
            x0 = x;
            y0 = y;
            outcode0 = CompOutCode(x0,y0);
        }
        else
        {
            x1 = x;
            y1 = y;
            outcode1 = CompOutCode(x1,y1);
          }
    }
  }while(done==FALSE);
  if(accept)line(x0,y0,x1,y1);
  rectangle(xmin,ymin,xmax,ymax);
}

outcode CompOutCode(float x,float y)
{
  outcode code = 0;
  if(y>ymax)
      code|=TOP;
  else if(y<ymin)
          code|=BOTTOM;
  if(x>xmax)
      code|=RIGHT;
  else if(x<xmin)
      code|=LEFT;
  return code;
}

int main( )
{
  float x1,y1,x2,y2;
  int gdriver = DETECT, gmode, n,poly[14],i;

  cout << "Enter the no of sides of polygon:";
  cin >> n;

  cout << "\nEnter the coordinates of polygon\n";
  for(i=0;i<2*n;i++)cin >> poly[i];

  poly[2*n]=poly[0];
  poly[2*n+1]=poly[1];

  cout << "Enter the rectangular coordinates of clipping window\n";
  cin >> xmin >> ymin >> xmax >> ymax;

  initgraph(&gdriver, &gmode, NULL);

  drawpoly(n+1,poly);
  rectangle(xmin,ymin,xmax,ymax);
  delay(5000);

  for(i=0;i<n;i++)
  {
    clip(poly[2*i],poly[(2*i)+1],poly[(2*i)+2],poly[(2*i)+3]);
  }

  getch( );
  closegraph();
  return 0;
}
