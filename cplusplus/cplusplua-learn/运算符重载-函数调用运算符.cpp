#include<iostream>
#include<string>
using namespace std;

//运算符重载
//6.函数调用运算符 ()
//    1.函数调用运算符()也可以重载
//    2.由于重载后使用的方式非常像函数的调用，因此称为仿函数
//    3.仿函数没有固定写法，非常灵活 

//----------------------------------------------------------------------------- 
//打印输出类 
class Myprint
{
public:
	//()运算符重载成员函数 
    void operator()(string test)
	{
		cout << test << endl; 
	} 
//	Myprint()
//	{
//		cout << "默认构造" << endl; 
//	}
}; 

void MyPrint1(string test)//全局函数 
{
	cout << test << endl;
}

void test1()
{
	Myprint myprint;
	//myprint.operator("Hello Word");  //本质
    myprint("Hello Word");             //化简后 
	Myprint ()("Hello Word");//匿名对象调用重载()，Myprint ()是利用默认构造创建一个匿名对象 
	
	MyPrint1("Hello Word");            //这个是函数，不是运算符重载，他们使用时非常像 
}



//----------------------------------------------------------------------------- 
//仿函数没有固定写法，非常灵活 
//加法类

class Myadd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
}; 

void test2()
{
	Myadd myadd;
	int ret = myadd(10,20);
	cout << ret << endl;
	
	//匿名函数对象 -> Myadd() ->  该行结束后立即被释放 
	cout << Myadd()(10,20) << endl; 
}

int main()
{
	test1();
	//test2();
	return 0;
}

