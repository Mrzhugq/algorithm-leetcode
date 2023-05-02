#include<iostream>
using namespace std;

//C++对象模型和this指针

//在C++中，类内的成员变量和成员属性分开储存
//只有非静态变量才属于类的对象 
//-------------------------------------------------------------------------- 
class Person
{
	
}; 

int main0()
{
	Person p;
	//空对象占用内存一个字节 
	//因为C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址 -> 为了区分不同的空对象 
	cout << "Size of p =" << sizeof(p) << endl;//1 
	
} 




//-------------------------------------------------------------------------- 
class Person1 
{
	int m_age;//非静态成员变量 ，属于类的对象上 
}; 

int main1()
{
	Person1 p;
	//p的大小就是一个int的大小 
	cout << "Size of p =" << sizeof(p) << endl;//4 
} 




//-------------------------------------------------------------------------- 
class Person2
{
	int m_age;//非静态成员变量 ，属于类的对象上 
	static int m_b; //静态成员变量，不属于类对象上 
}; 

int Person2::m_b = 0;

int main2()
{
	Person2 p;
	//p的大小还是一个int的大小 -> 只有非静态变量才属于类的对象  
	cout << "Size of p =" << sizeof(p) << endl;//4 
} 




//-------------------------------------------------------------------------- 
class Person3
{
	int m_age;//非静态成员变量 ，属于类的对象上 
	static int m_b; //静态成员变量，不属于类对象上 
	void func() {} //非静态成员函数，不属于类对象上，也只有一份 
}; 

int Person3::m_b = 0;

int main3()
{
	Person3 p;
	//p的大小还是一个int的大小 -> 只有非静态变量才属于类的对象  
	cout << "Size of p =" << sizeof(p) << endl;//4 
} 



//-------------------------------------------------------------------------- 
class Person4 
{
	int m_age;//非静态成员变量 ，属于类的对象上 
	static int m_b; //静态成员变量，不属于类对象上 
	void func() {}     //非静态成员函数，不属于类对象上，也只有一份 
	static func2() {}  //静态成员函数，也不属于类对象上，也只有一份 
}; 

int Person4::m_b = 0;

int main()
{
	Person4 p;
	//p的大小还是一个int的大小 -> 只有非静态变量才属于类的对象  
	cout << "Size of p =" << sizeof(p) << endl;//4 
} 
