#include<iostream>
#include<graphics.h>
#include<cstdlib>
using namespace std;
int sign(float a)
{
	if(a<0)
		return -1;
	else if(a==0)
		return 0;
	else
		return 1;
}
void dda(int x1,int y1,int x2,int y2)
{
	if(x1==x2&&y1==y2)
	{
	putpixel(x1,y1,YELLOW);
	}
	else
	{
	int x,y,length;
	float dx,dy;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	dx>=dy?length=dx:length=dy;
	dx=dx/(float)length;
	dy=dy/(float)length;
	x=x1+0.5*sign(dx);
	y=y1+0.5*sign(dy);
	int i=1;
	while(i<=length)
	{
	putpixel(x,y,BLUE);
	x=x+dx;
	y=y+dy;
	i=i+1;
	}
	}	
}
void bresen(int x1,int y1,int x2,int y2)
{
	if(x1==x2&&y1==y2)
	{
	putpixel(x1,y1,YELLOW);
	}
	else
	{	
	float dx,dy;
	int e,x,length,y;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;
	y=y1;
	e=2*dy-dx;
	int i=1;
	dx>=dy?length=dx:length=dy;
	while(i<=length)
	{
	while(e>=0)
	{
	y=y+1;
	e=e-2*dx;
	}
	x=x+1;		
	e=e+2*dy;
	i=i+1;
	putpixel(x,y,YELLOW);
	}
	}
}
int main()
{
	int ch,a,b,c,d;
	int x1,y1,x2,y2;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	while(1)
	{
	cout<<"1.DDA\n2.BRESENHAM's ALGORITHM\n 3.EXIT\nEnter the option:";
	cin>>ch;
	switch(ch)
	{
	case 1:cout<<"Enter the cooradinates of line:"<<endl;
		cin>>x1>>y1>>x2>>y2;
		dda(x1,y1,x2,y2);
	break;
	case 2: cout<<"Enter the cooradinates of line:"<<endl;
		cin>>x1>>y1>>x2>>y2;
		bresen(x1,y1,x2,y2);
	break;
	case 3:exit(1);
	break;
	}
	}
	getch();
}	
