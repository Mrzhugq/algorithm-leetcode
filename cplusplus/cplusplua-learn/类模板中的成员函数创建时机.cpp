#include<iostream>
using namespace std;

//类模板中的成员函数创建时机
//1.普通类中的成员函数一开始就可以创建
//2.类模板中的成员函数在调用时才创建


class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
}; 

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
}; 

template<class T>
class Myclass
{
public:
	T obj;
	void fun1()               //类模板中的成员函数在调用时才创建 
	{
		obj.showPerson1();    //因为编译器也不知道T是什么类型 
	}                         //没法调用showPerson() 
	void fun2()
	{
		obj.showPerson2();
	}
};


int main()
{
	Myclass<Person1> m1;
	m1.fun1();
	//m1.fun2();  //错误不能运行，因为showPerson2()，不是Person1的成员函数 
	return 0;
}

