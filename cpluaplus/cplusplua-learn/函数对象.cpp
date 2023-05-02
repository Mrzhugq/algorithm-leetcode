#include<iostream>
#include<string>
using namespace std;
 
//函数对象
//概念：
//    1.重载函数调用操作符的类，其对象称为函数对象
//    2.函数对象使用重载的()时，行为类似函数调用，也叫仿函数
//本质：
//    函数对象(仿函数)是一个类，不是一个函数


//函数对象使用：
//函数对象在使用的时候，可以像普通函数那样调用，可以可以有参数，可以有返回值
//函数对象超出普通函数的概念，函数对象可以有自己的状态
//函数对象可以作为参数传递


//1.
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
}; 

void test1()
{
	MyAdd myadd;  //myadd就是函数对象
	cout << myadd(10,10) << endl; 
}

//2.

class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}
	int count;//可以有属性，记录仿函数调用几次 
};

void test2()
{
	MyPrint myprint;
	myprint("Hello Word");
	myprint("Hello Word");
	myprint("Hello Word");
	myprint("Hello Word");
	cout << myprint.count << endl; //普通函数是没有这样的 
} 

//3.
void DoPrint(MyPrint &m, string test)
{
	m(test);
} 

void test3()
{
	MyPrint myprint;
	DoPrint(myprint,"Hello");
} 
 
 
 
int main()
{
    //test1();
    //test2();
    test3();
	return 0;
}

