/*
Write C++ program to implement Cohen Southerland line clipping algorithm.
*/

#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
class POINT
{
public:
    // ABRL
    int x, y;
	    int code[4];
    void setCode(int xmin,int xmax,int ymin,int ymax){
	if (x<xmin)
	    code[3] = 1;// left
	else
	    code[3] = 0;
	if(x>xmax)
	    code[2] = 1;// Right
	else
	    code[2] = 0;
	if (y>ymax)
	    code[1] = 1;// Above
	else
	    code[1] = 0;
	if(y<ymin)
	    code[0] = 1;// Below
	else
	    code[0] = 0;
    }

};

void drawWindow(int xmin,int xmax,int ymin,int ymax){
	line(xmin,ymax,xmin,ymin);
	line(xmax,ymin,xmax,ymax);
	line(xmin,ymin,xmax,ymin);
	line(xmin,ymax,xmax,ymax);
}

// return 0 if line completly visibl
// return 1 if line completly invisible
// return 2 otherwise
int check(POINT p1,POINT p2){
    int flag = 0;
    for(int i=0;i<4;i++)
    {
	if(p1.code[i] != 0 || p2.code[i] != 0)
	    flag = 1;
    }
    if(flag==0)
	   return 0; //both points are completly inside
    flag = 0;
    for(int j = 0;j<4;j++)
    {
	if(p1.code[j]== 1 && p2.code[j] == 1)
	    flag = 1;
    }
    if(flag==1)
	   return 1;// both points are completly outside
    return 2;// partially inside and pratially outside

}
POINT clipping(POINT p1, POINT p2,int xmin,int xmax,int ymin,int ymax)
{
    float m;
    POINT pi;
    // LEFT and RIGHT edges
    if(p1.code[2]==1)  //it crosses Right side
	   pi.x = xmax;
    if(p1.code[3]==1) //it Left Left side
	   pi.x = xmin;
    if(p1.code[3] ==1 || p1.code[2]==1)
    {
	// to find the slope of the line
	m = (float)(p2.y-p1.y)/(p2.x-p1.x);
	pi.y = p1.y +m*(pi.x-p1.x);
	for(int i=0;i<4;i++)// for copying the code of p1 to pi
		pi.code[i] = p1.code[i];
	if(pi.y <= ymax && pi.y >= ymin)
		return pi;
    }
    // TOP and BOTTOM edges
    if(p1.code[0] == 1) // it crosses Top side
	   pi.y = ymin;
    if(pi.code[1] == 1) // it crosses Bottom side
	   pi.y = ymax;
    if(p1.code[0]==1 || p1.code[1]==1)
    {
	// to find the slope of the line
	m = (float)(p2.y-p1.y)/(p2.x-p1.x);
	pi.x = p1.x + (pi.y-p1.y)/m;
	for(int i=0;i<4;i++)// for copying the code of p1 to pi
		pi.code[i] = p1.code[i];
	if(pi.y <= ymax && pi.y >= ymin)
		return pi;
    }
    else
	   return p1;

}

int main()
{
    clrscr();
    POINT ps,pe,p3,p4;

    cout <<"Enter x and y  coordinates of start point of line:: ";
    cin >> ps.x>>ps.y;
    cout <<"Enter x and y  coordinates of end point of line:: ";
    cin >> pe.x>>pe.y;
    int xmin=100,xmax=300,ymin=100,ymax=200;
    int gd = DETECT , gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    ps.setCode(xmin,xmax,ymin,ymax);// set code for ps
    pe.setCode(xmin,xmax,ymin,ymax);// set code for pe
    int  value = check(ps,pe);
    switch (value) {
	case 0:
		outtextxy(50,50,"Before clipping");
		drawWindow(xmin,xmax,ymin,ymax);// drawWindow
		delay(3000);
		line(ps.x,ps.y,pe.x,pe.y);// draw line
		delay(3000);
		cleardevice();
		outtextxy(50,50,"After clipping");
		drawWindow(xmin,xmax,ymin,ymax);// drawWindow
		line(ps.x,ps.y,pe.x,pe.y);// draw line
		break;
	case 1:
		outtextxy(50,50,"Before clipping");
		drawWindow(xmin,xmax,ymin,ymax);// drawWindow
		delay(3000);
		line(ps.x,ps.y,pe.x,pe.y);// draw line
		delay(3000);
		cleardevice();
		outtextxy(50,50,"After clipping");
		drawWindow(xmin,xmax,ymin,ymax);// drawWindow
		// line is completly outside therefore it's not displyed
		break;
	case 2:
		outtextxy(50,50,"Before clipping");
		drawWindow(xmin,xmax,ymin,ymax);// drawWindow
		line(ps.x,ps.y,pe.x,pe.y);      // draw line
		delay(3000);
		cleardevice();
		outtextxy(50,50,"After clipping");
		p3 = clipping(ps,pe,xmin,xmax,ymin,ymax);// p3 is clipped point for first interface
		p4 = clipping(pe,ps,xmin,xmax,ymin,ymax);// p4 is clipped point for second interface
		drawWindow(xmin,xmax,ymin,ymax);
		line(p3.x,p3.y,p4.x,p4.y);
		break;
	default:
	    cout <<".....";
	    break;
    }
    getch();
    closegraph();
    return 0;
}
