#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


//ν��
//����bool���͵ķº�����Ϊν��
//���operator()����һ����������ô����һԪν�� 
//���operator()����������������ô������Ԫν�� 


//-------------------------------------------------------------------------------- 
//1.һԪν�� 
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
}; 

void test1()
{
	vector<int> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(i);
	}
	
	//������������û�д���5������
	//GreaterFive() ������������ 
	vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());    
	//find_if�㷨,������������Ҫһ��ν�� 
	//find_if�ҵ����ص��������Ҳ�������v.end(); 
	if(it == v.end())
	{
		cout << "û�ҵ�" << endl; 
	}
	else
	{
		cout << "�ҵ���" << *it << endl;
	}
}


//-----------------------------------------------------------------------------
//2.��Ԫν�� 

class Mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
}; 

void test2()
{
	vector<int> v;
	v.push_back(10);	
	v.push_back(6);	
	v.push_back(20);	
	v.push_back(1);
	
	sort(v.begin(),v.end(),Mycompare());
	//Mycompare()Ҳ��һ���������� 
	//Ĭ�����򣬿�����ν�ʸı�Ĭ�����򣬵�����������ν�ʣ��������� 
	for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << *it << " ";
	}	
} 


int main()
{
    //test1();
    test2();
	return 0;
}

