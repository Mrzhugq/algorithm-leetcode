#include<iostream>
#include<string>
using namespace std;


//----------------------------------------------------------
//静态成员 -> 前面加上static 
//1.静态成员变量
//所有对象共享同一份数据
//在编译阶段分配空间
//类内声明，类外初始化 

class Person
{
public:
	static int m_A;
	
}; 

//类内声明，类外初始化 
int Person::m_A = 10;

int main1()
{
	Person p;
	cout << p.m_A << endl;//10
	
	Person p2;
	p2.m_A = 20;
	cout << p.m_A << endl;//20  ->  所有对象共享同一份数据
	
	//静态成员变量 不属于某一个对象上，所有对象都共享同一份数据
	//所以静态成员变量有两种访问方式
	//1.通过对象进行访问(就是上面那种)
	
	//2.通过类名进行访问(静态成员变量也是有访问权限的,如果设为private,类外这里是访问不了的) 
	cout << Person::m_A << endl;
	
	return 0;
}



//----------------------------------------------------------
//2.静态成员函数（也有访问权限） 
//所有对象共享一个函数
//静态成员函数只能访问静态成员变量

class Phone
{
public:
    static int m_a;//静态成员变量 
    int b;//非静态 

	static void func()
	{
		m_a = 200;//静态成员函数 可以能访问 静态成员变量
		//b = 100;  //静态成员函数 不可以能访问 非静态成员变量(无法区分到底是哪个对象的b属性) 
		cout << "static void func 的调用" << endl;
	}
	
};

int Phone::m_a = 100; 

int main()
{
	//1.通过对象访问 
	Phone ph1;
	ph1.func();
	
	//2.通过类名访问
    Phone::func(); 
}
