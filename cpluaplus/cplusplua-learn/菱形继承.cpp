#include<iostream>
using namespace std;

//���μ̳�
 
//         ����
//    ����       ����
//       �����ࣨ������ 

//�������������̳�ͬһ������
//      ����ĳ����ͬʱ�̳�������������
//      ���ּ̳г�Ϊ���μ̳У�����שʯ�̳�

//���μ̳����⣺
//1.ͬ��̳�����
//2.�����Ǽ̳�������������ʱ -> ��������������Ǽ̳����������е����ݣ���Щ����ֻ��Ҫһ�ݾͿ����� 


//������ 
class Animal
{
public:
    int m_age;	
}; 

//��̳� -> �ڼ̳з�ʽǰ�����virtual 
//Animal���Ϊ ����� 
//���� 
class Sheep : virtual  public Animal
{
    	
}; 

//��̳� -> �ڼ̳з�ʽǰ�����virtual  
//���� 
class Tuo : virtual public Animal
{

}; 

//���� 
class SheepTuo : public Sheep , public Tuo
{
    	
}; 

int main()
{
	SheepTuo st;
	st.Sheep::m_age = 18;
	st.Tuo::m_age = 28;
	
	//�������һ  -> �������� 
	cout << "st.Sheep::m_age = " << st.Sheep::m_age << endl; //û��̳�ǰ��18 
	cout << "st.Tuo::m_age = " << st.Tuo::m_age << endl;     //û��̳�ǰ��28
	
	//��������������ն����ꣿ -> ���������䣬��Դ�˷ѣ���ʵֻҪһ�ݾ�����
	//�����������̳� ������μ̳е������
	cout << "m_age = " << st.m_age << endl;//��̳�m_age�ͱ����һ�� 28 
	return 0;
}

