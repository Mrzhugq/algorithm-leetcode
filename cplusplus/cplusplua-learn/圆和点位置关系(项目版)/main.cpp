#include "Circle.h"
#include "Point.h"

void IsInCircle(Circle &c, Point &p) //�жϵ���Բ�Ĺ�ϵ 
{
	//Բ���ڵ�����ƽ��
	int ret =   
	    ( c.GetCenter().GetX() - p.GetX() ) * ( c.GetCenter().GetX() - p.GetX() ) +  //(x1 - x2) ^ 2 
        ( c.GetCenter().GetY() - p.GetY() ) * ( c.GetCenter().GetY() - p.GetY() );   //(y1 - y2) ^ 2
    //�뾶��ƽ�� 
    int ans = c.GetR() * c.GetR();
    
    if(ret = ans)
    {
    	cout << "����Բ��" << endl;
	}
	else if(ret > ans)
	{
		cout << "����Բ��" << endl; 
	}
	else
	{
		cout << "����Բ��" << endl; 
	}
} 

int main()
{
	//����Բ 
	Circle c1;
	c1.SetR(10);
	
	Point center; //Բ�ġ�
	center.SetX(10);
	center.SetY(0); 
	c1.SetCenter(center);
	
	//������ 
	Point p1;
	p1.SetX(10);
	p1.SetY(10);
	
	IsInCircle(c1, p1);
	return 0;
} 
