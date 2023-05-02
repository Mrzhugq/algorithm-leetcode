#include<iostream>
using namespace std;

//纯虚函数和抽象类
//在多态中，通常父类中虚函数的首先是毫无意义的，主要都是调用子类重写的内容
//因此我们可以虚函数改为纯虚函数 语法：virtual 返回值类型 函数名(参数列表) = 0;
//当类中有了纯虚函数，这个类也称为 抽象类

//抽象类(接口类)特点
//无法实例化对象
//子类必须重写抽象类中的纯虚函数，否则也属于抽象类
 
class Base
{
public:
	//纯虚函数 
	virtual void func() = 0;
};

class Son : public Base 
{
public:
	void func()
	{
		cout << "func 调用" << endl; 
	}
}; 

int main()
{
	//Son s;//子类重写完才能实例化对象 
	Base* b = new Son;
	b->func();
	delete b;
	 
	return 0;
}
