#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional> 
using namespace std;

//�ڽ���������(�ڽ��º���)
//�����º�������ϵ�º������߼��º���

//��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
//ʹ���ڽ��º�������Ҫͷ�ļ�#include<functional> 


//---------------------------------------------------------------------------------
//�����º���
//���ܣ�ʵ���������㣬����negate��һԪ���㣬�������Ƕ�Ԫ���� 
/*
template<class T> plus<T>        //�ӷ� 
template<class T> minus<T>       //�ӷ� 
template<class T> multiplies<T>  //�˷� 
template<class T> divides<T>     //���� 
template<class T> modulus<T>     //ȡģ 
template<class T> negate<T>      //ȡ�� 
*/

void test1()
{
	//ȡ�� 
	negate<int> n;
	cout << n(50) << endl; 
	//�ӷ�
	plus<int> p;
	cout << p(10,20) << endl; 
}


//---------------------------------------------------------------------------------
//��ϵ�º���
/*
template<class T>  bool equal_to<T>       //���� 
template<class T>  bool not_equal_to<T>   //������ 
template<class T>  bool greater<T>        //���� 
template<class T>  bool greater_equal<T>  //���ڵ��� 
template<class T>  bool less<T>           //С�� 
template<class T>  bool less_equal<T>     //С�ڵ��� 
*/ 

void test2()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(5);
	sort(v.begin(),v.end(),less<int>());     //����(������Ĭ�ϲ�������less<T>(),���Բ�д) 
	sort(v.begin(),v.end(),greater<int>());  //����	 
}


//---------------------------------------------------------------------------------
//�߼��º���(�����ò���) 
/*
template<class T>   bool logical_and<T>   //�߼��� 
template<class T>   bool logical_or<T>    //�߼��� 
template<class T>   bool logical_not<T>   //�߼��� 
*/ 

void test3()
{
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	
	//�����߼��ǣ�������v1���˵�v2�����У�������ȡ������
	vector<bool> v2;
	v2.resize(v1.size()); //��Ҫ�ȿ��ٺÿռ� 
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>()); 
	//transform�㷨 ǰ����������Ҫ�������������䣬�������ǰ��˵���������ʼλ�ã�
	//���ĸ������ǰ��˹�������Ҫ������ 
}



int main()
{
	//test1(); 
	//test2(); 
	test3(); 
	return 0;
}

