#include<iostream>
using namespace std;



//---------------------------------------------------------------------------- 
//默认情况下，如果创建一个类，C++编译器至少给一个类添加3个函数 
//1.默认构造函数（无参，函数体为空） 
//2.默认析构函数（无参函数体为空） 
//3. 默认拷贝构造函数，对属性进行值拷贝

//构造函数调用规则如下： 
//如果用户定义有参构造函数，C++不在提供默认无参构造函数，但会提供默认拷贝函数
//如果用户定义拷贝构造函数，C++不在提供其他构造函数 

class Person
{
public :

    int m_age;
	 
	Person()
	{
		cout << "Person的默认构造函数调用" << endl; 
	}
	Person(int age)
	{
		m_age = age;
		cout << "Person的有参构造函数调用" << endl; 
	}
	Person(const Person &p)
	{
		m_age = p.m_age;
		cout << "Person的拷贝构造函数调用" << endl; 
	}
	~Person()
	{
		cout << "Person的默认析构函数调用" << endl;
	}
}; 

void test1()
{
	Person p1;
	p1.m_age = 18;
	
	//我们自己写拷贝构造函数
	//Person p2(p1);
	//cout << "p2的年龄为：" << p2.m_age << endl;
	
	//如果我们自己不写拷贝构造函数(上面的拷贝构造函数记得注释掉)，编译器也会帮我们加上
    Person p2(p1);
    cout << "p2的年龄为：" << p2.m_age << endl;

}

void test2()
{
	//如果我们写了有参构造函数，不写无参构造函数(上面的无参构造函数记得注释掉)，
	//C++不在提供默认无参构造函数，但会提供默认拷贝函数
	//Person p;  //因为没有默认构造函数所以这行会报错 
	
	//但会提供默认拷贝函数
	Person p1(20);
	Person p2(p1);
    cout << "p2的年龄为：" << p2.m_age << endl;
}

void test3()
{
	//如果我们只写了拷贝构造函数(上面的的有参和无参构造函数记得注释掉)
	//C++不在提供其他构造函数 
	Person p1;
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
} 
