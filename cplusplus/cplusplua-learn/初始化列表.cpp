#include<iostream>
using namespace std;

//初始化列表  -> 作用：用来初始化属性 
//语法：构造函数():属性1(值1)，属性2(值2)...{}

class Person
{
public:
	int m_A;
	int m_B;
	int m_C;
	//传统初始化操作
//	Person(int a, int b, int c)
//	{
//		m_A = a;
//		m_B = b;
//		m_C = c;
//    } 

    //初始化列表 
	Person():m_A(10),m_B(20),m_C(30)
	{
		cout << "无参 初始化列表" << endl;
    } 
    //也可以这样写   ->  这样看似和传统差不多，但效率比传统的高 
   	Person(int a,int b,int c):m_A(a),m_B(b),m_C(c)
	{
		cout << "有参 初始化列表" << endl;
    } 
    
};
 
int main()
{
	//Person p(10,20,30);
	
	//如果有了初始化列表，直接写下面的就行了
	//Person p; 
	
	Person p(30,20,10); 
	cout << p.m_A << p.m_B << p.m_C << endl;
} 
