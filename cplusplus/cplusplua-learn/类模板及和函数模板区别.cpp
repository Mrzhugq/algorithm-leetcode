#include<iostream>
#include<string>
using namespace std;

//2.类模板

//作用：建立一个通用类，数据类型可以不具体指定，用一个虚拟的类型来代表 
//语法：template<class T>   class也可以用typename代替 
//      类 


//-------------------------------------------------------------------------
template<class NameType,class AgeType>
class Person
{
public:
	NameType m_name;
	AgeType m_age;
	Person(NameType name, AgeType age)
	{
		m_name = name;
		m_age = age;
	}
	void Print()
	{
		cout << m_name << endl;
		cout << m_age << endl;
	}
//	string m_name;
//	int m_age;
};

void test1()
{
	Person<string,int> p1("孙悟空",90);
	p1.Print();
}




//-------------------------------------------------------------------------
//类模板与函数模板区别
//1.类模板没有自动类型推导的所以方式
//2.类模板 在模板参数列表中可以有默认参数

template<class NameType,class AgeType = int>
class Person1 
{
public:
	NameType m_name;
	AgeType m_age;
	Person1(NameType name, AgeType age)
	{
		m_name = name;
		m_age = age;
	}
	void Print()
	{
		cout << m_name << endl;
		cout << m_age << endl;
	}
};

void test2()
{
	//1.
    //Person p1("孙悟空",90); //错误，不能自动类型推导
	
	//2.
	//template<class NameType,class AgeType = int> //上面这样写了，有默认参数 
    Person1<string> p2("猪八戒", 80);
    p2.Print();
}
 

int main()
{
	//test1();
	test2();
	return 0;
}

