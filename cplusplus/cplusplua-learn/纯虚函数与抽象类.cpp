#include<iostream>
using namespace std;

//���麯���ͳ�����
//�ڶ�̬�У�ͨ���������麯���������Ǻ�������ģ���Ҫ���ǵ���������д������
//������ǿ����麯����Ϊ���麯�� �﷨��virtual ����ֵ���� ������(�����б�) = 0;
//���������˴��麯���������Ҳ��Ϊ ������

//������(�ӿ���)�ص�
//�޷�ʵ��������
//���������д�������еĴ��麯��������Ҳ���ڳ�����
 
class Base
{
public:
	//���麯�� 
	virtual void func() = 0;
};

class Son : public Base 
{
public:
	void func()
	{
		cout << "func ����" << endl; 
	}
}; 

int main()
{
	//Son s;//������д�����ʵ�������� 
	Base* b = new Son;
	b->func();
	delete b;
	 
	return 0;
}
