#include<iostream>
using namespace std;

//��̳��﷨

//C++������һ����̳ж����
//�﷨�� class ���� ���̳з�ʽ ����1 , �̳з�ʽ ����2 ...

//��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������ 
//C++ʵ�ʿ����в��Ƽ��ö�̳�


class Base1
{
public:
	int m_a;
	Base1()
	{
		m_a = 10;
	}
}; 

class Base2
{
public:
	int m_a;
	Base2()
	{
		m_a = 20;
	}
};

class Son : public Base1 , public Base2 
{
public:
	int m_c;
	int m_d;
	Son()
	{
		m_c = 30;
		m_d = 40;
	}
};

int main()
{
	Son s;
	//�������г���ͬ����Ա����Ҫ������������ 
	cout << "Base1::m_a = " << s.Base1::m_a << endl; 
	cout << "Base2::m_a = " << s.Base2::m_a << endl; 
	return 0;
}

