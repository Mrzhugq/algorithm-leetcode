#include<iostream>
using namespace std;

//���ͱ��
//C++��һ�ֱ��˼��Ϊ���ͱ�̣���Ҫ���õļ�����ģ��
//C++�ṩ����ģ����� ����ģ�����ģ��

 
//1.����ģ�壨�����������أ� 
//����ģ������:����һ��ͨ�ú����亯������ֵ���β����Ϳ��Բ�����ָ��,��һ����������������� 
//�﷨��template ��������ģ�壻 typename �����䱳��ķ�����һ���������ͣ�Ҳ������class
//      T ͨ�õ��������ͣ����ƿ��Ի���ͨ��Ϊ��д��ĸ 
//template<typename T> 
//������� �����������߶��� 

//typename һ���Ǻ���ģ��  �� class һ������ģ�� 

//����������
void SwapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
} 

//����������
void SwapDouble(double &a, double &b)
{
	double temp = a;
	a = b;
	b = temp;
} 
//����...ÿ�����ݶ�Ҫдһ����������ʹ����ҲҪд��������ģ��
 




//ע��2��ģ�����ȷ����T���������ͣ��ſ���ʹ��
template<typename T>
void func()
{
	cout << "func�ĵ���" << endl;
} 

void test2()
{
	//func(); //���� 
	
	//����ʹ�ñ���ָ�����һ������
	func<int>(); 
}





//----------------------------------------------------------------------------
template<typename T>//����һ��ģ�壬���߱��������������T��һ��ͨ������
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
} 

void test1()
{
    int a = 10;
	int b = 20; 
	char c = 'c'; 
	//���ַ�ʽʹ��ģ��
	//1.�Զ������Ƶ�   -> ע��1�������Ƶ�һ�µ���������T�ſ���ʹ�� 
	Swap(a,b);
	//Swap(a,c); //���� 
	
	//2.��ʾָ������
	Swap<int>(a,b); 
	
	cout << "a = " << a << endl; 
	cout << "b = " << b << endl; 
	cout << "c = " << c << endl; 
}


int main()
{
	//test1();
	test2();
	return 0;
}
