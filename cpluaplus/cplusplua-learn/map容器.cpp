#include<iostream>
#include<map> 
#include<string>
using namespace std;

//map/multimap������ 
//map������Ԫ�ض���pair
//pair��һ��Ԫ��Ϊkey����ֵ�������������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
//����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����

//map/multimap���ڹ���ʽ�������ײ�ʵ�ֽṹ�Ƕ�����ʵ��
//map/multimap������Ҳ����˫�����������֧��������� 

//�ŵ㣺���Ը���keyֵ�����ҵ�valueֵ
//map��multimap����map���������������ظ�keyԪ��(value�����ظ�)��multimap�������ظ�keyԪ��


//-------------------------------------------------------------------------------- 
//map�����븳ֵ
/*
���죺
map<T1,T2> mp;                //Ĭ�Ϲ���
map(const map &mp);           //��������
��ֵ��
map& operator=(const map &mp) //���� 
*/

//template<typename T1,typename T2>
//void PrintMap(const map<T1,T2> &mp)
//{
//	for(typename map<T1,T2>::const_iterator it = mp.begin(); it!=mp.end(); it++)
//	{
//		cout << "Key = " << (*it).first << " Value = " << it->second << endl; 
//	}
//}

void PrintMap(const map<int,int> &mp)
{
	for(typename map<int,int>::const_iterator it = mp.begin(); it!=mp.end(); it++)
	{
		cout << "Key = " << (*it).first << " Value = " << it->second << endl; 
	}
}

void test1()
{
	map<int,int> mp; 
	//map����Ҳֻ��insert,�������������Ƕ��� 
	mp.insert(pair<int,int>(1,10));  //pair�����������map
	mp.insert(pair<int,int>(3,30));  //��key������ 
	mp.insert(pair<int,int>(2,20));
	mp.insert(pair<int,int>(4,40));
    PrintMap(mp);
    
    map<int,int> mp2(mp);
    PrintMap(mp);
    
    map<int,int> mp3;
    mp3 = mp;
    PrintMap(mp3);
} 



//-------------------------------------------------------------------------------- 
//map�����Ĵ�С�ͽ���
//size();               //��С 
//empty();              //�Ƿ�Ϊ�� 
//swap(mp);             //�������� 

void test2()
{
	map<int,int> mp; 
	mp.insert(pair<int,int>(1,10));
	mp.insert(pair<int,int>(3,30));
	mp.insert(pair<int,int>(2,20));
	mp.insert(pair<int,int>(4,40));
    PrintMap(mp);
	cout << mp.empty() << endl;
	cout << mp.size() << endl;
	
	map<int,int> mp2; 
	mp2.insert(pair<int,int>(5,50));
	mp2.insert(pair<int,int>(6,60));	
	mp.swap(mp2);//���� 
}



//-------------------------------------------------------------------------------- 
//map�Ĳ�����ɾ��
/*
insert(elem);     //elem�Ǹ�����
iterator erase(const_iterator pos);     //ɾ��pos��������ָԪ�أ�������һԪ�صĵ�����
iterator erase(const_iterator start, const_iterator end);
//ɾ��[start,end)��������ݣ�������һԪ�ص�����
int erase(key);                        //ɾ��������ֵΪkey��Ԫ��
clear();                               //��� 
*/ 

void test3()
{
	map<int,int> mp; 
	//1.���� 
	mp.insert(pair<int,int>(1,10));
	mp.insert(pair<int,int>(3,30));
	//2.
	mp.insert(make_pair(4,40));
	//3.
	mp.insert(map<int,int>::value_type(5,50));
	//4.�����������  ����multimap��������[]��insert�� 
	mp[6] = 60; //�ڲ�������[] 

	cout << mp[7] << endl; 
	//û��֮ǰû�в���keyΪ7�Ķ��飬���������Զ������ˣ�valueΪ0��mp�������һ������(7,0) 
	//���������key�������еĶ��������value������ cout << mp[1] << endl; 
	PrintMap(mp);
	//ɾ��
	mp.erase(mp.begin());      //ͷɾ 
	int ret = mp.erase(4);               //ɾ��keyΪ3�Ķ���	
	PrintMap(mp);
} 



//-------------------------------------------------------------------------------- 
//map���Һ�ͳ��
//find(key);       //����key�Ƿ���ڣ������ڣ����ظý�Ԫ�صĵ������������ڷ���mp.end();
//count(key);      //ͳ��key��Ԫ�ظ���������mapֻ����0��1,����multimap����������ֵ 


void test4()
{
	map<int,int> mp; 
	mp.insert(pair<int,int>(1,10));
	mp.insert(pair<int,int>(3,30));	
	map<int,int>::iterator it = mp.find(3);
    if(it != mp.end())
    {
    	cout << "�ҵ��� value = " << (it->second) << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}
}



//-------------------------------------------------------------------------------- 
//map��������(�Զ����������ͱ���ָ���������) 
//Ĭ�ϰ�key���򣬿������÷º����ı�������� (��set����һ��) 

class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

void test5()
{
	map<int,int,MyCompare> mp1;
	//���� map<int,int,greater<int>> mp1;
	mp1.insert(pair<int,int>(1,10)); 
	mp1.insert(pair<int,int>(2,20)); 
	mp1.insert(make_pair(3,30));
	mp1.insert(make_pair(6,60));
	mp1.insert(make_pair(5,50));
    for(map<int,int,MyCompare>::iterator it = mp1.begin(); it!=mp1.end(); it++)
    {
        cout << "Key = " << (*it).first << " Value = " << it->second << endl; 	
	}
}




int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
    test5();
//    test6(); 
	return 0;
}

