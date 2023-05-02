#include<iostream>
using namespace std;

//运算符重载
//---------------------------------------------------------------------------
//4.赋值运算符重载
//C++编译器至少给一个类添加4个函数(前面说三个其实是四个)
//   1.默认构造函数（无参函数体为空）
//   2.默认析构函数（无参函数体为空）
//   3.默认拷贝构造函数，对属性进行值拷贝
//   4.赋值运算符，operator=，对属性进行值拷贝（编译器给的是简单的浅拷贝） 
//    （如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题）

class Person
{
public:
	int* m_age;
	
	Person(int age)//堆区 
	{
		m_age = new int(age);
	}
	
	~Person()//析构释放堆区内存 
	{
		if(m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}
	
	//重载赋值运算符（深拷贝） 
	Person& operator=(Person &p)
	{
		//编译器实现的浅拷贝
		//m_age = p.m_age;
		
		//自己写深拷贝
		//判断 防止自赋值 
		if(this != &p)
		{
			//先判断是否在有属性在堆区，如果有先释放干净，然后再深拷贝 
	        if(m_age != NULL)
			{
				delete m_age;
				m_age = NULL;
		    } 
	        m_age = new int( *(p.m_age) );
		}
		return *this; //加上返回就可以连等了 
	} 
}; 

void test1()
{
	Person p1(18);
	Person p2(20);
	Person p3(30); 
	
	//p2.operator=(p1); //本质 
	p2 = p1;            //化简后
	
	p3 = p2 = p1;
	
	cout << "p1的年龄为：" << *(p1.m_age) << endl;
	cout << "p2的年龄为：" << *(p2.m_age) << endl;
	cout << "p3的年龄为：" << *(p3.m_age) << endl;
}

int main()
{
    test1();
	return 0;
}

