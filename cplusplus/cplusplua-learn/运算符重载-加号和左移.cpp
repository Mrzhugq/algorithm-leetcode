#include<iostream>
using namespace std;

//���������
//��������е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������

//----------------------------------------------------------------------------------
//1.ͨ����Ա�������ؼӺ� 
class Person
{
public:
	int m_a;
	int m_b;
	
//	Person operator+(Person &p)//ͨ����Ա�������ؼӺţ������Ա�������ֱ����operator+
//	{
//		Person temp;
//		temp.m_a = m_a + p.m_a;
//		temp.m_b = m_b + p.m_b;
//		return temp;
//	}
};

//ͨ��ȫ�ֺ������ؼӺţ�����Ҳ�ñ����operator+ 
Person operator+(Person &p1, Person &p2)
{
    Person temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
} 
//�������� 
Person operator+(Person &p1, int num)
{
    Person temp;
	temp.m_a = p1.m_a + num;
	temp.m_b = p1.m_b + num;
	return temp;
} 

void test1()
{
	Person p1;
	p1.m_a = 10;
	p1.m_b = 10;
	Person p2;
	p2.m_a = 20;
	p2.m_b = 20;
	
	//����Ҫʵ��p1��p2��������Ӹ���p3 
	
	//1.ͨ����Ա�������ؼӺ� 
	//Person p3 = p1.operator+(p2); //���� 
	Person p3 = p1 + p2;            //���Լ�Ϊ���� 
	//2.ͨ��ȫ�ֺ������ؼӺ�
	//Person p4 = operator+(p1,p2); //���� 
	Person p4 = p1 + p2;            //Ҳ���Լ�Ϊ���� 
	
	//��������أ�Ҳ���Է����������� 
	//Person p5 = operator+(p1,100)
	Person p5 = p1 + 100;//Person + int Ҳ��Ҫ�Լ�д 
	  
	cout << p3.m_a <<" "<< p3.m_b <<endl;
	cout << p4.m_a <<" "<< p4.m_b <<endl;
	cout << p5.m_a <<" "<< p5.m_b <<endl;
}
 
 
 
 
//----------------------------------------------------------------------------------
//2.�������������
//���ã�����Զ������������ 

class Person2
{
public://���԰���������Ϊ˽�У�Ȼ��� operator<< ȫ�ֺ�����Ϊfriend 
	int m_A;
	int m_B;
	//���ó�Ա�������� ��������� �������p.operator<<(cout) - ��Ϊ p << cout 
	//һ�Ѳ������ó�Ա��������<<���������Ϊ�򻯺�p����࣬��ԭʼ���������̫һ�� 
//	void operator<<(ostream &cout)
//	{
//		
//	}
};

//ֻ������ȫ�ֺ���������������� -> cout �Ǳ�׼�����������ostream 
//102����Ҫ�������endl�����뷵��cout������Ҫ�����÷�ʽ����(ostream&) -> cout << endl;(�����ǵ��ÿ��������) 
ostream& operator<<(ostream &cout, Person2 &p)  
{
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
} 

void test2()
{
	Person2 p;
	p.m_A = 10;
	p.m_B = 20;
	//operator<<(cout, p); //���� 
	cout << p << endl;     //�򻯺� (��ʽ���) 
}







int main()
{
	//test1();
	test2(); 
} 
