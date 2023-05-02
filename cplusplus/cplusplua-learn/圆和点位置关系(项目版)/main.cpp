#include "Circle.h"
#include "Point.h"

void IsInCircle(Circle &c, Point &p) //判断点与圆的关系 
{
	//圆心于点距离的平方
	int ret =   
	    ( c.GetCenter().GetX() - p.GetX() ) * ( c.GetCenter().GetX() - p.GetX() ) +  //(x1 - x2) ^ 2 
        ( c.GetCenter().GetY() - p.GetY() ) * ( c.GetCenter().GetY() - p.GetY() );   //(y1 - y2) ^ 2
    //半径的平方 
    int ans = c.GetR() * c.GetR();
    
    if(ret = ans)
    {
    	cout << "点在圆上" << endl;
	}
	else if(ret > ans)
	{
		cout << "点在圆外" << endl; 
	}
	else
	{
		cout << "点在圆内" << endl; 
	}
} 

int main()
{
	//创建圆 
	Circle c1;
	c1.SetR(10);
	
	Point center; //圆心、
	center.SetX(10);
	center.SetY(0); 
	c1.SetCenter(center);
	
	//创建点 
	Point p1;
	p1.SetX(10);
	p1.SetY(10);
	
	IsInCircle(c1, p1);
	return 0;
} 
