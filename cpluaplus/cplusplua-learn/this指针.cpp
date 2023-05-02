#include<iostream>
using namespace std;

//this指针 
//非静态成员函数，不属于类对象上，也只有一份，也就是多个同类型对象会共用一块代码 
//那么这一块代码如何区分哪个对象调用自己的呢？ -> this指针

//this指针指向被调用的成员函数所属的对象

//this指针是隐含每一个 非静态成员函数 内的一种指针
//this指针不需要定义，直接使用即可

//this指针的用途
//1.当形参和成员变量同名时，可以this指针来区分
//2.在类的 非静态函数 中返回对象本身，可使用return *this; 


//-------------------------------------------------------------------
//1.
class Person1
{
public :
    int age;
    
	Person1(int age)
	{
		//this指针指向被调用的成员函数所属的对象
		this->age = age;
    } 
//public :
//    int m_age;
//    
//	Person1(int age)
//	{
//		m_age = age;
//    } 
}; 

int main1()
{
	Person1 p1(18);
	cout << "p1的年龄为：" << p1.age << endl;
	return 0;
}

//int *A = &a;
//int &A = a; 
//-------------------------------------------------------------------
//2.
class Person
{
public :
    int m_age;
    
	Person(int age)
	{
		m_age = age;
    } 
    
    Person& PersonAddAge(Person &p)
    {
    	m_age += p.m_age;
    	//this 指向p2，*this 就是p2本体 
    	return *this;
	}
}; 

int main()
{
	Person p1(10);
	Person p2(20);
	
	//p2.PersonAddAge(p1);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1); //链式编程思想 
	
	cout << "p2的年龄为：" << p2.m_age << endl;
	return 0;
}
