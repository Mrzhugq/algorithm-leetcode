#include<iostream>
using namespace std;

//thisָ�� 
//�Ǿ�̬��Ա������������������ϣ�Ҳֻ��һ�ݣ�Ҳ���Ƕ��ͬ���Ͷ���Ṳ��һ����� 
//��ô��һ�������������ĸ���������Լ����أ� -> thisָ��

//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���

//thisָ��������ÿһ�� �Ǿ�̬��Ա���� �ڵ�һ��ָ��
//thisָ�벻��Ҫ���壬ֱ��ʹ�ü���

//thisָ�����;
//1.���βκͳ�Ա����ͬ��ʱ������thisָ��������
//2.����� �Ǿ�̬���� �з��ض�������ʹ��return *this; 


//-------------------------------------------------------------------
//1.
class Person1
{
public :
    int age;
    
	Person1(int age)
	{
		//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this->age = age;
    } 
//public :
//    int m_age;
//    
//	Person1(int age)
//	{
//		m_age = age;
//    } 
}; 

int main1()
{
	Person1 p1(18);
	cout << "p1������Ϊ��" << p1.age << endl;
	return 0;
}

//int *A = &a;
//int &A = a; 
//-------------------------------------------------------------------
//2.
class Person
{
public :
    int m_age;
    
	Person(int age)
	{
		m_age = age;
    } 
    
    Person& PersonAddAge(Person &p)
    {
    	m_age += p.m_age;
    	//this ָ��p2��*this ����p2���� 
    	return *this;
	}
}; 

int main()
{
	Person p1(10);
	Person p2(20);
	
	//p2.PersonAddAge(p1);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1); //��ʽ���˼�� 
	
	cout << "p2������Ϊ��" << p2.m_age << endl;
	return 0;
}
