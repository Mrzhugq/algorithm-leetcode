#include<iostream>
using namespace std;

//�̳��еĹ�������� 
//���⣺���������Ĺ��������˳����˭��˭��
 
//
class Base
{
public:
	Base()
	{
		cout << "Base�Ĺ��캯��" << endl; 
	}
	~Base()
	{
		cout << "Base����������" << endl; 
	}
}; 

class Son : public Base 
{
public:
	Son()
	{
		cout << "Son�Ĺ��캯��" << endl; 
	}
	~Son()
	{
		cout << "Son����������" << endl; 
	}
}; 


int main()
{
	//Base b;
	
	//�ȹ��츸�࣬��������
	//����һ��͹����෴�����������࣬���������� 
	Son s;
	return 0;
}

