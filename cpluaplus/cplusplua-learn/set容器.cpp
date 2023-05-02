#include<iostream>
#include<set>
#include<utility>
#include<functional>
using namespace std;


//set���������ϣ� -> ����Ԫ�ض����ڲ���ʱ�Զ����� ��set������������������� 
//set/multiset���ڹ���ʽ�������ײ�ṹ�Ƕ�����ʵ��
//set/multisetΨһ����
//            set���������������ظ���Ԫ��
//            multiset�������������ظ���Ԫ��


//-------------------------------------------------------------------------------- 
//set�����븳ֵ
/*
���죺
set<T> st;           //Ĭ�Ϲ��� 
set(const set &st);  //��������
��ֵ��
set& operator=(const set &st); //������= 
*/ 
void PrintSet(const set<int> &st)
{
	//��listһ��������ֻ����++ --�������� += -=����Ϊֻ��++ --������  
	for(set<int>::const_iterator it = st.begin(); it!=st.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
} 

void test1()
{
	set<int> st;
	//set��������ֻ��insert��û��push 
	st.insert(10);
	st.insert(30);
	st.insert(20);
	st.insert(30);
	PrintSet(st);     //10��20��30 set�Զ����򣬲����ظ���ȥ�� 
	
	set<int> st2(st); //��������
	PrintSet(st2);
	//��ֵ 
	set<int> st3;
	st3 = st;
	PrintSet(st3); 
}
 
 
 
 
//--------------------------------------------------------------------------------
//set�Ĵ�С�ͽ���
// size();       //Ԫ����Ŀ  ��set������ָ����С�� 
// empty();      //�Ƿ�Ϊ��
// swap(st);     //���������������� 

void test2()
{
	set<int> st;
	st.insert(10);
	st.insert(30);
	st.insert(20);
	cout << st.empty() << endl;
	cout << st.size() << endl;
	
	set<int> st2;
	st2.insert(50);
	st2.insert(90);
	st2.insert(40);
	st.swap(st2);
	PrintSet(st);
	PrintSet(st2);
}



//--------------------------------------------------------------------------------
//set����ɾ�� ����ԭ��
/*
insert(elem);                           //�������в���Ԫ��

iterator erase(const_iterator pos);     //ɾ��pos��������ָԪ�أ�������һԪ�صĵ�����
iterator erase(const_iterator start, const_iterator end);
//ɾ��[start,end)��������ݣ�������һԪ�ص�����
int erase(elem);                        //ɾ��������ֵΪelem��Ԫ��
clear();                                //��� 
*/ 

void test3()
{
	set<int> st;
	st.insert(30);
	st.insert(30);
	st.insert(10);
	st.insert(20);
	
	st.erase(st.begin()); //ɾ�������ĵ�һ�� -> 10 
	PrintSet(st);
	
	st.erase(30);         //ֵΪ30��ɾ�� 
	PrintSet(st);	
	//���
	st.erase(st.begin(),st.end());
	st.clear(); 
}



//--------------------------------------------------------------------------------
//set���Һ�ͳ��
//iterator find(key);     //����key�Ƿ���ڣ����ڷ��ظ�Ԫ�صĵ������������ڷ���set.end();
//int count(key);         //ͳ��keyԪ�ظ���������setֻ����0��1,����multiset����������ֵ 

void test4()
{
	set<int> st;
	st.insert(30);
	st.insert(30);
	st.insert(10);
	st.insert(20);
	
	set<int>::iterator fit = st.find(10);
	if(fit != st.end())
	{
		cout << "�ҵ��ˣ�" << *fit << endl; 
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}
	
	cout << "set��30���ֵĴ�����" << st.count(30) << endl;	
}


//--------------------------------------------------------------------------------
//set��multiset����
//1.set���ܲ����ظ����ݣ���multiset����
//2.set�������ݵ�ͬʱ�᷵�ز���������ʾ�Ƿ����ɹ�
//3.multiset���������ݣ���˿��Բ����ظ����� 

//set�� 
//pair<iterator, bool> insert(elem);
//����һ��pair�࣬iterator��elem�����λ�ã�bool�Ƿ����ɹ� 
void test5()
{
	set<int> st1;
	pair< set<int>::iterator, bool > ret1 = st1.insert(30);
	//pari�ǽ�����Ԫ�غϳ�һ�����ݣ����ߵ�һ��������Ҫ������������ʱ��pari��ʵ����һ���ṹ�� 
	if(ret1.second == true) //ret1.second ����pair���еĵڶ��� 
	{
		//cout << *(ret1.first) << endl; 
		cout << "��һ�β���30�ɹ���" << endl;
	}
	else
	{
		cout << "��һ�β���30ʧ�ܣ�" << endl; 
	}
	
	pair< set<int>::iterator, bool > ret2 = st1.insert(30);
	if(ret2.second == true) 
	{
		cout << "�ڶ��β���30�ɹ���" << endl;
	}
	else
	{
		cout << "�ڶ��β���30ʧ�ܣ�" << endl; 
	}
	
	st1.insert(10);
	st1.insert(20);
}

//multiset�� 
//iterator insert(elem);   //ֻ���ز����λ�� 
void test6()
{
    multiset<int> ms;
    ms.insert(20); 
	ms.insert(10);  
	ms.insert(10);  
 	for(multiset<int>::iterator it = ms.begin(); it!=ms.end(); it++)
	{
		cout << (*it) << endl; 
	}
	cout << "10�ĸ���Ϊ��" << ms.count(10) << endl;
}




//--------------------------------------------------------------------------------
//pair���鴴�� 
//�ɶԳ��ֵ����ݣ����ö�����Է�����������
//(�ǽ�����Ԫ�غϳ�һ�����ݣ����ߵ�һ��������Ҫ������������ʱ)

//pair<type,type> p(value1,value2);              //�вι���
//pair<type,type> p = make_pair(value1,value2);  //
//pair& operator=(const pair &p);                //��ֵ���� 

void test7()
{
	//1.
	pair<string,int> p("��ķ",28);
	cout << "������" << p.first << " ���䣺" << p.second << endl; 
	//2.
	pair<string,int> p2 = make_pair("����",18);
	cout << "������" << p2.first << " ���䣺" << p2.second << endl;  
}



//--------------------------------------------------------------------------------
//set�������� Ĭ�ϴ�С��������
//���÷º��������Ըı�����˳��

class Mycompare1
{
public:
	bool operator()(int val1, int val2)//����С���ţ��зº��� 
	{
		return val1 > val2;
	}
};

//������������ 
void test8()
{
	//set<int,greater<int>> s1;
	set<int,Mycompare1> s1;
	//Ҫ��Ҫ���򣬱���Ҫ�ڲ���ǰ����set�����������
	 
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	for(set<int,greater<int>>::iterator it = s1.begin(); it!=s1.end(); it++)
	{
		cout << *it << endl;
	}	
}



class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
}; 

class Mycompare2
{
public:
    bool operator()(const Person &p1,const Person &p2)
	{
		return p1.m_age > p2.m_age; //�����併�� 
	}	
}; 
//�����Զ����������� 
void test9()
{
	//�Զ����������ͣ���Ӧ��ָ�����������Ϊ������Ҳ��֪����ô�� 
	set<Person,Mycompare2> s1; 
	Person p1("saf",13); 
	Person p2("ofa",10); 
	Person p3("ugh",25); 
	Person p4("pAF",5);
	s1.insert(p1); 
	s1.insert(p2); 
	s1.insert(p3); 
	s1.insert(p4); 
	for(set<Person,Mycompare2>::iterator it = s1.begin(); it!=s1.end(); it++)
	{
		cout << "������" << it->m_name << "  ���䣺" << it->m_age << endl;
	}
}

//set��������< ���� () ʵ���Զ������ݵ������ȥ��
//����<һ��д����Ҫ�Ƚ϶��Զ������͵����棨���ڣ� 
//������()һ������дһ�������set�Ĳ��������б��У����⣩ 
//ֻҪ����Ҫ�Ƚϵ�������ȵ�ʱ�򷵻�false���� 
//set�����ж��Ƿ����ʱ����������αȽϺ�����A<B false; B<A false; -> A��B��� 
 
//--------------------------------------------------------------------------------
int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6(); 
//    test7();
//    test8();
      test9();
	return 0;
}

