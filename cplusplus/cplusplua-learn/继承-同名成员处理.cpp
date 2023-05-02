#include<iostream>
using namespace std;

//---------------------------------------------------------------------------------------- 
//继承同名成员处理方式
//问题：当父类和子类中出现同名的成员，如何通过子类对象，访问到子类或者父类中同名的数据呢？
//1. 访问子类同名成员，直接访问即可
//2. 访问父类同名成员，需要加作用域

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
		cout << "Base-func 调用" << endl;
    } 
    
   	void func(int a)
	{
		cout << "Base-func(int a) 调用" << endl;
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
		cout << "Son-func 调用" << endl;
    } 
}; 

//同名成员属性 
void test1()
{
    Son s;
    cout << "Son 下的 m_a = " << s.m_a << endl;//可直接访问
    
    cout << "Base 下的 m_a = " << s.Base::m_a<< endl;//通过子类访问父类同名成员，需要加作用域 
}

//同名成员函数  和前面一样 
void test2()
{
	Son s;
	
	//1. 
	s.func();
	s.Base::func();
	
	//2.
	//如果子类中出现与父类同名的成员函数，子类中会隐藏掉父类中的所有同名成员函数
	//即要调用父类中的同名成员函数，必须加作用域 
	//s.func(10);    //错误的 
	s.Base::func(10);//正确 
}




//----------------------------------------------------------------------------------------
//继承同名静态处理方式
//静态和非静态成员出现同名，处理方式一样 -> 只不过有两种方式方式罢了(通过对象，通过类名) 
//1. 访问子类同名成员，直接访问即可
//2. 访问父类同名成员，需要加作用域

class Base1
{
public:
	static int m_a;
	
	static void func()
	{
		cout << "Base1 下的 static void func()的调用" << endl; 
	}
	
	static void func(int a)
	{
		cout << "Base1 下的 static void func(int a)的调用" << endl; 
	}
};

//静态成员属性需要类外初始化 
int Base1::m_a = 10;

class Son1 : public Base1
{
public:
	static int m_a;
	
	static void func()
	{
		cout << "Son1 下的 static void func()的调用" << endl; 
	}
}; 

int Son1::m_a = 20;


//同名静态成员属性 
void test3()
{
	//通过对象访问静态属性 
	Son1 s1;
	cout << "Son1下的 m_a = " << s1.m_a << endl; 
	cout << "Base1下的 m_a = " << s1.Base1::m_a <<endl; 
	
	//通过类名访问静态属性
 	cout << "Son1下的 m_a = " << Son1::m_a << endl;
 	cout << "Base1下的 m_a = " << Son1::Base1::m_a << endl;
 	//Son1::Base1::m_a 是通过子类访问父类中的m_a 
 	//第一个：：代表通过类名方式访问，第二个：：代表访问Base1作用域下 
 	
 	//cout << "Base1下的 m_a = " << Base1::m_a << endl; //Base1::m_a 这个是直接从父类直接访问m_a 
}

//同名的静态成员函数 (静态成员函数只能访问静态成员变量)
void test4()
{
	//通过对象访问静态函数 
	Son1 s2;
	s2.func();
	s2.Base1::func();
	
	//通过类名访问静态函数
	Son1::func();
	Son1::Base1::func();
	
	//Son1::func(100);  //错误,和非静态一样
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
