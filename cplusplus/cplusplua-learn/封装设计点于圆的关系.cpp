#include<iostream>
using namespace std;

//���� 
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

//Բ�� 
class Circle
{
private:
	int m_R; //�뾶 
	Piont m_Center; //Բ��     ->  �����п�������һ���࣬��Ϊ����ĳ�Ա 
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

void IsInCircle(Circle &c, Piont &p) //�жϵ���Բ�Ĺ�ϵ 
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
	
	Piont center; //Բ�ġ�
	center.SetX(10);
	center.SetY(0); 
	c1.SetCenter(center);
	
	//������ 
	Piont p1;
	p1.SetX(10);
	p1.SetY(10);
	
	IsInCircle(c1, p1);
	return 0;
} 
