#include<iostream>
using namespace std;


//const修饰成员函数
//1.常函数
//成员函数后加const后我们称这个函数为常函数
//常函数内不可修改成员属性
//成员属性声明时加关键字mutable后，在常函数中依然可以修改

//2.常对象
//声明对象前加const称该对象为常对象
//常对象只能调用常函数


//------------------------------------------------------------------
//1.常函数 
class Person
{
public:
	int m_a;
	mutable int m_b;//特殊，即使在 常函数中或者在常对象 中，也可以修改这个值 
	
	void ShoePerson() const
	{
		m_b = 200;//正确因为有mutable 
		
		m_a = 100; //错误 
		//相当于this->m_a = 100; //错误
		
		//this指针的本质是 指针常量，Person* const this；指针指向是不可以修改的 
		//this = NULL;    //这样错误 
		//如果在成员函数名字后面加上const，就相当于 const Person* const this；
		//所以this指针指向的值也不可以修改
		//this->m_a = 100;//所以这样是错误的 
	}
};

int main()
{
	Person p;
	p.ShoePerson(); 
	return 0;
}

//--------------------------------------------------------------------
//2.常对象 

class Person1
{
public:
	int m_a;
	mutable int m_b;//特殊，即使在 常函数中或者在常对象 中，也可以修改这个值
	
	Person1() //创建常对象报错，需要自己写一个构造函数，别的编译器不用写 
	{
		
	}
	
	void ShoePerson1() const
	{
		cout << "常函数的调用" << endl; 
	}
	
	void func()
	{
		cout << "普通成员函数的调用" << endl; 
	}
};


int main1()
{
	const Person1 p1;//常对象p1 
	//p1.m_a = 100; //错误
	p1.m_b = 200; //正确
	
	//常对象只能调用常函数
	//p1.func(); //错误 -> 因为普通成员函数可能会篡改常对象的属性，所以非法 
	p1.ShoePerson1(); //正确 
} 




