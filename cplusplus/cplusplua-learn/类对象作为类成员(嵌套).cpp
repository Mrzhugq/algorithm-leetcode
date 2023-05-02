#include<iostream>
#include<string>
using namespace std;


//类对象作为类成员 
//当其他类对象作为本类的成员，构造时候先构造类对象(Phone类)，再构造自身(Person类) 
//析构的时候和构造时相反，先析构自身(Person类)，再析构类对象(Phone类)


class Phone
{
public:
	string m_pName;
	
	Phone(string pName)
	{
		m_pName = pName; 
		cout << "Phone 构造函数" << endl; 
	}
};

class Person
{
public:
	string m_name;
	Phone m_Phone;
	
	//初始化列表 中的m_Phone(pName) 相当于 Phone m_Phone = pName;即隐式转换法 
	Person(string name,string pName):m_name(name), m_Phone(pName) 
	{
		cout << "Person 构造函数" << endl; 
    } 
    //传统的 
//	Person(string name,string pName)
//	{
//		m_name = name;
//		m_phone.m_pName = pName;
//    } 
}; 


int main()
{
	Person p("张三","苹果12");
	cout << p.m_name << "拿着" << p.m_Phone.m_pName << endl; 
	return 0;
}

