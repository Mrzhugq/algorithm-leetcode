#include<iostream>
using namespace std;

//函数的默认值
//注意：
//1.如果某个位置已经有了默认参数，那么从个位置往后，从左到右都必须有默认值 
//2.如果函数的声明有默认参数，函数的实现就不能有默认参数
//声明和实现只能有一个有默认参数 
int fun1(int a, int b = 10, int c = 20)
{
	return a+b+c;
} 

int main2()
{
	int ret1 = fun1(10);    //如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值 
	cout << ret1 << endl;
	int ret2 = fun1(10,20);
	cout << ret2 <<endl;
} 






//函数的占位参数(占位参数还可以有默认值)
void fun2(int a, int)
{
	cout << "this is fun2" << endl;
}

void fun3(int a, int = 10)
{
	cout << "this is fun2" << endl;
}

int main1()
{
	//fun2(10);这样不对  ->   fun3(10);这样对 
	fun2(10,20);
	return 0;
} 





//函数重载  
//作用 : 函数名可以相同，提高复用性 
//满足函数重载条件
//1.同一个作用域下
//2.函数名字相同
//3.函数的参数类型不同 或者 个数不同 或者 顺序不同 (函数的返回值不可以作为函数重载的条件)
int fun4()
{
	cout << "fun4的调用" << endl; 
} 

int fun4(int a)
{
	cout << "fun4(int a)的调用" << endl; 
} 

int main3()
{
	//fun4();
	fun4(10);
	return 0;
}
 


//函数重载的注意事项
//1.引用作为重载的条件
void fun5(int& a)  //int& a = 10; 不合法 
{
	cout << "fun5(int& a)的调用" << endl; 
} 
void fun5(const int& a)  //const int& a = 10; 合法 
{
	cout << "fun5(const int& a)的调用" << endl; 
}

//2.函数重载碰到默认参数
void fun6(int a, int b = 10) 
{
	cout << "fun6(int a, int b = 10)" << endl; 
} 
void fun6(int a)   
{
	cout << "fun6(int a)的调用" << endl; 
} 


int main()
{
	int a = 10;
	fun5(a);//注意区别 
	fun5(10);
	
	fun6(10);//错误 ，编译器不知道要调用上面还是下面的fun6，出现二义性，要尽量避免 
}
