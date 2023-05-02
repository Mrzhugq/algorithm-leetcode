#include<iostream>
using namespace std;


//���������
//---------------------------------------------------------------------------
//3.�������������(�ݼ�һ��) 
//���ã�ͨ�����ص����������ʵ���Լ�����������

//�Զ������� 
class MyInteger
{
	friend ostream& operator<<(ostream &cout,const MyInteger &myint);
private:
	int m_num;
public:
	MyInteger()
	{
		m_num = 0;
	}
	//����ǰ��++�����
	//�����������޷���ʽ��̣�(��������)��Ϊ��һֱ��һ�����ݽ��в��� 
	MyInteger& operator++()//����������MyInteger&,ע����&��ʽ���أ�++(++myint)�������������ȷ 
	{
		//�Ƚ�����++ 
		m_num++;
		//�ٽ����������أ��Ա���42�е���� 
		return *this;
	}
	
	//���غ���++����� -> ������ʽ 
	//����ķ�������(û������)����Ϊ���Ƿ���temp�Ǿֲ�����������ִ����ͻᱻ�ͷ�
	//����ٰ������÷��أ����ǷǷ�����(temp)�ˣ���Ϊtemp�Ѿ����ͷ��� 
	//������ǰ��Ӹ�const -> const MyInteger operator++(int) 
	MyInteger operator++(int)//intռλ��������������ǰ�úͺ��õ��� 
	{
		//�� ��¼��ǰ���
		MyInteger temp = *this;
		//�� ����
		m_num++; 
		//��󽫼�¼�������
		return temp;
    } 
}; 

//����<<����� 
ostream& operator<<(ostream &cout, const MyInteger &myint)//ע��ڶ������� 
{
	cout << "m_num = " << myint.m_num;
	return cout;
} 

void test1()
{
	MyInteger myint;
	
	//1.����ǰ��++����� 
	//myint.operator++(); //���� 
	//++myint;            //�򻯺� 
	
	cout << myint << endl;//�����Ҫ����<<����� 
	cout << ++(++myint) << endl;
}

void test2()
{
	MyInteger myint;
	
	//2.���غ���++�����
	//myint.operator++(1); //����
	//myint++;             //����
	
	cout << myint << endl;//�����Ҫ����<<�����  
	cout << myint++ << endl;
}

int main()
{
	//test1();
	test2(); 
	return 0;
}

