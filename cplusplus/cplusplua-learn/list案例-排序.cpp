#include<iostream>
#include<list> 
#include<string>
using namespace std;

class Person
{
public:
	Person(string name,int age,int hight)
	{
		m_name = name;
		m_age = age;
		m_hight = hight; 
	}
	string m_name;
	int m_age;
	int m_hight;
}; 

bool comparePerson(Person &p1, Person &p2)
{
	if(p1.m_age == p2.m_age)
	{
		return p1.m_hight > p2.m_hight;
	}
	else //���䲻��� 
	{
		return p1.m_age < p2.m_age; 
	}
}
 
int main()
{
	list<Person> L;
	Person p1("aaf",35,160); //���䲻ͬ������������ͬ������߽��� 
	Person p2("grg",35,150); 
	Person p3("seg",35,190); 
	Person p4("lyx",40,150); 
	Person p5("qew",30,169); 
	Person p6("zzb",45,160); 
	L.push_back(p1); 
	L.push_back(p2); 
	L.push_back(p3); 
	L.push_back(p4); 
	L.push_back(p5); 
	L.push_back(p6);
	
	for(list<Person>::iterator it = L.begin(); it!=L.end(); it++)
	{
		cout << "������" << (*it).m_name << "  ���䣺" << it->m_age
		     << "  ��ߣ�" << it->m_hight << endl; 
	} 
	
	L.sort(comparePerson);
	cout << "����󡪡�������������" << endl;
	for(list<Person>::iterator it = L.begin(); it!=L.end(); it++)
	{
		cout << "������" << (*it).m_name << "  ���䣺" << it->m_age
		     << "  ��ߣ�" << it->m_hight << endl; 
	} 
	return 0;
}

