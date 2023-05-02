#include<iostream>
using namespace std;

void fun(int &b)
{
	b = 50;
}

int main()
{
	int a = 10;
	int b = 20;
	//引用 -> 数据类型 &别名 = 原名;   -> 指针常量的封装
	
	//引用必须初始化                  int &c;                  ->  错误 
	//引用在初始化后，不可以改变      int &c = a; int &c = b;  ->  错误 
	 
	int &c = a;
	c = 50;
	
	fun(b);
	
	cout << a << endl;
	cout << b << endl;
}






//引用做函数返回值 
//1.不要返回局部变量的引用 
int& test1()
{
	int a = 10;
	return a;
}

//2.函数的调用可以作为左值 
int& test2()
{
	static int a = 10; //静态变量，存放在全局区，函数test2结束后，还存在 
	return a;
}

int main2()
{
	//1.
	int &ret1 = test1();
	cout << ret1<< endl;
	
	//2.
	int &ret2 = test2();
	cout << ret2 << endl;
	test2() = 100; //如果函数的返回值是引用，这个函数调用可以作为左值 
	cout << ret2 << endl;
} 






//引用的本质 -> 一个指针常量 
int main3()
{
	int a = 10;
	int &ret = a; //自动转化为 -> int* const ret = &a; (指针常量)
	
	ret = 20;     //内部发现是引用，自动帮我们转为 -> *ret = 20; 
} 



void Print(const int& val)  //const int& val -> const int* const val; 
{
	//val = 20; //加上const不能修改了 
	cout << val << endl;
}

//常量引用  -> 用来修饰形参，防止误操作 
int main4()
{
	//int& ret = 10; //错误 
	const int& ret = 10;//正确
	//加上const后，编译器将代码修改为 int temp = 10; const int& ret = temp;  
	
	
	int a = 10;
	Print(a);
} 
