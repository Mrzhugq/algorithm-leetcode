#include<iostream>
using namespace std;

//������Ĭ��ֵ
//ע�⣺
//1.���ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�Ӹ�λ�����󣬴����Ҷ�������Ĭ��ֵ 
//2.���������������Ĭ�ϲ�����������ʵ�־Ͳ�����Ĭ�ϲ���
//������ʵ��ֻ����һ����Ĭ�ϲ��� 
int fun1(int a, int b = 10, int c = 20)
{
	return a+b+c;
} 

int main2()
{
	int ret1 = fun1(10);    //��������Լ��������ݣ������Լ������ݣ����û�У���ô��Ĭ��ֵ 
	cout << ret1 << endl;
	int ret2 = fun1(10,20);
	cout << ret2 <<endl;
} 






//������ռλ����(ռλ������������Ĭ��ֵ)
void fun2(int a, int)
{
	cout << "this is fun2" << endl;
}

void fun3(int a, int = 10)
{
	cout << "this is fun2" << endl;
}

int main1()
{
	//fun2(10);��������  ->   fun3(10);������ 
	fun2(10,20);
	return 0;
} 





//��������  
//���� : ������������ͬ����߸����� 
//���㺯����������
//1.ͬһ����������
//2.����������ͬ
//3.�����Ĳ������Ͳ�ͬ ���� ������ͬ ���� ˳��ͬ (�����ķ���ֵ��������Ϊ�������ص�����)
int fun4()
{
	cout << "fun4�ĵ���" << endl; 
} 

int fun4(int a)
{
	cout << "fun4(int a)�ĵ���" << endl; 
} 

int main3()
{
	//fun4();
	fun4(10);
	return 0;
}
 


//�������ص�ע������
//1.������Ϊ���ص�����
void fun5(int& a)  //int& a = 10; ���Ϸ� 
{
	cout << "fun5(int& a)�ĵ���" << endl; 
} 
void fun5(const int& a)  //const int& a = 10; �Ϸ� 
{
	cout << "fun5(const int& a)�ĵ���" << endl; 
}

//2.������������Ĭ�ϲ���
void fun6(int a, int b = 10) 
{
	cout << "fun6(int a, int b = 10)" << endl; 
} 
void fun6(int a)   
{
	cout << "fun6(int a)�ĵ���" << endl; 
} 


int main()
{
	int a = 10;
	fun5(a);//ע������ 
	fun5(10);
	
	fun6(10);//���� ����������֪��Ҫ�������滹�������fun6�����ֶ����ԣ�Ҫ�������� 
}
