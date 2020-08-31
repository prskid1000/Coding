#include<graphics.h>
#define ll long long int
int main()
{
    int gd = DETECT, gm, tmp = 0;
    initgraph(&gd,&gm, NULL);
    circle(300,300,50);
    getche();
    closegraph();
    return 0;
}
