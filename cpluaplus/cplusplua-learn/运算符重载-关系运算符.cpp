#include<iostream>
#include<string>
using namespace std;

//运算符重载 
//5.关系运算符重载

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
	Person p1("汤姆",18);
	Person p2("汤姆",20);
	//1.
	//if(p1.operator==(p2)) //本质 
	if(p1 == p2)            //简化后 
	{
		cout << "p1 p2 是相等的" << endl; 
	}
	else
	{
		cout << "p1 p2 是不相等的" << endl;
	}
	//2.
	if(p1 != p2)
	{
		cout << "p1 p2 是不相等的" << endl; 
	}
	else
	{
		cout << "p1 p2 是相等的" << endl;
	}
}

int main()
{
	test1();
	return 0;
} 
