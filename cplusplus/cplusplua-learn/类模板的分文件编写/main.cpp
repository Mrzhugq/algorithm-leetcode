#include <iostream>
#include<string> 
using namespace std;

//��ģ����ļ���д
//���⣺��ģ���еĳ�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���

//���:
//1.ֱ�Ӱ���.cppԴ�ļ�
//2.��������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��

//#include"Person.cpp"
//1. #include"Person.h"  ->  #include"Person.cpp"   (�õ���) 

//2.
#include"Person.hpp"    //���� 

int main() 
{
	Person<string,int> p1("jack",18);
	p1.Print();
	return 0;
}
