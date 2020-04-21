#include<iostream>
#include<cstdlib>
#include<graphics.h>
#define pi 3.1412
using namespace std;
void create(int x[],int y[],int n)
{
	for(int i=0;i<n;i++)
		line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
}

int main()
{
	int n,b,a,x1[9],y1[9],x[9],y[9],tx,ty,dx,dy;
	float s,d;
	cout<<"Enter the no.of vertices :";
	cin>>n;
	cout<<"Enter the coordinates(x,y):";
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	int gm,gd=DETECT;
	initgraph(&gd,&gm,NULL);
	create(x,y,n);
	while(1)
	{
	cout<<"1.Translation\n2.Scaling\n3.Rotation\n4.Exit\nEnter your choice:";
	cin>>b;
	switch(b)
	{
	case 1:
	cout<<"Enter the distance for translation(x,y):"<<endl;
	cin>>tx>>ty;
	cleardevice();
	create(x,y,n);
	for(int i=0;i<n;i++)	
	{
		x1[i]=x[i]+tx;
		y1[i]=y[i]+ty;
	}
	create(x1,y1,n);
	break;
	case 2:
	cout<<"Enter the scaling factor:";
	cin>>s;
	cleardevice();
	create(x,y,n);
	if(s>0)
	{
		for(int i=0;i<n;i++)
		{
			x1[i]=x[i]*s;
			y1[i]=y[i]*s;
	  	}
	}
	else
	{
		s=-s;
		for(int i=0;i<n;i++)
		{
			x[i]=x[i]/s;
			y[i]=y[i]/s;
		}
	}
	create(x1,y1,n);
	break;
	case 3:
	cleardevice();
	create(x,y,n);
	cout<<"Enter the angle";
	cin>>a;
	d=(float)a*pi/180;
	for(int i=0;i<n;i++)
	{
	x1[i]=(x[i]*cos(d))-(y[i]*sin(d));
	y1[i]=(x[i]*sin(d))+(y[i]*cos(d));
	}	
	create(x1,y1,n);
	break;
	default:
	cout<<"Wrong choice!!";
	break;
	case 4:
	exit(1);
	break;
	}
	}
	getch();
}

