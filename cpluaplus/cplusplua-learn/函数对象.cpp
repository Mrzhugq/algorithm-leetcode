#include<iostream>
#include<string>
using namespace std;
 
//��������
//���
//    1.���غ������ò��������࣬������Ϊ��������
//    2.��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���
//���ʣ�
//    ��������(�º���)��һ���࣬����һ������


//��������ʹ�ã�
//����������ʹ�õ�ʱ�򣬿�������ͨ�����������ã����Կ����в����������з���ֵ
//�������󳬳���ͨ�����ĸ����������������Լ���״̬
//�������������Ϊ��������


//1.
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
}; 

void test1()
{
	MyAdd myadd;  //myadd���Ǻ�������
	cout << myadd(10,10) << endl; 
}

//2.

class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}
	int count;//���������ԣ���¼�º������ü��� 
};

void test2()
{
	MyPrint myprint;
	myprint("Hello Word");
	myprint("Hello Word");
	myprint("Hello Word");
	myprint("Hello Word");
	cout << myprint.count << endl; //��ͨ������û�������� 
} 

//3.
void DoPrint(MyPrint &m, string test)
{
	m(test);
} 

void test3()
{
	MyPrint myprint;
	DoPrint(myprint,"Hello");
} 
 
 
 
int main()
{
    //test1();
    //test2();
    test3();
	return 0;
}

