#include<iostream>
#include<string>
using namespace std;

//��ģ���Ա��������ʵ��


template<class T1,class T2>
class Person
{
public:
	T1 m_name;
	T2 m_age;
	//���� 
	Person(T1 name, T2 age);
	void Print();
};


//����ʵ��
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    m_name = name;
	m_age = age;
}

template<class T1,class T2>  //�ñ�������ʶT1 T2 
void Person<T1,T2>::Print()  //void Person::Print() �������д������ͨ��Ա��������ʵ�� 
{                            //���Լ���<T1,T2> ��ʾ��ģ���Ա��������ʵ�� 
    cout << m_name << endl;
	cout << m_age << endl;
}




int main()
{
	Person<string,int> p1("zhu",99);
	p1.Print(); 
	return 0;
}

