#include<iostream>
using namespace std;

//��ʼ���б�  -> ���ã�������ʼ������ 
//�﷨�����캯��():����1(ֵ1)������2(ֵ2)...{}

class Person
{
public:
	int m_A;
	int m_B;
	int m_C;
	//��ͳ��ʼ������
//	Person(int a, int b, int c)
//	{
//		m_A = a;
//		m_B = b;
//		m_C = c;
//    } 

    //��ʼ���б� 
	Person():m_A(10),m_B(20),m_C(30)
	{
		cout << "�޲� ��ʼ���б�" << endl;
    } 
    //Ҳ��������д   ->  �������ƺʹ�ͳ��࣬��Ч�ʱȴ�ͳ�ĸ� 
   	Person(int a,int b,int c):m_A(a),m_B(b),m_C(c)
	{
		cout << "�в� ��ʼ���б�" << endl;
    } 
    
};
 
int main()
{
	//Person p(10,20,30);
	
	//������˳�ʼ���б�ֱ��д����ľ�����
	//Person p; 
	
	Person p(30,20,10); 
	cout << p.m_A << p.m_B << p.m_C << endl;
} 
