#include<iostream>
#include<fstream>
using namespace std;

//�Զ����Ƶķ�ʽ���ļ����ж�д���� 
//�򿪷�ʽָ��Ϊios::binary

//������ ���ļ� 
//����ԭ��ostream& read(char* buffer,int len);
//�������ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���

//�������ļ�����д�������Զ����������� 
class Person
{
public:
	char m_name[64]; //����
	int m_age; 
}; 


int main()
{
    ifstream ifs;
    ifs.open("Penson.txt", ios::in | ios::binary);
    
	if(!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return 0;
	}
	
	Person p1;
	ifs.read((char*)&p1, sizeof(Person));
	
	cout << "������" << p1.m_name << endl;
	cout << "���䣺" << p1.m_age << endl;
	
	ifs.close(); 
	return 0;
}

