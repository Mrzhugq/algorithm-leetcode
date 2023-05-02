#include<iostream>
using namespace std;

//----------------------------------------------------------------------------- 
//拷贝构造函数的调用时机
//1.使用一个创建完毕的对象来初始化一个新对象
//2.值传递的方式给函数参数传值
//3.以值方式返回局部对象

class Person
{
public :
	int m_age;

    Person()
	{
		cout << "Person 无参构造函数 的调用" << endl;
	}
	Person(int age)//有参构造
	{
		m_age = age; 
		cout << "Person 有参构造函数 的调用" << endl;
    } 
    Person(const Person &p)//拷贝构造 
    {
    	m_age = p.m_age;
    	cout << "Person 拷贝构造函数 的调用" << endl;
	}
	
    ~Person()
	{
		cout << "Person 析构函数 的调用" << endl;
    } 
}; 

//1.使用一个创建完毕的对象来初始化一个新对象
void test1()
{
	Person p1(20);
	Person p2(p1);
	
	cout << "p2的年龄为：" << endl; 
}

//2.值传递的方式给函数参数传值
void DoWork(Person p)
{
	
}
void test2()
{
	Person p;
	DoWork(p); 
}

//3.以值方式返回局部对象  -> 这里可能编译器优化了不显示调用拷贝构造函数 
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

