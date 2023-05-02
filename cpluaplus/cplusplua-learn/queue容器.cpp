#include<iostream>
#include<queue> 
using namespace std;

//���� -> �Ƚ��ȳ�(FIFO)���������ڣ�һ��ֻ�ܽ����ݣ�һ��ֻ�ܳ����ݣ�
//���������һ���������ݣ�һ���Ƴ�����
//������ֻ�ж�ͷ�Ͷ�β�ſ��Ա����ʹ�ã���˶���Ҳ�������б�����Ϊ
//���push������pop 


//�ӿڣ�
/*
���캯���� 
queue<T> que;            //Ĭ�Ϲ���
queue(const queue &que)  //��������
��ֵ������
queue& operator=(const queue &que); //����
���ݴ洢��
push(elem);              //����β�������
pop();                   //����ͷ�Ƴ���һ��Ԫ��
back();                  //�������һ��Ԫ��
front();                 //���ص�һ������ 
��С������
empty();                 //�ж϶����Ƿ�Ϊ��
size();                  //���ض��д�С 
*/ 


void test1()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	cout << "����ǰ��С��" << q.size() << endl; 
	while(!q.empty())
	{
		cout << "��ͷ���ݣ�" << q.front() <<endl;		
		cout << "��β���ݣ�" << q.back() <<endl;
		q.pop();
		cout << endl;		
	}
	cout << "���Ӻ��С��" << q.size() << endl; 
}

int main()
{
    test1();
	return 0;
}

