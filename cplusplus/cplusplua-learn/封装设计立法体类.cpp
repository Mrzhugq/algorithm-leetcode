#include<iostream>
using namespace std;

class Cube
{
	//���� 
private :
	int m_L;//�� 
	int m_H;//�� 
	int m_W;//�� 
	
	//��Ϊ 
public:
	void SetL(int L)
	{
		m_L = L;
	}
	int GetL()
	{
		return m_L;
	}
	
	void SetW(int W)
	{
		m_W = W;
	}
	int GetW()
	{
		return m_W;
	}
	
	void SetH(int H)
	{
		m_H = H;
	}
	int GetH()
	{
		return m_H;
	}
	
	int calculteS()//��� 
	{
		return 2*m_L*m_W + 2*m_W*m_H + 2*m_L*m_H;
	}
	int calculteV()//���
	{
		return m_L * m_W * m_H;
    } 
    
    bool IsSameByclass(Cube &c)  //ע�������Ҫһ������ 
    {
   		if(m_H == c.GetH() 
	      && m_L == c.GetL()
		  && m_W == c.GetW())
	    {
		return true;	
	    }
	    return false;
	}
};

bool IsSame(Cube &c1, Cube &c2)
{
	if(c1.GetH() == c2.GetH() 
	    && c1.GetL() == c2.GetL()
		&& c1.GetW() == c2.GetW())
	{
		return true;	
	}
	return false;
}

int main()
{
	Cube c1;
	c1.SetH(10);
	c1.SetL(10);
	c1.SetW(10);
	cout << "c1�����Ϊ: " << c1.calculteS() << endl;
	cout << "c1�����Ϊ: " << c1.calculteV() << endl;
	
	Cube c2; 
	c2.SetH(10);
	c2.SetL(10);
	c2.SetW(10);
	
	//����ȫ�ֺ����ж����������Ƿ���� 
	int ret1 = IsSame(c1, c2);
	cout << ret1 << endl;
	
	//���ó�Ա�����ж����������Ƿ���� 
	int ret2 = c1.IsSameByclass(c2);
	cout << ret2 << endl;
	return 0;
}
