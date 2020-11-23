#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void circlehe(int c,int r,int e,int f){
	 int x=0,y;
    float d;
    y = r ; d = 1.25 -r;
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

 	cout<<"Solar System with Circle Md Pt 32";
 	//sun
 	for(int i=0;i<40;i++){
 		circlehe(14,i,400,400);
	}
	 //9 circles
	 circlehe(15,90,400,400);
	 circlehe(15,120,400,400);
	 circlehe(15,150,400,400);
	 circlehe(15,200,400,400);
	 circlehe(15,250,400,400);
	 circlehe(15,300,400,400);
	 circlehe(15,340,400,400);
	 circlehe(15,390,400,400);
//	for(int i=1;i<=8;i++){
//	 	circlehe(15,30*(i+2),400,400);
//	}
	 //Mercury 22r grey color
	for(int i=0;i<=21;i++)
	 circlehe(7,i,340,340);

	 //Venus  23 12 light red
	for(int i=0;i<=23;i++)
	    circlehe(12,i,280,400);

	 //Earth blue=1 r=25
	for(int i=0;i<=26;i++)
	    circlehe(1,i,295,295);

	//Mars red=4 r = 22
	for(int i=0;i<=22;i++)
	    circlehe(4,i,365,205);

	//Jupiter brown 38 radius
	for(int i=0;i<=38;i++)
	    circlehe(6,i,300,170);
	//Saturn orange 35
	for(int i=0;i<=35;i++)
	    circlehe(12,i,365,105);
//	    //ring
	circlehe(15,39,365,105);
//	//uranus 9 33
	for(int i=0;i<=33;i++)
	    circlehe(9,i,505,75);
//	//neptune 1 30
	for(int i=0;i<=30;i++)
		    circlehe(1,i,155,95);
//
	getch();
    return 0;
}
