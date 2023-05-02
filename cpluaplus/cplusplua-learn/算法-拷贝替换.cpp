#include<iostream>
#include<algorithm> 
#include<functional>
#include<vector> 
#include<string>
using namespace std;


//���ÿ����滻�㷨
//copy        ����ָ����ΧԪ�ؿ�������һ������
//replace     ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
//replace_if  ��������ָ����Χ������������Ԫ���޸�Ϊ��Ԫ�� 
//swap        ��������������Ԫ��

//replace_copy(iterator beg, iterator end, iterator dest, oldvalue, newvalue);
//�����ڵ��ھ�ֵ�����ݿ������µ������� 

//--------------------------------------------------------------------------  
//copy(iterator beg, iterator end, iterator dest); ʵ���õĲ��࣬��ֱ����=��ֵ 
//destĿ������������ 

void MyPrint(int val)
{
	cout << val << " "; 
}

void test1()
{
	vector<int> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(i);
	}
	vector<int> v2;
	v2.resize(v.size()); //Ҳ��Ҫ��ǰ���ٿռ�
	copy(v.begin(),v.end(),v2.begin());
    for_each(v2.begin(),v2.end(),MyPrint);
} 


//-------------------------------------------------------------------------- 
//replace(iterator beg, iterator end, oldvalue, newvalue); 

void test2()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	replace(v.begin(),v.end(),10,1000); //��������10�滻Ϊ1000
	for_each(v.begin(),v.end(),MyPrint); 
	v.push_back(10);
}



//--------------------------------------------------------------------------
//replace_if(iterator beg, iterator end, _Pred, newvalue);
//_Predν�ʣ� ����������bool��������() �� 
class greater200
{
public:
	bool operator()(int val)
	{
		return val > 200;
	}
}; 

void test3()
{
	vector<int> v;
	v.push_back(233);
	v.push_back(110);
	v.push_back(220);
	v.push_back(310);
	replace_if(v.begin(),v.end(),greater200(), 999); //����200�滻Ϊ999
	for_each(v.begin(),v.end(),MyPrint);	
}



//-------------------------------------------------------------------------- 
//swap(container c1, container c2);
//������������Ϊͬ������ 
void test4()
{
	vector<int> v1;
	vector<int> v2;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+10);
	}	
	swap(v1, v2);
	for_each(v1.begin(),v1.end(),MyPrint); 
	cout << endl;
	for_each(v2.begin(),v2.end(),MyPrint); 
} 
 
 
int main()
{
    //test1();
    //test2();
    //test3();
    test4();
	return 0;
}

