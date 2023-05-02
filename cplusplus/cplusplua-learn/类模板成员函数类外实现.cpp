#include<iostream>
#include<string>
using namespace std;

//类模板成员函数类外实现


template<class T1,class T2>
class Person
{
public:
	T1 m_name;
	T2 m_age;
	//声明 
	Person(T1 name, T2 age);
	void Print();
};


//类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    m_name = name;
	m_age = age;
}

template<class T1,class T2>  //让编译器认识T1 T2 
void Person<T1,T2>::Print()  //void Person::Print() 如果这样写就是普通成员函数类外实现 
{                            //所以加上<T1,T2> 表示类模板成员函数类外实现 
    cout << m_name << endl;
	cout << m_age << endl;
}




int main()
{
	Person<string,int> p1("zhu",99);
	p1.Print(); 
	return 0;
}

