#include<iostream>
using namespace std;

int *fun()
{
	int *p = new int(10);//int *p = (int*)malloc(sizeof(int)*1);  *p=10;
	return p;
}

void test1()//����һ���� 
{
	int *p = fun();
	cout << *p << endl;
	delete p;
}


void test2()//����һ������ 
{
	int *arr = new int[10];
	for(int i=0; i<10; i++)
	{
		arr[i] = 10 + i;
	}
	
	for(int i=0; i<10; i++)
	{
		cout << arr[i] << endl;
	}
	
	delete[] arr; //ע������Ҫ��һ��[] �����߱����������ͷŵ������� 
}

int main()
{
	//test1();
	test2(); 
	return 0; 
}
