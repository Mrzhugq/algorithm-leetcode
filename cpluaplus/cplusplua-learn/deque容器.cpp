#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

//deque����
//���ܣ�˫�����飬���Զ�ͷ�˽��в���ɾ������

//deque��vector����
//vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
//deque��Զ��ԣ���ͷ���Ĳ���ɾ����vector��
//vector����Ԫ�ص��ٶȻ��deque�죬������ߵ��ڲ�ʵ���й�

//deque�ĵ�����Ҳ��֧��������ʵģ��ռ�������



//----------------------------------------------------------------------------------
//deque���� ����ԭ��
/*
deque<T> deq              //Ĭ�Ϲ��� 
deque(beg, end);          //[begin,end)��ֵ����������Ϊ������ 
deque(n, elem);           //n��elem 
deque(const deque &deq);  //�������� 
*/ 

//��ӡ  ->  ע��������д����ģ�� 
template<typename T>
void PeintDeque(const deque<T> &d)
{
	for(typename deque<T>::const_iterator it = d.begin(); it!=d.end(); it++)
	{
		//*it = 100; �����޸ģ���Ϊ25��27�м�const�� 
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	//1. 
	deque<int> deq;
	for(int i=0; i<10; i++)
	{
		deq.push_back(i);
	}
	PeintDeque(deq);
	//2.
	deque<int> deq2(deq.begin(),deq.end());
    PeintDeque(deq2);
    //3.
    deque<int> deq3(10,3); //10��3
	//4.
	deque<int> deq4(deq3); //�������� 
} 



//----------------------------------------------------------------------------------
//deque��ֵ���� ����ԭ��
/*
deque& operator=(const deque &deq); //���� 
deque& assign(beg, end);                  //[beg,end)������Ϊ������ 
deque& assign(n, elem);                   //n��elem 
*/

void test2()
{
	deque<int> deq1;
	for(int i=0; i<10; i++)
	{
		deq1.push_back(i);
	}
	//1.
	deque<int> deq2 = deq1;
    PeintDeque(deq2);
    //2.
    deque<int> deq3;
    deq3.assign(deq1.begin(),deq1.end());
    //3.
    deque<int> deq4;
    deq4.assign(10,5); //10��5 
}  



//----------------------------------------------------------------------------------
//deque������С���� ����ԭ��
/*
empty();                   //�Ƿ�Ϊ�� 
size();                    //��С ��ע�������vector��һ��û����capacity�� 
resize(int num);           //����ָ����С��������0�����˺������ɾ�� 
resize(int num,int elem);  //����ָ����С��������elem�����˺������ɾ��
*/ 

void test3()
{
	deque<int> deq1;
	for(int i=0; i<10; i++)
	{
		deq1.push_back(i);
	}
	cout << deq1.empty() << endl;
	cout << deq1.size() << endl;
	
	deq1.resize(15);     //��0 
	PeintDeque(deq1);
//	deq1.resize(15,6);   //��6
//	PeintDeque(deq1);
	
	deq1.resize(5);    //ĩβɾ�� 
	PeintDeque(deq1);	
}



//----------------------------------------------------------------------------------
//deque�����ɾ�� ����ԭ��
/*
���˲��������
push_back(elem);   //β�� 
push_front(elem);  //ͷ��
pop_back();
pop_front();
ָ��λ�ò�����posΪ������ 
iterator insert(const_iterator pos, elem); //posλ�ò���elem������������(������)��λ�� 
void insert(const_iterator pos, int count, elem); //posλ�ò���n��elem
void insert(const_iterator pos, const_iterator start, const_iterator end);
//posλ�ò���[start,end)��������ݣ��޷���ֵ

iterator erase(const_iterator pos);        //ɾ��������posָ��Ԫ��
iterator erase(const_iterator start, const_iterator end); 
//ɾ����������start��end֮���Ԫ��[start,end)
claer();                         //��� 
*/ 

void test4()
{
	deque<int> d1;
	for(int i=0; i<5; i++)
	{
		d1.push_back(i); //β�� 
	} 
	for(int i=0; i<5; i++)
	{
		d1.push_front(i); //ͷ�� 
	}
	PeintDeque(d1);
	
	//2.
	d1.insert(d1.begin()+1, 10);  //�ڶ���λ�ò���10 
	//3.
	d1.insert(d1.begin(),5, 10); //ͷ��5��10 
	//4.
	deque<int> d2;
	d2.push_back(66);
	d2.push_back(77);
	d2.push_back(88);
	d1.insert(d1.begin(),d2.begin(),d2.end()); //ͷ������d2 
	PeintDeque(d1); 
	//5.
    //d2.erase(d2.begin()+1);
    deque<int>::iterator it = d2.erase(d2.begin()+1); //ɾ���ڶ����� 
    cout << "ɾ����" << endl;
    PeintDeque(d1); 
    cout << "��һ����Ϊ��" << *it << endl; 
}



//----------------------------------------------------------------------------------
//deque���ݴ洢  
/*
at(int Index);   //��������Index��ָ������ �������±��Ƿ�Խ�磩 
operator[];      //��������Index��ָ������ �������飩
front();         //���������е�һ��Ԫ��
back();          //���������� ���һ��Ԫ�� 
*/ 
void test5()
{
	deque<int> d1;
	for(int i=0; i<5; i++)
	{
		d1.push_back(i); //β�� 
	} 
	cout << d1[0] << endl;	
	cout << d1.at(1) << endl;
	
	cout << d1.front() << endl;	
	cout << d1.back() << endl;	
}
 
 
 
//----------------------------------------------------------------------------------
//deque���� (vectorҲ��)
//����֧��������ʵĵ���������������������sort�㷨����(Ĭ������)��ͷ�ļ�algorithm 
//sort(iterator beg, iterator end); //��[beg,end)����Ԫ�ؽ������� 

void test6()
{
	deque<float> d1;
	d1.push_back(23.7);
	d1.push_back(20.6);
	d1.push_back(50.4);
	sort(d1.begin(),d1.end());
	PeintDeque(d1); 
}



 
int main()
{
//	test1(); 
//	test2(); 
//	test3(); 
	test4(); 
//	test5(); 
//	test6(); 
	return 0;
}

