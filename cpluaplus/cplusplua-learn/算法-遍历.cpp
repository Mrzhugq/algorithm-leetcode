#include<iostream>
#include<algorithm> 
#include<numeric>
#include<functional>
#include<vector> 
using namespace std;

//�㷨 


//------------------------------------------------------------------------------------
//���������㷨
//Function for_each(iterator first, iterator last, Function fn);//���������Ǹ��������߷º��� 
//iterator transform(iterator beg1, iterator end1, iterator beg2, Function fn)
//���������Ǹ��������߷º���,���ڰ��˹�����Ҫִ�е�����  

//��ͨ����
void Print01(int val)
{
	cout << val << " ";
} 
//�º���
class Print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
}; 

void test1()
{
	vector<int> v;
	v.push_back(12);
	v.push_back(14);
	v.push_back(10);
	v.push_back(19);
	for_each(v.begin(),v.end(),Print01);     //���뺯�����־��� 
	for_each(v.begin(),v.end(),Print02 ());  //���÷º�����Ҫ�����������󣨺������� 
}



class Transform
{
public:
	int operator()(int val)
	{
		return val; //����Ҫ����v1�е�ֵ����ֱ�ӷ��ؾ����� 
	}
}; 

void test2()
{
	vector<int> v1;
	v1.push_back(12);
	v1.push_back(14);
	v1.push_back(10);
	v1.push_back(19);	
	//��v1���ݰᵽv2�� 
	vector<int> v2;        //Ŀ������ 
	v2.resize(v1.size()); //Ŀ��������Ҫ��ǰ���ٿռ� 
	transform(v1.begin(),v1.end(),v2.begin(),Transform ());//���÷º�����Ҫ�����������󣨺������� 
	for_each(v2.begin(),v2.end(),Print02 ());              //���һ��v2 
} 


int main()
{
    //test1();
    test2();
	return 0;
}

