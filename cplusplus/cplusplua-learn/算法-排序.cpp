#include<iostream>
#include<algorithm> 
#include<numeric>
#include<functional>
#include<vector> 
#include<string>
#include<ctime>
using namespace std;

//�����㷨 
//sort            ����
//random_shuffle  ϴ�ƣ�ָ����Χ�ڵ�Ԫ���������˳��
//merge           ����Ԫ�غϲ��������浽��һ��������
//reverse         ��תָ����Χ��Ԫ��


//-------------------------------------------------------------------------- 
//sort(iterator beg, iterator end, _Pred) 
//������������Ҫһ��ν�ʣ���Ĭ��ֵ�� ��������Ϊbool��������() �� 

void MyPrint(int val)
{
	cout << val << " "; 
}

void test1()
{
	vector<int> v;
	v.push_back(12);
	v.push_back(14);
	v.push_back(10);
	sort(v.begin(),v.end(),greater<int>()); //����
	//�����Զ������ͣ���������< ������������() 
	for_each(v.begin(),v.end(),MyPrint);
}


//-------------------------------------------------------------------------- 
//random_shuffle(iterator beg, iterator end); //����

void test2()
{
	srand((unsigned int)time(NULL)); //ʱ��� 
	
	vector<int> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(),v.end());//α��������Լ�����ʵ������� 
	for_each(v.begin(),v.end(),MyPrint);
}

 

//--------------------------------------------------------------------------------- 
//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//ע�⣺������������������� ���鲢���� 
//dest Ŀ������������

void test3()
{
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	for(int i=0; i<10; i++)
	{
		v2.push_back(i+2);
	}
	vector<int> v3;
	v3.resize(v1.size()+v2.size()); //��ǰ��Ŀ����������ÿռ���ܹ鲢
	 
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	for_each(v3.begin(),v3.end(),MyPrint);
}



//-------------------------------------------------------------------------- 
//reverse(iterator beg, iterator end);  ��ת  

void test4()
{
	vector<int> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(i);
	}
	reverse(v.begin(),v.end()); //��ת 
	for_each(v.begin(),v.end(),MyPrint);	
} 
 
 
 
 
int main()
{
	//test1(); 
	//test2(); 
	//test3(); 
	test4(); 
	return 0;
}

