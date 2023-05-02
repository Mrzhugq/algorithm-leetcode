#include<iostream>
using namespace std;


//运算符重载
//---------------------------------------------------------------------------
//3.递增运算符重载(递减一样) 
//作用：通过重载递增运算符，实现自己的整形数据

//自定义整形 
class MyInteger
{
	friend ostream& operator<<(ostream &cout,const MyInteger &myint);
private:
	int m_num;
public:
	MyInteger()
	{
		m_num = 0;
	}
	//重载前置++运算符
	//不返回引用无法链式编程，(返回引用)是为了一直对一个数据进行操作 
	MyInteger& operator++()//返回类型是MyInteger&,注意是&方式返回，++(++myint)这样结果才能正确 
	{
		//先将属性++ 
		m_num++;
		//再将自身做返回，以便于42行的输出 
		return *this;
	}
	
	//重载后置++运算符 -> 不能链式 
	//这里的返回类型(没加引用)，因为我们返回temp是局部变量，函数执行完就会被释放
	//如果再按照引用返回，就是非法操作(temp)了，因为temp已经被释放了 
	//可以在前面加个const -> const MyInteger operator++(int) 
	MyInteger operator++(int)//int占位参数，用来区分前置和后置递增 
	{
		//先 记录当前结果
		MyInteger temp = *this;
		//后 递增
		m_num++; 
		//最后将记录结果返回
		return temp;
    } 
}; 

//重载<<运算符 
ostream& operator<<(ostream &cout, const MyInteger &myint)//注意第二个参数 
{
	cout << "m_num = " << myint.m_num;
	return cout;
} 

void test1()
{
	MyInteger myint;
	
	//1.重载前置++运算符 
	//myint.operator++(); //本质 
	//++myint;            //简化后 
	
	cout << myint << endl;//输出需要重载<<运算符 
	cout << ++(++myint) << endl;
}

void test2()
{
	MyInteger myint;
	
	//2.重载后置++运算符
	//myint.operator++(1); //本质
	//myint++;             //化简
	
	cout << myint << endl;//输出需要重载<<运算符  
	cout << myint++ << endl;
}

int main()
{
	//test1();
	test2(); 
	return 0;
}

