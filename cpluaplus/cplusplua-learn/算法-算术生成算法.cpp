#include<iostream>
#include<algorithm> 
#include<vector> 
#include<string>
#include<numeric> 
using namespace std;

//���������㷨 ��Ҫͷ�ļ�#include<numeric> 
//accumulate   ����������Ԫ���ۼ��ܺ�
//fill         ���������Ԫ��


//------------------------------------------------------------------------ 
//accumulate(iterator beg, iteator end, value);
//������������ʾ��value��ʼ�ۼ� 

//��ʵ���е��ĸ�������һ����������һ����������(����������С����)
 
void test1()
{
	vector<int> v;
	for(int i=0; i<=100; i++) //v�ܺ�Ϊ5050 
	{
		v.push_back(i);
	}
	int total = accumulate(v.begin(), v.end(), 0);
	cout << total << endl;
}




//------------------------------------------------------------------------ 
//fill(iterator beg, iterator end, value);
//���������пռ����Ϊvalue 

void test2()
{
	vector<int> v;
	v.resize(10); //10��0
	
	//����������� 
	fill(v.begin(),v.end(),100); //10��100 
} 


int main()
{
    //test1();
    test2();
	return 0;
}

