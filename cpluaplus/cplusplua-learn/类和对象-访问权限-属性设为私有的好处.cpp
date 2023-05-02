#include<iostream>
#include<string>
using namespace std; 

//访问权限 (成员属性和成员函数都有权限) 
//公共权限 public    成员 类内可以访问 类外也可以访问
//保护权限 protected 成员 类内可以访问 类外不可以访问   儿子可以访问父亲中的保护内容 
//私有权限 private   成员 类内可以访问 类外不可以访问   儿子不可以访问父亲的私有内容 

class Person
{
public :
	//公共权限
	string Name;
protected :
	//保护权限
	string Car;
private :
	//私有权限
	int Password; //银行卡密码
	
public :
	void fun()
	{
		Name = "张三";  //类内三个都能访问 
		Car = "拖拉机";
		Password = 123456; 
	}
}; 

int main1()
{
	Person p1;
	
	p1.Name = "李四";
	//p1.Car = "奔驰";   //错误 -> 保护权限的内容，在类外访问不到
	//p1.Password = 123; //错误 -> 私有权限的内容，在类外也访问不到 
	p1.fun();
	return 0; 
} 



///////////////////////////////////////////////////////////////////////////
//class 和 struct 的区别
//都可以表示一个类
//唯一区别在默认访问权限不同
//struct 默认权限为公共 public
//class  默认权限为私有 private

class C1
{
	int a;//默认private 
}; 

struct C2
{
	int b;//默认public 
}; 





/////////////////////////////////////////////////////////////////////////
//成员属性设置为私有
//优点 ：将所有成员色泽为私有，可以自己控制读写权限
//       对于写权限，我们可以检查数据的有效性

//优点1. 
class Person1
{
public :
	//设置姓名 (写姓名)
	void SetName(string name)
	{
		MyName = name;
	}
	
	//获取姓名 (读姓名)
	string GetName()
	{
		return MyName;
    } 
    
    //获取年龄  (读年龄)
    int GetAge()
    {
    	age = 0;//初始化一下，要不返回的是随机值
		return age; 
	}
	
	//设置爱人(写爱人)
	void SetLover(string love)
	{
		Lover = love;
    } 
    
private :
	string MyName;  //可读可写 
	int age;      //只读 
	string Lover; //爱人 只写 
}; 

int main2()
{
	Person1 p;
	
	p.SetName("张三");
	cout << "姓名是：" << p.GetName() << endl;
	
	//p.age = 100; //错误 -> 自己设计的只读 
	cout << "年龄是: " << p.GetAge() << endl;
	
	p.SetLover("热巴"); 
	//cout << "爱人名称为: " << p.Lover << endl;//错误 -> 自己设计的只写不可读 
    return 0;
}




//优点2.年龄只读改为可读可写 -> 写的同时可以检测年龄的有效性 
class Person2 
{
public :
	//设置姓名 (写姓名)
	void SetName(string name)
	{
		MyName = name;
	}
	
	//获取姓名 (读姓名)
	string GetName()
	{
		return MyName;
    } 
    
    //设置年龄(写年龄) -> 检查有效性(年龄区间必须是0 ~ 150) 
    void SetAge(int A)
	{
		if(A<0 || A>150)
		{
			age = 0;
			cout << "年龄输入有误" << endl;
			return;
		}
		age = A;
    } 
    
    //获取年龄  (读年龄)
    int GetAge()
    {
		return age; 
	}
	
	//设置爱人(写爱人)
	void SetLover(string love)
	{
		Lover = love;
    } 
    
private :
	string MyName;  //可读可写 
	int age;      //只读 
	string Lover; //爱人 只写 
}; 

int main()
{
	Person2 p;

	p.SetAge(1000); 
	cout << "年龄是: " << p.GetAge() << endl;
	
	p.SetAge(80); 
	cout << "年龄是: " << p.GetAge() << endl;

    return 0;
}






