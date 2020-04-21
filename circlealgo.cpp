#include<iostream>
#include<graphics.h>
using namespace std;
void display(int x1,int y1,int x,int y)
{
	putpixel(x1+x,y1+y,BLUE);
	putpixel(x1-x,y1+y,BLUE);
	putpixel(x1+x,y1-y,BLUE);
	putpixel(x1-x,y1-y,BLUE);
	putpixel(x1+y,y1+x,BLUE);
	putpixel(x1-y,y1+x,BLUE);
	putpixel(x1+y,y1-x,BLUE);
	putpixel(x1-y,y1-x,BLUE);
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

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	draw(150,150,150);
	draw(150,150,120);
	draw(150,150,100);
	draw(150,150,80);
	draw(150,150,50);
	draw(150,150,30);
	getch();
}
