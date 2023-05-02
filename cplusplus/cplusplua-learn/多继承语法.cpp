#include<iostream>
using namespace std;

//多继承语法

//C++中允许一个类继承多个类
//语法： class 子类 ：继承方式 父类1 , 继承方式 父类2 ...

//多继承可能会引发父类中有同名成员出现，需要加作用域区分 
//C++实际开发中不推荐用多继承


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
	//当父类中出现同名成员，需要加作用域区分 
	cout << "Base1::m_a = " << s.Base1::m_a << endl; 
	cout << "Base2::m_a = " << s.Base2::m_a << endl; 
	return 0;
}

