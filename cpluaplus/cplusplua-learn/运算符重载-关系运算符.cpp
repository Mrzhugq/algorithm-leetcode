#include<iostream>
#include<string>
using namespace std;

//��������� 
//5.��ϵ���������

class Person
{
public:
	string m_name;
	int m_age;
	
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	//1.
	bool operator==(Person &p)
	{
		if(m_name == p.m_name
		    && m_age == p.m_age)
        {
        	return true;
		}
		else
		{
			return false;
		}
	}
	//2.
	bool operator!=(Person &p)
	{
		if(m_name == p.m_name
		    && m_age == p.m_age)
        {
        	return false;
		}
		else
		{
			return true;
		}
	}
};

void test1()
{
	Person p1("��ķ",18);
	Person p2("��ķ",20);
	//1.
	//if(p1.operator==(p2)) //���� 
	if(p1 == p2)            //�򻯺� 
	{
		cout << "p1 p2 ����ȵ�" << endl; 
	}
	else
	{
		cout << "p1 p2 �ǲ���ȵ�" << endl;
	}
	//2.
	if(p1 != p2)
	{
		cout << "p1 p2 �ǲ���ȵ�" << endl; 
	}
	else
	{
		cout << "p1 p2 ����ȵ�" << endl;
	}
}

int main()
{
	test1();
	return 0;
} 
