#include<iostream>
using namespace std;


//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��


class Person
{
public:
	int m_age;
	
	void ShowClassName()
	{
		cout << "this is Person class" << endl;
	}
	void ShowClassAge()
	{
		if(this == NULL)//�����жϱ�֤����Ľ�׳��
		{
			return;
		}
		cout << "����Ϊ��" << m_age << endl; 
		//����ԭ���Ǵ����ָ��Ϊ�գ���thisΪ�� 
		//��ʵĬ����������cout << "����Ϊ��" << this->m_age << endl;  
	}
}; 

//��ָ����ó�Ա����
int main()
{
	Person* p = NULL;
	p->ShowClassName();
	p->ShowClassAge();//������ 
	
	return 0;
}
