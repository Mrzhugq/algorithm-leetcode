#include<iostream>
using namespace std;

//----------------------------------------------------------------------------- 
//�������캯���ĵ���ʱ��
//1.ʹ��һ��������ϵĶ�������ʼ��һ���¶���
//2.ֵ���ݵķ�ʽ������������ֵ
//3.��ֵ��ʽ���ؾֲ�����

class Person
{
public :
	int m_age;

    Person()
	{
		cout << "Person �޲ι��캯�� �ĵ���" << endl;
	}
	Person(int age)//�вι���
	{
		m_age = age; 
		cout << "Person �вι��캯�� �ĵ���" << endl;
    } 
    Person(const Person &p)//�������� 
    {
    	m_age = p.m_age;
    	cout << "Person �������캯�� �ĵ���" << endl;
	}
	
    ~Person()
	{
		cout << "Person �������� �ĵ���" << endl;
    } 
}; 

//1.ʹ��һ��������ϵĶ�������ʼ��һ���¶���
void test1()
{
	Person p1(20);
	Person p2(p1);
	
	cout << "p2������Ϊ��" << endl; 
}

//2.ֵ���ݵķ�ʽ������������ֵ
void DoWork(Person p)
{
	
}
void test2()
{
	Person p;
	DoWork(p); 
}

//3.��ֵ��ʽ���ؾֲ�����  -> ������ܱ������Ż��˲���ʾ���ÿ������캯�� 
Person DoWork2()
{
	Person p1;
	return p1;
}
void test3()
{
	Person p = DoWork2();
}


int main()
{
	//test1(); 
	test2();
	//test3(); 
	return 0;
}




//----------------------------------------------------------------------------- 

