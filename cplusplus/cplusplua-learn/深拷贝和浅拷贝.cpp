#include<iostream>
using namespace std;

//ǳ�������� �򵥵ĸ�ֵ��������
//������� �ڶ����ظ�����ռ䣬���п������� 

class Person
{
public :

    int m_age;//���� 
    int *m_height;//��� 
    
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl; 
	}
	Person(int age, int height)
	{
		m_age = age;
		m_height = new int(height);
		cout << "Person���вι��캯������" << endl; 
	}
	Person(const Person &p)
	{
		//��������Ʊ������ṩ��ǳ���� 
		//m_age = p.m_age;
		//m_height = p.m_height;
		
		//�Լ�д��� 
		m_age = p.m_age;
		int *height = new int( *(p.m_height) );
		m_height = height;
		cout << "Person�Ŀ������캯������" << endl; 
	}
	
	~Person()
	{
		//�ͷŶ������ٵĿռ�
		if(m_height != NULL)
		{
		    delete m_height;
			m_height = NULL; 
		}
		cout << "Person��Ĭ��������������" << endl;
	}
};

//ǳ���� 
void test1()
{
	Person p1(10, 180);
	cout << "p1����Ϊ��" << p1.m_age << " p1�����Ϊ��" << *(p1.m_height) << endl;
	
	Person p2(p1);//�������ûд�������캯����ʹ�õ��Ǳ������Ŀ������캯��(ǳ����) 
	cout << "p2����Ϊ��" << p1.m_age << " p2�����Ϊ��" << *(p1.m_height) << endl;
	//����Ӧ�ó����������Ϊp2�����ǳ������p1 p2��m_heightָ���������ͬ��һƬ����
	//ִ�е����p2 p1����������������ͷſռ䣬���Ըÿռ䱻��ϰ�ͷ������Σ������ڱ���
	//ǳ�������ܴ������������ �������ڴ��ظ��ͷ� 
}


//��� -> ÿ�ο�����Ҫ��������ռ� 
void test2()
{
    Person p1(10, 180);
	cout << "p1����Ϊ��" << p1.m_age << " p1�����Ϊ��" << *(p1.m_height) << endl;
	
	Person p2(p1);//ʹ���������Լ�д�� ��� ���캯�� -> ������� 
	cout << "p2����Ϊ��" << p1.m_age << " p2�����Ϊ��" << *(p1.m_height) << endl;
} 


int main()
{
	//test1();
	test2();
	return 0;
}
