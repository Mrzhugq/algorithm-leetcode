#include<iostream>
#include<string>
using namespace std;

//2.��ģ��

//���ã�����һ��ͨ���࣬�������Ϳ��Բ�����ָ������һ����������������� 
//�﷨��template<class T>   classҲ������typename���� 
//      �� 


//-------------------------------------------------------------------------
template<class NameType,class AgeType>
class Person
{
public:
	NameType m_name;
	AgeType m_age;
	Person(NameType name, AgeType age)
	{
		m_name = name;
		m_age = age;
	}
	void Print()
	{
		cout << m_name << endl;
		cout << m_age << endl;
	}
//	string m_name;
//	int m_age;
};

void test1()
{
	Person<string,int> p1("�����",90);
	p1.Print();
}




//-------------------------------------------------------------------------
//��ģ���뺯��ģ������
//1.��ģ��û���Զ������Ƶ������Է�ʽ
//2.��ģ�� ��ģ������б��п�����Ĭ�ϲ���

template<class NameType,class AgeType = int>
class Person1 
{
public:
	NameType m_name;
	AgeType m_age;
	Person1(NameType name, AgeType age)
	{
		m_name = name;
		m_age = age;
	}
	void Print()
	{
		cout << m_name << endl;
		cout << m_age << endl;
	}
};

void test2()
{
	//1.
    //Person p1("�����",90); //���󣬲����Զ������Ƶ�
	
	//2.
	//template<class NameType,class AgeType = int> //��������д�ˣ���Ĭ�ϲ��� 
    Person1<string> p2("��˽�", 80);
    p2.Print();
}
 

int main()
{
	//test1();
	test2();
	return 0;
}

