#include<iostream>
using namespace std;

//��ģ���еĳ�Ա��������ʱ��
//1.��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//2.��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���


class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
}; 

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
}; 

template<class T>
class Myclass
{
public:
	T obj;
	void fun1()               //��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ��� 
	{
		obj.showPerson1();    //��Ϊ������Ҳ��֪��T��ʲô���� 
	}                         //û������showPerson() 
	void fun2()
	{
		obj.showPerson2();
	}
};


int main()
{
	Myclass<Person1> m1;
	m1.fun1();
	//m1.fun2();  //���������У���ΪshowPerson2()������Person1�ĳ�Ա���� 
	return 0;
}

