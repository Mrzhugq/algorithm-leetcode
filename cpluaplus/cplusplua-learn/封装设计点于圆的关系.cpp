#include<iostream>
using namespace std;

//点类 
class Piont
{
private :
    int m_X;
    int m_Y;
public :
	void SetX(int x)
	{
		m_X = x;
	}
	int GetX()
	{
		return m_X;
	}
	
	void SetY(int Y)
	{
		m_Y = Y;
	}
	int GetY()
	{
		return m_Y;
	}
};

//圆类 
class Circle
{
private:
	int m_R; //半径 
	Piont m_Center; //圆心     ->  在类中可以让另一个类，作为本类的成员 
public:
	void SetR(int R)
	{
		m_R = R;
	}
	int GetR()
	{
		return m_R;
	}
	
	void SetCenter(Piont center)
	{
		m_Center = center;
	}
	Piont GetCenter()
	{
		return m_Center;
	}
	
};

void IsInCircle(Circle &c, Piont &p) //判断点与圆的关系 
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
	
	Piont center; //圆心、
	center.SetX(10);
	center.SetY(0); 
	c1.SetCenter(center);
	
	//创建点 
	Piont p1;
	p1.SetX(10);
	p1.SetY(10);
	
	IsInCircle(c1, p1);
	return 0;
} 
