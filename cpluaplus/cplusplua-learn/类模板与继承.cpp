#include<iostream>
using namespace std;

//当类模板碰到继承时，需要注意一下几点：
//1.当子类继承的父类是一个类模板时，子类在声明的时候，要指出父类中的T的类型
//2.如果不指定，编译器无法给子类分配内存
//3.如果想灵活指定出父类中的T的类型，子类也需要变为类模板

template<class T>
class Base
{
public:
    T m; 
}; 

//class Son : public Base  //错误，必须要知道父类中的T的类型，才能继承 
//{
//	
//};


//1. 指定 
class Son : public Base<int>
{
	
}; 

void test1()
{
	Son s1; //可以实例化 
}



//2. 不指定，子类写成模板 -> 灵活指定 
template<class T1, class T2>
class Son2 : public Base<T2>
{
public: 
	T1 abc;
}; 

void test2()
{
	Son2<int, char> s2;
	//就是把int给了T1，把char给了T2  ->  子类中的abc为int型，父类中的m为char型 
}






int main()
{
	//test1();
	test2();
	return 0;
}

