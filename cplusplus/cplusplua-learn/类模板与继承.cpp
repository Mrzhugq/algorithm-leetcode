#include<iostream>
using namespace std;

//����ģ�������̳�ʱ����Ҫע��һ�¼��㣺
//1.������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ�������е�T������
//2.�����ָ�����������޷�����������ڴ�
//3.��������ָ���������е�T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��

template<class T>
class Base
{
public:
    T m; 
}; 

//class Son : public Base  //���󣬱���Ҫ֪�������е�T�����ͣ����ܼ̳� 
//{
//	
//};


//1. ָ�� 
class Son : public Base<int>
{
	
}; 

void test1()
{
	Son s1; //����ʵ���� 
}



//2. ��ָ��������д��ģ�� -> ���ָ�� 
template<class T1, class T2>
class Son2 : public Base<T2>
{
public: 
	T1 abc;
}; 

void test2()
{
	Son2<int, char> s2;
	//���ǰ�int����T1����char����T2  ->  �����е�abcΪint�ͣ������е�mΪchar�� 
}






int main()
{
	//test1();
	test2();
	return 0;
}

