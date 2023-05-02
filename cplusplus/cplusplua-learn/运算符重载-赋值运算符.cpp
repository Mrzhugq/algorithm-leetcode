#include<iostream>
using namespace std;

//���������
//---------------------------------------------------------------------------
//4.��ֵ���������
//C++���������ٸ�һ�������4������(ǰ��˵������ʵ���ĸ�)
//   1.Ĭ�Ϲ��캯�����޲κ�����Ϊ�գ�
//   2.Ĭ�������������޲κ�����Ϊ�գ�
//   3.Ĭ�Ͽ������캯���������Խ���ֵ����
//   4.��ֵ�������operator=�������Խ���ֵ�����������������Ǽ򵥵�ǳ������ 
//    ���������������ָ�����������ֵ����ʱҲ�������ǳ�������⣩

class Person
{
public:
	int* m_age;
	
	Person(int age)//���� 
	{
		m_age = new int(age);
	}
	
	~Person()//�����ͷŶ����ڴ� 
	{
		if(m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}
	
	//���ظ�ֵ������������ 
	Person& operator=(Person &p)
	{
		//������ʵ�ֵ�ǳ����
		//m_age = p.m_age;
		
		//�Լ�д���
		//�ж� ��ֹ�Ը�ֵ 
		if(this != &p)
		{
			//���ж��Ƿ����������ڶ�������������ͷŸɾ���Ȼ������� 
	        if(m_age != NULL)
			{
				delete m_age;
				m_age = NULL;
		    } 
	        m_age = new int( *(p.m_age) );
		}
		return *this; //���Ϸ��ؾͿ��������� 
	} 
}; 

void test1()
{
	Person p1(18);
	Person p2(20);
	Person p3(30); 
	
	//p2.operator=(p1); //���� 
	p2 = p1;            //�����
	
	p3 = p2 = p1;
	
	cout << "p1������Ϊ��" << *(p1.m_age) << endl;
	cout << "p2������Ϊ��" << *(p2.m_age) << endl;
	cout << "p3������Ϊ��" << *(p3.m_age) << endl;
}

int main()
{
    test1();
	return 0;
}

