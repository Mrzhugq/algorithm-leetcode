#include<iostream>
#include<string> 
#include<typeinfo>
using namespace std;

//类模板对象做函数参数
//就是类模板实例化出的对象，向函数传参的方式 

//三种传入的方式： 
//1.指定传入的类型 -- 直接显示对象的数据模型
//2.参数模板化 -- 将对象中的参数变为模板进行传递
//3.整个类模板化 -- 将这个对象类型 模板化进行传递



template<class T1,class T2>
class Person
{
public:
	Person(T1 name,T2 age)
	{
		m_name = name;
		m_age = age;
	}
	void showPerson()
	{
		cout << m_name << m_age << endl;
	}
	T1 m_name;
	T2 m_age;
};


//1.指定传入的类型 （这种最常用） 
void PrintPerson1(Person<string,int> &p1)
{
	p1.showPerson();
}
void test1()
{
	Person<string,int> p1("汤姆",18);
	PrintPerson1(p1);
}


//2.参数模板化 （类似函数模板） 
template<class T1,class T2>
void PrintPerson2(Person<T1,T2> &p2)
{
	p2.showPerson();
	
	//如果想要看模板中推出了什么类型 -> typeid(T1).name()
	cout << "T1的类型：" << typeid(T1).name() << endl; 
	cout << "T2的类型：" << typeid(T2).name() << endl; 
}
void test2()
{
	Person<string,int> p2("杰克",90);
	PrintPerson2(p2);
}



//3.整个类模板化 （类似函数模板）
template<class T> 
void PrintPerson3(T &p3)
{
	p3.showPerson();
}
void test3()
{
	Person<string,int> p3("哈哈",99);
	PrintPerson3(p3);
}




int main()
{

 	//test1(); 
 	//test2(); 
 	test3(); 
	return 0;
}
 
