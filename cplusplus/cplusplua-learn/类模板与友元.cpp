#include<iostream>
#include<string>
using namespace std;

//��ģ������Ԫ

//ȫ�ֺ�������ʵ�֣�ֱ��������������Ԫ����
//ȫ�ֺ�������ʵ�֣���Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ��� 

//���printPerson2�� ָ����������� �Ͳ�ͬ��ô�鷳��  


//ͨ��ȫ�ֺ�����ӡPerson��Ϣ 

template<class T1,class T2>
class Person;

//ȫ�ֺ���������ʵ��   ->  д��Personǰ�棬��printPerson2��Ҳ�õ���Person��Ҫ����һ��ģ�� 
template<class T1,class T2>
void printPerson2(Person<T1,T2> &p)
{
	cout << p.m_name << p.m_age << endl;
}


template<class T1,class T2>
class Person
{
	//ȫ�ֺ���������ʵ��
	friend void printPerson(Person<T1,T2> &p)
	{
		cout << p.m_name << p.m_age << endl;
	} 
	
	//ȫ�ֺ���������ʵ�� 
	//friend void printPerson2(Person<T1,T2> &p);
	//1.���Ͽ�ģ������б� -> printPerson2�Ǹ�����ģ��
    //2.����ǰ�ñ�����֪��ȫ�ֺ����Ĵ��� -> ��printPerson2дPerson���� 
	friend void printPerson2<>(Person<T1,T2> &p); 
	
private:
    T1 m_name;
	T2 m_age;
public:
	//���� 
	Person(T1 name, T2 age)
	{
		m_name = name;
		m_age = age;
	}
};





int main()
{
	Person<string,int> p1("��ķ",18);
	printPerson(p1);
	printPerson2(p1);
	return 0;
}

