#include<iostream>
using namespace std;

//---------------------------------------------------------------------------------------- 
//�̳�ͬ����Ա����ʽ
//���⣺������������г���ͬ���ĳ�Ա�����ͨ��������󣬷��ʵ�������߸�����ͬ���������أ�
//1. ��������ͬ����Ա��ֱ�ӷ��ʼ���
//2. ���ʸ���ͬ����Ա����Ҫ��������

class Base
{
public:
	int m_a;
	
	Base()
	{
		m_a = 100;
	}
	void func()
	{
		cout << "Base-func ����" << endl;
    } 
    
   	void func(int a)
	{
		cout << "Base-func(int a) ����" << endl;
    } 
}; 

class Son : public Base 
{
public:
	int m_a;
	
	Son()
	{
		m_a = 200;
	}
	void func()
	{
		cout << "Son-func ����" << endl;
    } 
}; 

//ͬ����Ա���� 
void test1()
{
    Son s;
    cout << "Son �µ� m_a = " << s.m_a << endl;//��ֱ�ӷ���
    
    cout << "Base �µ� m_a = " << s.Base::m_a<< endl;//ͨ��������ʸ���ͬ����Ա����Ҫ�������� 
}

//ͬ����Ա����  ��ǰ��һ�� 
void test2()
{
	Son s;
	
	//1. 
	s.func();
	s.Base::func();
	
	//2.
	//��������г����븸��ͬ���ĳ�Ա�����������л����ص������е�����ͬ����Ա����
	//��Ҫ���ø����е�ͬ����Ա����������������� 
	//s.func(10);    //����� 
	s.Base::func(10);//��ȷ 
}




//----------------------------------------------------------------------------------------
//�̳�ͬ����̬����ʽ
//��̬�ͷǾ�̬��Ա����ͬ��������ʽһ�� -> ֻ���������ַ�ʽ��ʽ����(ͨ������ͨ������) 
//1. ��������ͬ����Ա��ֱ�ӷ��ʼ���
//2. ���ʸ���ͬ����Ա����Ҫ��������

class Base1
{
public:
	static int m_a;
	
	static void func()
	{
		cout << "Base1 �µ� static void func()�ĵ���" << endl; 
	}
	
	static void func(int a)
	{
		cout << "Base1 �µ� static void func(int a)�ĵ���" << endl; 
	}
};

//��̬��Ա������Ҫ�����ʼ�� 
int Base1::m_a = 10;

class Son1 : public Base1
{
public:
	static int m_a;
	
	static void func()
	{
		cout << "Son1 �µ� static void func()�ĵ���" << endl; 
	}
}; 

int Son1::m_a = 20;


//ͬ����̬��Ա���� 
void test3()
{
	//ͨ��������ʾ�̬���� 
	Son1 s1;
	cout << "Son1�µ� m_a = " << s1.m_a << endl; 
	cout << "Base1�µ� m_a = " << s1.Base1::m_a <<endl; 
	
	//ͨ���������ʾ�̬����
 	cout << "Son1�µ� m_a = " << Son1::m_a << endl;
 	cout << "Base1�µ� m_a = " << Son1::Base1::m_a << endl;
 	//Son1::Base1::m_a ��ͨ��������ʸ����е�m_a 
 	//��һ����������ͨ��������ʽ���ʣ��ڶ��������������Base1�������� 
 	
 	//cout << "Base1�µ� m_a = " << Base1::m_a << endl; //Base1::m_a �����ֱ�ӴӸ���ֱ�ӷ���m_a 
}

//ͬ���ľ�̬��Ա���� (��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����)
void test4()
{
	//ͨ��������ʾ�̬���� 
	Son1 s2;
	s2.func();
	s2.Base1::func();
	
	//ͨ���������ʾ�̬����
	Son1::func();
	Son1::Base1::func();
	
	//Son1::func(100);  //����,�ͷǾ�̬һ��
	Son1::Base1::func(100); 
} 



int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0; 
}
