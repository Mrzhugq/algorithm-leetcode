#include<iostream>
#include<list> 
#include<algorithm>
#include<functional> 
using namespace std;

//list���� -> ��������ռ������
//������������ɣ�һ���Ǵ洢���ݵ�Ԫ����������һ���Ǵ洢��һ������ַ��ָ��

//STL�е�������һ�� ˫��ѭ������
//��������Ĵ洢��ʽ�������������ڴ�ռ䣬�������list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ�����˫������� 
//list�ŵ㣺��ȡ��̬���䣬��������ڴ��˷Ѻ����
//          ����ɾ��ʮ�ַ��㣬����Ҫ�ƶ�����Ԫ��
//listȱ�㣺��Ȼ�����ǿռ�(ָ����)���ͱ���ʱ�������ʽϴ�
//list��һ����Ҫ�����ʣ�����ɾ���������������ԭ��list��������ʧЧ������vector�ǲ�������


//--------------------------------------------------------------------------------
//list���캯��
/*
list<T> ist;                  //Ĭ�Ϲ���
list(lst.begin(), lst.end()); //��lst��[begin,end)���丳ֵ������
list(int n, elem)             //n��elem����������
list(const list &lst);        //�������� 
*/ 

void PrintList(const list<int> &l)
{
	for(list<int>::const_iterator it = l.begin(); it!=l.end(); it++)
	{
		cout << (*it) << " "; 
	}
	cout << endl;
} 

void test1()
{
	list<int> l1;   //Ĭ�Ϲ��� 
	//�������
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_back(40); 
	PrintList(l1);
	//2.
	list<int>::iterator it = l1.begin();
	//it += i;                  //���� 
	it++;                       //��ȷ����Ϊ++��--���������ˣ���+=��-=û�б����� 
	list<int> l2(it, l1.end()); //����l1�ĵ�һ�����ݣ����������Ƹ�l2 
	PrintList(l2);
	//3.
	list<int> l3(l1);
	PrintList(l3); 
	//4. 
	list<int> l4(5,10); //5��10  
} 



//--------------------------------------------------------------------------------
//list��ֵ�ͽ��� ����ԭ��
/*
list& operator=(const list &lst);  //����
assign(beg, end);                  //��[beg,end)�������ݿ�������������Ϊ������
assign(n, elem);                   //n��elem
swap(lst);                         //��lst�뱾��Ԫ�ػ���    
*/  

void test2()
{
	list<int> l1;
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_back(40); 
	//1.
	list<int> l2;
	l2 = l1;
	PrintList(l2); 
	//2.
	list<int> l3;
	l3.assign(l1.begin(),l1.end());
	PrintList(l3);
	//3.
	list<int> l4;
	l4.assign(5,10); //5��10;
	PrintList(l4);
	//4.
	l4.swap(l1);
	PrintList(l1);
	PrintList(l4);	
}


//--------------------------------------------------------------------------------
//list��С���� ����ԭ��
/*
empty();                //�Ƿ�Ϊ�� 
size();                 //��С  (û������capacity��˵�� 
resize(int num);        //����ָ����С���䳤���㣬���ĩβ������ɾ��
resize(int num, elem)   //����ָ����С���䳤elem�����ĩβ������ɾ��
*/ 

void test3()
{
    list<int> l1;
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_back(40);
	
	cout << l1.empty() << endl; 
	cout << l1.size() << endl; 
	
	l1.resize(10);
	PrintList(l1);
	
	l1.resize(20,66);
	PrintList(l1); 
}



//--------------------------------------------------------------------------------
//list�����ɾ�� ����ԭ��
/*

push_back(elem);    //β��
pop_back();         //βɾ 
push_front(elem);   //ͷ��
pop_front();        //ͷɾ

iterator insert(const_iterator pos, elem);  //������ָ��λ��pos����Ԫ��ele,����������λ�� 
void insert(const_iterator pos, int count, elem); //������ָ��λ��pos����count��Ԫ��ele  
void insert(const_iterator pos, const_iterator start, const_iterator end);
//posλ�ò���[start,end)��������ݣ��޷���ֵ

iterator erase(const_iterator pos);        //ɾ��������posָ��Ԫ��,������һ������λ�ã��������� 
iterator erase(const_iterator start, const_iterator end); 
//ɾ����������start��end֮���Ԫ��[start,end)��������һ������λ�ã��������� 
remove(elem);       //ɾ��������������elemֵƥ���Ԫ�� 
clear();            //��� 
*/ 


void test4()
{
    list<int> l1;
	l1.push_back(10); //β�� 
	l1.push_back(20); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_front(5); //ͷ�� 
	l1.push_front(6);
	l1.push_front(7);
	PrintList(l1);
	
	list<int>::iterator it = l1.begin();
	it++;
	l1.insert(it,1000); 
	PrintList(l1);
	
	it = l1.begin();
	l1.erase(it);
	PrintList(l1);
	
	l1.remove(20); //����20��ֵ��ɾ�� 
	PrintList(l1);
}
 

//--------------------------------------------------------------------------------
//list���ݴ�ȡ �� ��֧��operator[],lst.at(i) �� 
//front();  //���ص�һ��Ԫ��
//back();   //�������һ������


void test5()
{
    list<int> l1;
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_back(40); 
	cout << "ͷ���ݣ�" << l1.front() << endl;
	cout << "β���ݣ�" << l1.back() << endl;
	
	//��������֧���������
	list<int>::iterator it = l1.begin();
	//it += 3;      //����û������
	it++;           //��ȷ��STL�����ˣ�ֻ��һ��һ�μ� 
	it--;           //��ȷ�����Ե�������˫������� 
}


//--------------------------------------------------------------------------------
//list��ת������
//reverse();          //��ת����ע������reverse��reserve(vector��Ԥ���ռ�) 
//sort();             //�������� 

bool myCompare(int a,int b) //�Լ�д�ȽϺ�����ʵ�ֽ��� 
{
	return a > b; 
} 

void test6()
{
	list<int> l1;
	l1.push_back(23); 
	l1.push_back(45); 
	l1.push_back(10); 
	l1.push_back(9);
	cout << "��תǰ��" << endl; 
	PrintList(l1); 
	cout << "��ת��" << endl; 
	l1.reverse();
	PrintList(l1);
	
	//sort(l1.begin(),l1.end()); //������Ϊֻ�е�����֧��������ʣ������ñ�׼�㷨
	//���������׼�㷨�����Ǹ�ȫ�ֺ���
	//���Բ�֧��������ʵĵ��������������ڲ����ṩһЩ��Ӧ���㷨(��Ա����) 
	l1.sort();     //Ĭ������ 
	cout << "�����(����)��" << endl; 
	PrintList(l1);
	
	//l1.sort(greater<int>());
	l1.sort(myCompare);  //����l1.sort(greater<int>()); ͷ�ļ�#include<functional>  
	cout << "�����(����)��" << endl; 
	PrintList(l1);
}
 
int main()
{
	//test1(); 
	//test2(); 
	//test3(); 
	//test4(); 
	//test5(); 
	test6(); 
	return 0;
}
