#include<iostream>
#include<string>
using namespace std;

//类模板与友元

//全局函数类内实现：直接在类内声明友元即可
//全局函数内外实现：需要提前让编译器知道全局函数的存在 

//如果printPerson2用 指定传入的类型 就不同那么麻烦了  


//通过全局函数打印Person信息 

template<class T1,class T2>
class Person;

//全局函数，类外实现   ->  写到Person前面，但printPerson2中也用到了Person，要声明一下模板 
template<class T1,class T2>
void printPerson2(Person<T1,T2> &p)
{
	cout << p.m_name << p.m_age << endl;
}


template<class T1,class T2>
class Person
{
	//全局函数，类内实现
	friend void printPerson(Person<T1,T2> &p)
	{
		cout << p.m_name << p.m_age << endl;
	} 
	
	//全局函数，类外实现 
	//friend void printPerson2(Person<T1,T2> &p);
	//1.加上空模板参数列表 -> printPerson2是个函数模板
    //2.需提前让编译器知道全局函数的存在 -> 把printPerson2写Person上面 
	friend void printPerson2<>(Person<T1,T2> &p); 
	
private:
    T1 m_name;
	T2 m_age;
public:
	//声明 
	Person(T1 name, T2 age)
	{
		m_name = name;
		m_age = age;
	}
};





int main()
{
	Person<string,int> p1("汤姆",18);
	printPerson(p1);
	printPerson2(p1);
	return 0;
}

