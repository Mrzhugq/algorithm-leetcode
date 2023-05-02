#include<iostream>
using namespace std;

//浅拷贝就是 简单的赋值拷贝操作
//深拷贝就是 在堆区重复申请空间，进行拷贝操作 

class Person
{
public :

    int m_age;//年龄 
    int *m_height;//身高 
    
	Person()
	{
		cout << "Person的默认构造函数调用" << endl; 
	}
	Person(int age, int height)
	{
		m_age = age;
		m_height = new int(height);
		cout << "Person的有参构造函数调用" << endl; 
	}
	Person(const Person &p)
	{
		//这个是类似编译器提供的浅拷贝 
		//m_age = p.m_age;
		//m_height = p.m_height;
		
		//自己写深拷贝 
		m_age = p.m_age;
		int *height = new int( *(p.m_height) );
		m_height = height;
		cout << "Person的拷贝构造函数调用" << endl; 
	}
	
	~Person()
	{
		//释放堆区开辟的空间
		if(m_height != NULL)
		{
		    delete m_height;
			m_height = NULL; 
		}
		cout << "Person的默认析构函数调用" << endl;
	}
};

//浅拷贝 
void test1()
{
	Person p1(10, 180);
	cout << "p1年龄为：" << p1.m_age << " p1的身高为：" << *(p1.m_height) << endl;
	
	Person p2(p1);//如果我们没写拷贝构造函数，使用的是编译器的拷贝构造函数(浅拷贝) 
	cout << "p2年龄为：" << p1.m_age << " p2的身高为：" << *(p1.m_height) << endl;
	//这里应该程序崩溃，因为p2身高是浅拷贝，p1 p2的m_height指向堆区上相同的一片区域
	//执行到这里，p2 p1都会调用析构函数释放空间，所以该空间被练习释放了两次，以至于崩溃
	//浅拷贝可能带来的问题就是 堆区的内存重复释放 
}


//深拷贝 -> 每次拷贝都要重新申请空间 
void test2()
{
    Person p1(10, 180);
	cout << "p1年龄为：" << p1.m_age << " p1的身高为：" << *(p1.m_height) << endl;
	
	Person p2(p1);//使用了我们自己写的 深拷贝 构造函数 -> 不会崩溃 
	cout << "p2年龄为：" << p1.m_age << " p2的身高为：" << *(p1.m_height) << endl;
} 


int main()
{
	//test1();
	test2();
	return 0;
}
