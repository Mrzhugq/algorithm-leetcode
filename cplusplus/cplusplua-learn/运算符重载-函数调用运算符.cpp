#include<iostream>
#include<string>
using namespace std;

//���������
//6.������������� ()
//    1.�������������()Ҳ��������
//    2.�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
//    3.�º���û�й̶�д�����ǳ���� 

//----------------------------------------------------------------------------- 
//��ӡ����� 
class Myprint
{
public:
	//()��������س�Ա���� 
    void operator()(string test)
	{
		cout << test << endl; 
	} 
//	Myprint()
//	{
//		cout << "Ĭ�Ϲ���" << endl; 
//	}
}; 

void MyPrint1(string test)//ȫ�ֺ��� 
{
	cout << test << endl;
}

void test1()
{
	Myprint myprint;
	//myprint.operator("Hello Word");  //����
    myprint("Hello Word");             //����� 
	Myprint ()("Hello Word");//���������������()��Myprint ()������Ĭ�Ϲ��촴��һ���������� 
	
	MyPrint1("Hello Word");            //����Ǻ�����������������أ�����ʹ��ʱ�ǳ��� 
}



//----------------------------------------------------------------------------- 
//�º���û�й̶�д�����ǳ���� 
//�ӷ���

class Myadd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
}; 

void test2()
{
	Myadd myadd;
	int ret = myadd(10,20);
	cout << ret << endl;
	
	//������������ -> Myadd() ->  ���н������������ͷ� 
	cout << Myadd()(10,20) << endl; 
}

int main()
{
	test1();
	//test2();
	return 0;
}

