#include<iostream>
using namespace std;

//继承中的构造和析构 
//问题：父类和子类的构造和析构顺序是谁先谁后？
 
//
class Base
{
public:
	Base()
	{
		cout << "Base的构造函数" << endl; 
	}
	~Base()
	{
		cout << "Base的析构函数" << endl; 
	}
}; 

class Son : public Base 
{
public:
	Son()
	{
		cout << "Son的构造函数" << endl; 
	}
	~Son()
	{
		cout << "Son的析构函数" << endl; 
	}
}; 


int main()
{
	//Base b;
	
	//先构造父类，后构造子类
	//析构一般和构造相反，先析构子类，后析构父类 
	Son s;
	return 0;
}

