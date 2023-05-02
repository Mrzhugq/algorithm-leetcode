#include<iostream>
#include<string>
using namespace std; 
#define PI 3.14 

//类中的属性和行为 我们都统一称为成员
//属性也称为   成员属性 成员变量
//行为也称为   成员函数 成员方法 


//本题设计一个圆类，求的周长 
//class 代表设计一个类 ，类后面就是类名称          
class Circle
{
	//访问权限
	//公共权限
public :
	
    //属性
	//半径 
    int r;
	
    //行为
	//获取圆的周长 -> 一般用函数来实现
	double calculateZC()
	{
		return 2 * PI * r; 
    } 
	 
}; 


int main1()
{
	//通过圆类，创建一个具体的圆 (对象)
	//实例化 -> 通过一个类，创建一个对象的过程 
	Circle c1;
	//给圆对象 的属性进行赋值
	c1.r = 10;
	
	cout << "圆的周长为：" << c1.calculateZC() << endl;
	return 0;
}






class Student
{
	//权限 
public:
	//属性
	string MyName;
	int ID;
	//行为
	void Show()
	{
		cout << "姓名：" << MyName << endl;
		cout << "学号：" << ID << endl;
	}
	
	//还可以根据行为给属性赋值
	void Getname(string name)
	{
		MyName = name;
    } 
};

int main() 
{
	Student s1;
	s1.MyName = "张三";
	s1.ID = 123;
	s1.Show();
	
	Student s2;
	s2.Getname("李四");
	s2.ID = 456;
	s2.Show(); 
	return 0;
}
