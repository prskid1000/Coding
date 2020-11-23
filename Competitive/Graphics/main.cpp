#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void boundaryfill(int x,int y,int boundarycolor,int newcolor){
	if(getpixel(x,y)==boundarycolor || getpixel(x,y)==newcolor) return;
	putpixel(x,y,newcolor);
	boundaryfill(x+1,y,boundarycolor,newcolor);
	boundaryfill(x-1,y,boundarycolor,newcolor);
	boundaryfill(x,y+1,boundarycolor,newcolor);
	boundaryfill(x,y-1,boundarycolor,newcolor);
}
void background(){
    int x1=20,x2=600;
	for(int i=20;i<600;i++){
		int y1,y2;
		y1=y2=i;
		int dx=x2-x1;
		int dy=y2-y1;
		int steps;
		if(abs(dx)>abs(dy)) steps = abs(dx);
		else steps = abs(dy);
		int xinc = dx/steps;
		int yinc = dy/steps;
		int x=0,y=i;
		x+=xinc;
		y+=yinc;
		for(int i=0;i<steps;i++){
			putpixel(x,y,WHITE);
		  //delay(1);
			x+=xinc;
			y+=yinc;
		}
	}
}
void ellipsehere(float rx,float ry,int e,int f,int color){
	float x=0,y=ry;
	float d1=(ry*ry) - (rx*rx*ry) + (0.25*rx*rx);
	float dy =2*rx*rx*y, dx=2*ry*ry*x;
	do{
		putpixel(e+x,y+f,color);
		putpixel(e-x,y+f,color);
		putpixel(e+x,f-y,color);
		putpixel(e-x,f-y,color);
		if(d1<0){
			x=x+1;
			dx+=2*ry*ry;
			d1=d1+dx+ry*ry;
		}
		else{
			x=x+1;
			y=y-1;
			dx+=2*ry*ry;
			dy-=2*rx*rx;
			d1=d1+dx-dy+ry*ry;
		}
	} while(dx<dy);
	float d2=  ((ry * ry) * ((x + 0.5) * (x + 0.5))) +  ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
		do{
		putpixel(e+x,y+f,color);
		putpixel(e-x,y+f,color);
		putpixel(e+x,-y+f,color);
		putpixel(e-x,-y+f,color);
		if(d2>0){
			y=y-1;
			dy-=2*rx*rx;
			d2=d2-dy+rx*rx;
		}
		else{
			x=x+1;
			y=y-1;
			dx+=2*ry*ry;
			dy-=2*rx*rx;
			d2=d2+dx-dy+rx*rx;
		}
	} while(y>0);
}
void circlehe(int r,int e,int f,int c){
	 int x=0,y;
    float d;
    y = r ; d = 1.5 -r;
    do
    {
        putpixel(e+x,f+y,c);
        putpixel(e+x,f-y,c);
        putpixel(e-x,f+y,c);
        putpixel(e-x,f-y,c);
        putpixel(e+y,f+x,c);
        putpixel(e+y,f-x,c);
        putpixel(e-y,f+x,c);
        putpixel(e-y,f-x,c);
        if(d<0)
        {
            x++;
            y= y;
            d= d+2*x+2;
		}
        else
        {
            x++;
            y--;
            d = d+2*x-2*y+1;
        }
	}while(x<y);
}
int main(){
	int gd=DETECT,gm;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,NULL);
	background();
	circlehe(60,100,100,BLACK);
	boundaryfill(80,80,BLACK,BLACK);
	circlehe(60,300,100,BLACK);
	boundaryfill(280,80,BLACK,BLACK);
	circlehe(120,200,200,BLACK);
	boundaryfill(180,180,BLACK,BLACK);
	delay(100);
	getch();
	return 0;
}
