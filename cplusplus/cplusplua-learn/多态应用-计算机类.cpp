#include<iostream>
using namespace std;

//�������ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ������
//��̬�ŵ㣺
//  ������֯�ṹ����
//  �ɶ���ǿ
//  ����ǰ�ں���ڵ���չ�Լ�ά�� 


//--------------------------------------------------------------------------------------- 
//��ͨд��
class Calculator
{
public:
	int m_num1;
	int m_num2;
	int GetResult(string oper)
	{
		if(oper == "+")
		{
			return m_num1+m_num2;
		}
		else if(oper == "-")
		{
			return m_num1-m_num2;
		}
		else if(oper == "*")
		{
			return m_num1*m_num2;
		}
		//���������Ҫ��ӳ������㣬���Ǳ����޸�Դ�롣����ʵ�����ߣ������ᳫ ����ԭ��
		//����ԭ�򣬼�����չ���п��������޸Ľ��йر� 
	}
}; 


//--------------------------------------------------------------------------------------- 
//��̬д��

//����ʵ�ּ���������� 
class AbstractCalculator
{
public:
	int m_num1;
	int m_num2;
	virtual int Getresult() 
	{
		return 0;
	}
}; 

//�ӷ������
class AddCalculator : public AbstractCalculator
{
public:
	int Getresult()
	{
		return m_num1 + m_num2;
	}
};

//��������� 
class SubCalculator : public AbstractCalculator
{
public:
	int Getresult()
	{
		return m_num1 - m_num2;
	}
};
 
//�˷������
class MulCalculator : public AbstractCalculator
{
public:
	int Getresult()
	{
		return m_num1 * m_num2;
	}
};



//��̬д������ 
void test2()
{
	//��̬ʹ������
	//����ָ���������ָ���������
	
	//�ӷ�����
	AbstractCalculator* abc = new AddCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->Getresult() << endl;
	delete abc;
	
	//�ӷ�����
    abc = new SubCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->Getresult() << endl;
	delete abc; 
}

//��ͨд������ 
void test1()
{
	Calculator c;
	c.m_num1 = 10;
	c.m_num2 = 20;
	
	cout << c.m_num1 << "+" << c.m_num2 << "=" << c.GetResult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.GetResult("-") << endl;
}

int main()
{
	//test1(); 
	test2(); 
	return 0;
}

