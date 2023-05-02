#include<iostream>
#include<string>
using namespace std;

//多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
//解决方式：将父类中的析构函数改为虚析构 或者 纯虚析构

//虚析构 纯虚析构共性：
//    都可以解决父类指针释放子类对象
//    都需要有具体的实现
//虚析构 纯虚析构区别：
//    如果是纯虚析构，该类属于抽象类，无法实例化对象 

//析构语法
//virtual ~类名() {}
//纯虚构语法
//virtual ~类名() = 0;
//类名：：~类名() {} 


class Animal
{
public:
	Animal()
	{
		cout << "Animal 的构造函数调用" << endl;
	}
	//1. 虚虚构 
	//在父类析构函数前加上Virtual变为虚析构，可解决父类指针释放子类对象不干净的问题 
//	virtual ~Animal()
//	{
//		cout << "Animal 的析构函数调用" << endl;
//	} 
	//2. 纯虚虚构 -> 需要有具体的实现 
	virtual ~Animal() = 0; 
	
	virtual void speak() = 0;
}; 

//2. 有了纯虚虚构 这个类也属于抽象类了 
Animal::~Animal()
{
	cout << "Animal 的纯虚析构函数调用" << endl;
} 


class Cat : public Animal
{
public:
	string* m_name;
	
	Cat(string name)//构造函数 
	{
		m_name = new string(name);//放在堆区 
		cout << "Cat 构造函数调用" << endl; 
    } 
    ~Cat()//析构函数 
	{
		if(m_name != NULL)
		{
			delete m_name;
			m_name = NULL;
			cout << "Cat 析构函数调用" << endl; 
		}
	} 
	
	void speak()
	{
		cout << (*m_name) << "小猫在说话" << endl;
	}
};


int main()
{
	Animal* a = new Cat("汤姆");
	a->speak();
	//父类指针在释放时，不会调用子类中的析构函数(子类一些不会释放)，导致如果子类有堆区属性，会出现内存泄漏 
	delete a;
	 
	return 0;
}

