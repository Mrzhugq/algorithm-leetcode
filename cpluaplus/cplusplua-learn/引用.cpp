#include<iostream>
using namespace std;

void fun(int &b)
{
	b = 50;
}

int main()
{
	int a = 10;
	int b = 20;
	//���� -> �������� &���� = ԭ��;   -> ָ�볣���ķ�װ
	
	//���ñ����ʼ��                  int &c;                  ->  ���� 
	//�����ڳ�ʼ���󣬲����Ըı�      int &c = a; int &c = b;  ->  ���� 
	 
	int &c = a;
	c = 50;
	
	fun(b);
	
	cout << a << endl;
	cout << b << endl;
}






//��������������ֵ 
//1.��Ҫ���ؾֲ����������� 
int& test1()
{
	int a = 10;
	return a;
}

//2.�����ĵ��ÿ�����Ϊ��ֵ 
int& test2()
{
	static int a = 10; //��̬�����������ȫ����������test2�����󣬻����� 
	return a;
}

int main2()
{
	//1.
	int &ret1 = test1();
	cout << ret1<< endl;
	
	//2.
	int &ret2 = test2();
	cout << ret2 << endl;
	test2() = 100; //��������ķ���ֵ�����ã�����������ÿ�����Ϊ��ֵ 
	cout << ret2 << endl;
} 






//���õı��� -> һ��ָ�볣�� 
int main3()
{
	int a = 10;
	int &ret = a; //�Զ�ת��Ϊ -> int* const ret = &a; (ָ�볣��)
	
	ret = 20;     //�ڲ����������ã��Զ�������תΪ -> *ret = 20; 
} 



void Print(const int& val)  //const int& val -> const int* const val; 
{
	//val = 20; //����const�����޸��� 
	cout << val << endl;
}

//��������  -> ���������βΣ���ֹ����� 
int main4()
{
	//int& ret = 10; //���� 
	const int& ret = 10;//��ȷ
	//����const�󣬱������������޸�Ϊ int temp = 10; const int& ret = temp;  
	
	
	int a = 10;
	Print(a);
} 
