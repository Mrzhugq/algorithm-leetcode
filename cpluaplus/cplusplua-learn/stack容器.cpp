#include<iostream>
#include<string> 
#include<stack> 
using namespace std;


//ջ -> �Ƚ����(FILO),ֻ��һ������
//ջ��ֻ�ж���Ԫ�زſ��Ա����ʹ�ã����ջ�������б�����Ϊ
//��ջpush����ջpop 

//�ӿڣ�
/*
���캯���� 
stack<T> stk;            //Ĭ�Ϲ��� 
stack(const stack &stk)  //��������
��ֵ������
stack& operator=(const stack &stk); //����
���ݴ洢��
push(elem);  //��ջ���������
pop();       //��ջ���Ƴ���һ��Ԫ��
top();       //����ջ��Ԫ��
��С������
empty();     //�ж�ջ�Ƿ�Ϊ��
size();      //����ջ�Ĵ�С  
*/ 

void test1()
{
	stack<int> s1;
	s1.push(10);//��ջ 
	s1.push(20);
	s1.push(30);
	s1.push(40);
	cout << "��ջǰ��С��" << s1.size() << endl; 
	while(!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();//��ջ 
    } 
    cout << endl; 
	cout << "��ջ���С��" << s1.size() << endl; 
}
 
int main()
{
	test1(); 
	return 0;
}

