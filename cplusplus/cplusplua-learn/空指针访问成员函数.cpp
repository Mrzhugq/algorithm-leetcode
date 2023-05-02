#include<iostream>
using namespace std;


//C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
//如果用到this指针，需要加以判断保证代码的健壮性


class Person
{
public:
	int m_age;
	
	void ShowClassName()
	{
		cout << "this is Person class" << endl;
	}
	void ShowClassAge()
	{
		if(this == NULL)//加以判断保证代码的健壮性
		{
			return;
		}
		cout << "年龄为：" << m_age << endl; 
		//报错原因是传入的指针为空，即this为空 
		//其实默认是这样：cout << "年龄为：" << this->m_age << endl;  
	}
}; 

//空指针调用成员函数
int main()
{
	Person* p = NULL;
	p->ShowClassName();
	p->ShowClassAge();//这个会崩 
	
	return 0;
}
