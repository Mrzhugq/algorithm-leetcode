#include<iostream>
using namespace std;

//继承方式

//语法 class 子类 ： 继承方式 父类
//子类 就是 派生类
//父类 就是 基类

//公共继承 public 
//保护继承 protected
//私有继承 private

//公共继承 父类中的私有子类中访问不到，父类中的其他属性按照 原先的的访问权限 给子类 
//保护继承 父类中的私有子类中访问不到，父类中的其他属性都变为 保护权限 给子类 
//私有继承 父类中的私有子类中访问不到，父类中的其他属性都变为 私有权限 给子类 

class Base1
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
}; 

class Son1 : public Base1
{
public:
	void func()
	{
		m_a = 10;   //公共还是公共权限 
		m_b = 20;   //保护还是保护权限 
		//m_c = 30; //错误(私有子类访问不到) 
	}
};

class Son2 : protected Base1
{
public:
	void func()
	{
		m_a = 10;   //公共变为保护权限 
		m_b = 20;   //保护还是保护权限 
		//m_c = 30; //错误(私有子类访问不到) 
	}
};

class Son3 : private Base1
{
public:
	void func()
	{
		m_a = 10;   //公共变为私有权限 
		m_b = 20;   //保护变为私有权限 
		//m_c = 30; //错误(私有子类访问不到) 
	}
};

void test1()
{
	Son1 s1;
	s1.m_a = 10;
	//s1.m_b = 20;//错误 
	//s1.m_c = 20;//错误 
}

void test2()
{
	Son1 s1;
	//s1.m_a = 10;//错误，变为保护权限了类外访问不到 
	//s1.m_b = 20;//错误 
	//s1.m_c = 20;//错误 
}

void test3()
{
	Son1 s1;
	//s1.m_a = 10;//错误，变为私有权限了类外访问不到 
	//s1.m_b = 20;//错误 
	//s1.m_c = 20;//错误 
}

int main()
{
	test1(); 
}

