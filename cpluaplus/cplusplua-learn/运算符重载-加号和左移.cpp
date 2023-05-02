#include<iostream>
using namespace std;

//运算符重载
//概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

//----------------------------------------------------------------------------------
//1.通过成员函数重载加号 
class Person
{
public:
	int m_a;
	int m_b;
	
//	Person operator+(Person &p)//通过成员函数重载加号，这个成员函数名字必须叫operator+
//	{
//		Person temp;
//		temp.m_a = m_a + p.m_a;
//		temp.m_b = m_b + p.m_b;
//		return temp;
//	}
};

//通过全局函数重载加号，名字也得必须叫operator+ 
Person operator+(Person &p1, Person &p2)
{
    Person temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
} 
//函数重载 
Person operator+(Person &p1, int num)
{
    Person temp;
	temp.m_a = p1.m_a + num;
	temp.m_b = p1.m_b + num;
	return temp;
} 

void test1()
{
	Person p1;
	p1.m_a = 10;
	p1.m_b = 10;
	Person p2;
	p2.m_a = 20;
	p2.m_b = 20;
	
	//我们要实现p1和p2的属性相加赋给p3 
	
	//1.通过成员函数重载加号 
	//Person p3 = p1.operator+(p2); //本质 
	Person p3 = p1 + p2;            //可以简化为这样 
	//2.通过全局函数重载加号
	//Person p4 = operator+(p1,p2); //本质 
	Person p4 = p1 + p2;            //也可以简化为这样 
	
	//运算符重载，也可以发生函数重载 
	//Person p5 = operator+(p1,100)
	Person p5 = p1 + 100;//Person + int 也需要自己写 
	  
	cout << p3.m_a <<" "<< p3.m_b <<endl;
	cout << p4.m_a <<" "<< p4.m_b <<endl;
	cout << p5.m_a <<" "<< p5.m_b <<endl;
}
 
 
 
 
//----------------------------------------------------------------------------------
//2.左移运算符重载
//作用：输出自定义的数据类型 

class Person2
{
public://可以把属性设置为私有，然后把 operator<< 全局函数设为friend 
	int m_A;
	int m_B;
	//利用成员函数重载 左移运算符 最后本质是p.operator<<(cout) - 简化为 p << cout 
	//一把不会利用成员函数重载<<运算符，因为简化后p在左侧，和原始的输出，不太一样 
//	void operator<<(ostream &cout)
//	{
//		
//	}
};

//只能运用全局函数重载左移运算符 -> cout 是标准的输出流对象ostream 
//102行想要继续输出endl，必须返回cout，还得要以引用方式返回(ostream&) -> cout << endl;(这句就是调用库里面的了) 
ostream& operator<<(ostream &cout, Person2 &p)  
{
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
} 

void test2()
{
	Person2 p;
	p.m_A = 10;
	p.m_B = 20;
	//operator<<(cout, p); //本质 
	cout << p << endl;     //简化后 (链式编程) 
}







int main()
{
	//test1();
	test2(); 
} 
