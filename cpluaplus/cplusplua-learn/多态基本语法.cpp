#include<iostream>
using namespace std;

//多态（多种形态） -> C++面向对象三大特征之一

//多态分为两类 
//1.静态多态  函数重载和运算符重载属于静态多态，复用函数名 
//2.动态多态  派生类和虚函数实现运行时多态 

//静态和动态多态区别：
//静态多态的函数地址早绑定——编译阶段确定函数地址 
//动态多态的函数地址晚绑定——运行阶段确定函数地址

class Animal
{
public:
	//加上virtual加上虚函数了 
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
}; 

class Cat : public Animal
{
public:
    //重写  函数返回值类型 函数名 形参列表 都相同 
	void speak() 
	{
		cout << "小猫在说话" << endl;
	}
};

//执行说话函数 
//地址早绑定，在编译阶段确定函数地址，所以无论传进来什么都是输出 动物在说话

//如果想要执行猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定 -> 虚函数 
//虚函数就是在函数名字前面加个virtual 
void doSpeak(Animal &animal) //Animal &anmial = cat;
{
	animal.speak();
} 

//动态多态满足条件
//1.有继承关系
//2.子类重写父类的虚函数 

//动态多态使用：
//父类的指针或者引用 指向子类对象
 
int main()
{
	Cat cat;
	Animal animal; 
	
	doSpeak(cat);
	//C++中允许 子类转化为父类，不允许父类转化为子类 
	//子类转化为父类 -> 只能是指针或者引用，不能是对象 
	//例如 ：Bulk_item bulk;           (其中Bulk_item是Item_base的子类) 
	//       Item_base *itemp = &bulk;
	//这里其实并没有什么转化
    //指针只是代表地址，什么类型指针只是表示从当前地址开始，到这个类型空间指针结束的内存块 
    //这里相当于父类的指针指向子类所存在的地址，然而子类中拥有父类的部分，所以这样合法 
	return 0;
}

