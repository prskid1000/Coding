#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int maxx,maxy,midx,midy;

void axis()
{
  getch();
  cleardevice();
  line(midx,0,midx,maxy);
  line(0,midy,maxx,midy);
}

void translation()
{
  int x,y,z,o,x1,x2,y1,y2;
  int gd=DETECT,gm;

  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,NULL);

  maxx=getmaxx();
  maxy=getmaxy();
  midx=maxx/2;
  midy=maxy/2;

  axis();

  bar3d(midx+50,midy-100,midx+60,midy-90,10,1);

  cout << "Enter translation factor\n";
  cin >> x >> y;

  cout << "After translation:\n";
  bar3d(midx+x+50,midy-(y+100),midx+x+60,midy-(y+90),10,1);

  cin >> x;
  closegraph();
}

void scaling()
{
  float x,y,z,o,x1,x2,y1,y2;
  int gd=DETECT,gm;

  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,NULL);

  maxx=getmaxx();
  maxy=getmaxy();
  midx=maxx/2;
  midy=maxy/2;

  axis();

  bar3d(midx+50,midy-100,midx+60,midy-90,5,1);

  cout << "Enter scaling factors\n";
  cin >> x >> y >> z;

  cout << "After scaling\n";
  bar3d(midx+(x*50),midy-(y*100),midx+(x*60),midy-(y*90),5*z,1);
  delay(3000);

  cin >> x;
  closegraph();
}

void rotation()
{
  float x,y,z,o,x1,x2,y1,y2;
  int gd=DETECT,gm;

  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,NULL);

  maxx=getmaxx();
  maxy=getmaxy();
  midx=maxx/2;
  midy=maxy/2;

  axis();

  bar3d(midx+50,midy-100,midx+60,midy-90,5,1);

  cout << "Enter rotating angle\n";
  cin >> o;

  x1=50*cos(o*3.14/180)-100*sin(o*3.14/180);
  y1=50*sin(o*3.14/180)+100*cos(o*3.14/180);
  x2=60*cos(o*3.14/180)-90*sin(o*3.14/180);
  y2=60*sin(o*3.14/180)+90*cos(o*3.14/180);

  cout << "After rotation about z axis\n";
  bar3d(midx+x1,midy-y1,midx+x2,midy-y2,5,1);
  cin >> o;


  cout << "After rotation  about x axis\n";
  bar3d(midx+50,midy-x1,midx+60,midy-x2,5,1);
  cin >> o;


  cout << "After rotation about yaxis\n";
  bar3d(midx+x1,midy-100,midx+x2,midy-90,5,1);

  cin >> o;
  closegraph();
}

int main()
{
  rotation();
  return 0;
}
