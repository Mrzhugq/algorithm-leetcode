#include<iostream>
#include<string>
using namespace std;


//�������Ϊ���Ա 
//�������������Ϊ����ĳ�Ա������ʱ���ȹ��������(Phone��)���ٹ�������(Person��) 
//������ʱ��͹���ʱ�෴������������(Person��)�������������(Phone��)


class Phone
{
public:
	string m_pName;
	
	Phone(string pName)
	{
		m_pName = pName; 
		cout << "Phone ���캯��" << endl; 
	}
};

class Person
{
public:
	string m_name;
	Phone m_Phone;
	
	//��ʼ���б� �е�m_Phone(pName) �൱�� Phone m_Phone = pName;����ʽת���� 
	Person(string name,string pName):m_name(name), m_Phone(pName) 
	{
		cout << "Person ���캯��" << endl; 
    } 
    //��ͳ�� 
//	Person(string name,string pName)
//	{
//		m_name = name;
//		m_phone.m_pName = pName;
//    } 
}; 


int main()
{
	Person p("����","ƻ��12");
	cout << p.m_name << "����" << p.m_Phone.m_pName << endl; 
	return 0;
}

