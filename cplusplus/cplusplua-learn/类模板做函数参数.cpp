#include<iostream>
#include<string> 
#include<typeinfo>
using namespace std;

//��ģ���������������
//������ģ��ʵ�������Ķ����������εķ�ʽ 

//���ִ���ķ�ʽ�� 
//1.ָ����������� -- ֱ����ʾ���������ģ��
//2.����ģ�廯 -- �������еĲ�����Ϊģ����д���
//3.������ģ�廯 -- ������������� ģ�廯���д���



template<class T1,class T2>
class Person
{
public:
	Person(T1 name,T2 age)
	{
		m_name = name;
		m_age = age;
	}
	void showPerson()
	{
		cout << m_name << m_age << endl;
	}
	T1 m_name;
	T2 m_age;
};


//1.ָ����������� ��������ã� 
void PrintPerson1(Person<string,int> &p1)
{
	p1.showPerson();
}
void test1()
{
	Person<string,int> p1("��ķ",18);
	PrintPerson1(p1);
}


//2.����ģ�廯 �����ƺ���ģ�壩 
template<class T1,class T2>
void PrintPerson2(Person<T1,T2> &p2)
{
	p2.showPerson();
	
	//�����Ҫ��ģ�����Ƴ���ʲô���� -> typeid(T1).name()
	cout << "T1�����ͣ�" << typeid(T1).name() << endl; 
	cout << "T2�����ͣ�" << typeid(T2).name() << endl; 
}
void test2()
{
	Person<string,int> p2("�ܿ�",90);
	PrintPerson2(p2);
}



//3.������ģ�廯 �����ƺ���ģ�壩
template<class T> 
void PrintPerson3(T &p3)
{
	p3.showPerson();
}
void test3()
{
	Person<string,int> p3("����",99);
	PrintPerson3(p3);
}




int main()
{

 	//test1(); 
 	//test2(); 
 	test3(); 
	return 0;
}
 
