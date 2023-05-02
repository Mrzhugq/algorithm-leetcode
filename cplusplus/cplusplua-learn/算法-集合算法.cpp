#include<iostream>
#include<algorithm> 
#include<functional>
#include<vector> 
#include<string>
using namespace std;

//�����ļ����㷨
//set_intersection �����������Ľ���
//set_union        �����������Ĳ���
//set_difference   �����������Ĳ

//---------------------------------------------------------------------------------
//iterator set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

//iterator set_intersection //��������Զ�������������Ҫ_Pred����ָ���������(ν��) ��
//(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest, _Pred);

//���ؽ��������λ�õ����� 
//��������(ǰ���������)�Ľ����ŵ�Ŀ�������У�destΪĿ�������ĵ����� 
void Print(int val)
{
	cout << val << " ";
}
 
void test1()
{
    vector<int> v1;
	vector<int> v2;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}	
	vector<int> vTarget; //��Ҫ��ǰ���ٿռ�
	//������һ����������һ����������������Ҫ����������������С��size��С
	int size = min(v1.size(), v2.size()); 
	vTarget.resize(size);//������10���ռ䣨5��6��7��8��9��0��0��0��0��0�� 
	
	vector<int>::iterator itEnd = 
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//���ص���ʵ��9�����λ�� 
	for_each(vTarget.begin(), itEnd, Print);
	//for_each(vTarget.begin(), vTarget.end(), Print); //������Ѻ����ֵ��ӡ���� 
}


//---------------------------------------------------------------------------------
//iterator set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//��������ǰ�������򣨷���ֵ�ͽ���һ���� 
//�Զ����������ͺ�set_intersectionһ������Ҫ��������� 
void test2()
{
    vector<int> v1;
	vector<int> v2;
	for(int i=0; i<5; i++)
	{
		v1.push_back(i);   //(0,1,2,3,4)
		v2.push_back(i+2); //(2,3,4,5,6)
	}
	vector<int> vTarget; //Ҳ��Ҫ��ǰ���ٿռ�
	int size = v1.size() + v2.size(); //������ʱ�� 
	vTarget.resize(size);  //(1,2,3,4,5,6,0,0,0,0)
	
	vector<int>::iterator itEnd = 
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//����ֵ�ǽ�����������һ��Ԫ��λ�ã���6�����λ�� 
	for_each(vTarget.begin(), itEnd, Print);	
}


//---------------------------------------------------------------------------------
//iterator set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//��������ǰ�������򣨷���ֵ�ͽ���һ���� 
//�Զ����������ͺ�set_intersectionһ������Ҫ��������� 


void test3()
{
    vector<int> v1;
	vector<int> v2;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);   //(0,1,2,3,4,5,6,7,8,9)
		v2.push_back(i+5); //(5,6,7,8,9,10,11,12,13,14)
	}	
	//v1��v2�Ĳ = v1 - (v1 ��v2)  ->  1,2,3,4  
	//v2��v1�Ĳ = v2 - (v1 ��v2)  ->  10,11,12,13,14
	vector<int> vTarget;
	int size =  max(v1.size(), v2.size()); //�������������û�н���
	vTarget.resize(size);
	
	//v1��v2� 
	vector<int>::iterator itEnd = 
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, Print);
    cout << endl <<  "----------------" << endl; 
    //v2��v1�
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());  
	for_each(vTarget.begin(), itEnd, Print);
}




int main()
{
	//test1(); 
	//test2(); 
	test3(); 
	return 0;
}

