#include<iostream>
#include<algorithm> 
#include<numeric>
#include<functional>
#include<vector> 
#include<string>
using namespace std;

//���������㷨
//find           ����Ԫ��
//find_if        ����������Ԫ��
//adjacent_find  ���������ظ�Ԫ��
//binary_search  ���ֲ��ҷ�
//count          ͳ��Ԫ�ظ���
//count_if       ������ͳ��Ԫ�ظ���

 
//--------------------------------------------------------------------------------------
//1.
//iterator find(iterator beg, iterator end, value);�ҵ����ظ�Ԫ�ص��������Ҳ�������end() 
class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(const Person &p)//�����Զ���������Ҫ����== 
	{
		if(m_name == p.m_name && m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
    } 
	string m_name;
	int m_age;
}; 
void test1()
{
	//���������������� 
	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	vector<int>::iterator it = find(v.begin(),v.end(),10);
	cout << *it << endl;
	//�����Զ�����������
	vector<Person> v2;
	Person p1("afga",12); 
	Person p2("tryy",18);
	v2.push_back(p1);
	v2.push_back(p2);
	vector<Person>::iterator it2 = find(v2.begin(),v2.end(),p1);//�����Զ���������Ҫ��������== 
	cout << it2->m_name << " " << it2->m_age << endl;
}




//--------------------------------------------------------------------------------------
//2.
//iterator find_if(iterator beg, iterator end, _Pred);
//�ҵ����ظ�Ԫ�ص��������Ҳ�������end() 
//������������ _Pred��������ν��(����bool���͵ķº���) 

class GreatFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

class Great20
{
public:
	bool operator()(Person &p)
	{
		return p.m_age > 20;
	}
};

void test2()
{
	//1.
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	vector<int>::iterator it = find_if(v1.begin(),v1.end(),GreatFive ());
	cout << *it << endl;
	//2.
	vector<Person> v2;
	Person p1("aaa",15);
	Person p2("bbb",18);
	Person p3("ccc",30);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	//�����Ƿ����������20���� 
	vector<Person>::iterator it2 = find_if(v2.begin(),v2.end(),Great20 ());
	cout << it2->m_name << " " << it2->m_age << endl;
}



//--------------------------------------------------------------------------------------
//3.
//iterator adjacent_find(iterator beg, iterator end);
//���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�������û�з���end(); 

void test3()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	vector<int>::iterator it = adjacent_find(v.begin(),v.end());
	cout << *it << endl;
	//�����Ҫ�����Զ�������������Ҫ����==����� 
}
 


//--------------------------------------------------------------------------------------
//4.
//bool binary_search(iterator beg, iterator end, value);
//�����������в���value�Ƿ���ڣ�������٣����ֲ��ң� 

void test4()
{
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	//��9�Ƿ����
	bool ret = binary_search(v1.begin(), v1.end(), 9);
	cout << ret << endl;	
	
	//�����Զ���������Ҫ��������<�������ʹԪ������set/map�����Զ�������Ҳ��Ҫ����<�� 
} 



//--------------------------------------------------------------------------------------
//int count(iterator beg, iterator end, value);  ͳ��value���ֵĴ��� 
class Person2 
{
public:
	Person2(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(const Person2 &p)//ͳ���Զ���������Ҫ����== 
	{
		if(m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
    } 
	string m_name;
	int m_age;
}; 

void test5()
{
	//1.�����������;Ͳ�д��
	
	//2.�Զ�����������
	vector<Person2> v2;
	Person2 p1("aaa",15);
	Person2 p2("bbb",18);
	Person2 p3("ccc",30);
	Person2 p4("ddd",30);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	Person2 p("fff",30);
	//ͳ�ƺ�fffͬ����˵ĸ���
	int sum = count(v2.begin(),v2.end(),p);//��Ҫ����== 
	cout << sum << endl;	 
} 
 
 
//--------------------------------------------------------------------------------------
//int count_if(iterator beg, iterator end, _Pred); //������ͳ��, _PredΪν��(��������Ϊbool�ķº���) 

class greater20
{
public:
	bool operator()(int val)
	{
	    return val > 20;	
    } 
};

void test6()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(25);
	v1.push_back(30);
	int sum1 = count_if(v1.begin(),v1.end(),greater20 ());
	cout << sum1 << endl;
	
	//�Զ�������һ����Ҳ��Ҫдһ���º��� 
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

