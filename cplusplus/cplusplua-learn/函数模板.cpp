#include<iostream>
using namespace std;

//泛型编程
//C++另一种编程思想为泛型编程，主要利用的技术是模板
//C++提供两种模板机制 函数模板和类模板

 
//1.函数模板（参数类型重载） 
//函数模板作用:建立一个通用函数其函数返回值和形参类型可以不具体指定,用一个虚拟的类型来代表 
//语法：template 声明创建模板； typename 表明其背后的符号是一种数据类型，也可以用class
//      T 通用的数据类型，名称可以换，通常为大写字母 
//template<typename T> 
//下面紧跟 函数声明或者定义 

//typename 一般是函数模板  ， class 一般是类模板 

//交换整形数
void SwapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
} 

//交换浮点数
void SwapDouble(double &a, double &b)
{
	double temp = a;
	a = b;
	b = temp;
} 
//交换...每种数据都要写一个函数，即使重载也要写，所以用模板
 




//注意2：模板必须确定出T的数据类型，才可以使用
template<typename T>
void func()
{
	cout << "func的调用" << endl;
} 

void test2()
{
	//func(); //错误 
	
	//若想使用必须指明随便一个类型
	func<int>(); 
}





//----------------------------------------------------------------------------
template<typename T>//声明一个模板，告诉编译器后面紧跟的T的一个通用类型
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
} 

void test1()
{
    int a = 10;
	int b = 20; 
	char c = 'c'; 
	//两种方式使用模板
	//1.自动类型推导   -> 注意1：必须推导一致的数据类型T才可以使用 
	Swap(a,b);
	//Swap(a,c); //错误 
	
	//2.显示指定类型
	Swap<int>(a,b); 
	
	cout << "a = " << a << endl; 
	cout << "b = " << b << endl; 
	cout << "c = " << c << endl; 
}


int main()
{
	//test1();
	test2();
	return 0;
}
