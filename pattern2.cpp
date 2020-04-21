#include<iostream>
#include<graphics.h>
using namespace std;
void display(int x1,int y1, int x, int y)
{
	putpixel(x1+x,y1+y,YELLOW);
	putpixel(x1-x,y1+y,YELLOW);
	putpixel(x1+x,y1-y,YELLOW);
	putpixel(x1-x,y1-y,YELLOW);
	putpixel(x1+y,y1+x,YELLOW);
	putpixel(x1-y,y1+x,YELLOW);
	putpixel(x1+y,y1-x,YELLOW);
	putpixel(x1-y,y1-x,YELLOW);
}

void draw(int x2,int y2,int r)
{
	int x=0,y=r;
	int d=3-2*r;
	display(x2,y2,x,y);
	while(y>=x)
	{
	x++;
	if(d>0)
	{
	y--;
	d=d+4*(x-y)+10;
	}
	else
	{
	d=d+4*x+6;
	}
	display(x2,y2,x,y);
	}
}

void dda(int x1,int y1,int x2,int y2)
{
	int length,dx,dy;
	float x,y,xi,yi;
	dx=x2-x1,dy=y2-y1;
	abs(dx)>abs(dy)?length=dx:length=dy;
	xi=dx/(float)length,yi=dy/(float)length;
	x=x1,y=y1;
	int i=0;
	while(i<=length)
	{
	putpixel(x,y,WHITE);
	x=x+xi;
	y=y+yi;
	i++;
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	draw(50,50,25);
	dda(25,50,75,50);
	dda(50,25,75,50);
	dda(50,25,25,50);
	draw(50,39,9);
	getch();
}


