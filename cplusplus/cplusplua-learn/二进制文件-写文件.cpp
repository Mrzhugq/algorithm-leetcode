#include<iostream>
#include<fstream>
using namespace std;

//�Զ����Ƶķ�ʽ���ļ����ж�д���� 
//�򿪷�ʽָ��Ϊios::binary


//������ д�ļ� 
//����ԭ��ostream& write(const char* buffer,int len);
//�������ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���

//�������ļ�����д�������Զ����������� 
class Person
{
public:
	char m_name[64]; //�����������ļ�����һ��ͬchar*,����string
	int m_age; 
}; 


int main()
{
	//������ofstream ofs("Penson.txt",ios::out | ios::binary);
	
	//1.ͷ�ļ� 
	//2.���������� 
	ofstream ofs;
	//3.���ļ� 
	ofs.open("Penson.txt",ios::out | ios::binary); //  ���ִ򿪷�ʽ�м��� | 
	//4.д�ļ� 
	Person p1 = {"����", 18};
	ofs.write( (const char*)&p1, sizeof(Person) );
	//5.�ر��ļ� 
	ofs.close();
	return 0;
}

