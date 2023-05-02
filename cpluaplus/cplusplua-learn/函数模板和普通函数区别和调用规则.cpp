#include<iostream>
#include<string>
using namespace std;

//------------------------------------------------------------------------------
//普通函数和模板函数的区别 (隐式类型转换，能转换就转换，不能就报错) 
//1.普通函数调用可以发生  隐式类型转换
//2.函数模板 用自动类型推导，不可以发生隐式类型转换
//3.函数模板 用显示指定类型，可以发生隐式类型转换 


//普通函数 
int MyAdd(int a, int b)
{
	return a+b;
}

//模板函数 
template<typename T>
T MyAdd2(T a, T b)
{
	return a + b;
} 

//普通函数测试 
void test1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << MyAdd(a,b) << endl; 
	
	cout << MyAdd(a,c) << endl; 
	//隐式类型转换了,在传入过程中把字符型转化为了整形 c -> 99 
	 
}

//模板函数测试 
void test2()
{
    int a = 10;
	int b = 20;
	char c = 'c';
	
	//1.自动类型推导 
	cout << MyAdd2(a,b) << endl;  
	//cout << MyAdd2(a,c) << endl; //错误 不能隐式类型转换，编译器不知道T是char还是int
	
	//2.显示指定类型 (一般用这种方法) 
    cout << MyAdd2<int>(a,b) << endl;     
    cout << MyAdd2<int>(a,c) << endl; //正确，T的类型已经明确int    
    
}  




//------------------------------------------------------------------------------
//普通函数和函数模板的调用规则：
//1.如果函数模板和普通函数都可以实现，优先调用普通函数
//2.可以通过空模板参数列表来强制调用函数模板
//3.函数模板也可以发生重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板

void MyPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
} 

template<typename T>
void MyPrint(T a, T b)
{
	cout << "调用的函数模板" << endl; 
}

//模板重载 
template<typename T>
void MyPrint(T a, T b, T c)
{
	cout << "调用的重载的函数模板" << endl; 
}


void test3()
{
	int a = 10;
	int b = 20;
	MyPrint(a,b); //1.优先调用普通函数
	
	//2.通过空模板参数列表来强制调用函数模板 
	MyPrint<>(a,b);  // <> 代表空模板 
	
	//3.函数模板也可以发生重载
	MyPrint<>(a,b,100);
	
	//4.如果模板可产生更好的匹配，优先调模板
	char ch1 = 'a';     //因为是char,调用普通函数还要发生隐式转换，所以调模板 
	char ch2 = 'b';
	MyPrint(ch1,ch2);
    
    //既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性 
}



//------------------------------------------------------------------------------
//模板的局限性 

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};

template<typename T>
void fun(T a, T b)
{
	a = b;
}
//如果a，b是自定义类型，Person或者数组等，也就无法正常运行了
//因此C++为了解决这种问题，提供了模板的重载，可以为这些特定的类型提供 具体化的模板 
//当然也可以运算符重载，但麻烦 


//比较两个数是否相等模板 
template<typename T>
bool MyCom(T &a, T &b)
{
	if(a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//具体化Person的模板 -> 如果是Person类型优先调用 
//template<> bool MyCom<Person>(Person &p1, Person &p2)
template<> 
bool MyCom(Person &p1, Person &p2)
{
	if(p1.m_name == p2.m_name && p1.m_age == p2.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}
} 

void test4()
{
	int a = 10;
	int b = 20;
	cout << MyCom(a,b) << endl; 
	
	Person p1("张三",18);
	Person p2("赵四",18);
	cout << MyCom(p1,p2) << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

