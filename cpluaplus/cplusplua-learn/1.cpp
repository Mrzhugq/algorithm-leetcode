#include<iostream>
#include<set> 
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

class Person1
{
public:
	string m_name;
	int m_age;
	int m_hight;
	Person1(string name,int age,int hight)
	{
		m_name = name;
		m_age = age;
		m_hight = hight;
	}
	//���� 
	bool operator<(const Person1 &p) const //������ȥ�أ�����߽��� 
	{
		if(m_age == p.m_age)
		{
			return false;
		}
		else
		{
			return m_hight > p.m_hight;
		}
	}
}; 

void test1()
{
    set<Person1> s1;
	Person1 p1("ada",16,145);
	Person1 p2("wge",16,185);
	Person1 p3("zwet",18,190);
	Person1 p4("opp",16,185);
	Person1 p5("ZHB",20,160);
	Person1 p6("yugl",20,170);
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);
	s1.insert(p6);
	for(set<Person1>::iterator it = s1.begin(); it!=s1.end(); it++)
	{
		cout << it->m_name << " " << it->m_age << " " << it->m_hight << endl; 
	}
}


//--------------------------------------------------------------------------------
class Person2
{
public:
	string m_name;
	int m_age;
	int m_hight;
	Person2(string name,int age,int hight)
	{
		m_name = name;
		m_age = age;
		m_hight = hight;
	}
}; 

//���� 
class CmpPerson2
{
public:
    bool operator()(const Person2 &p1,const Person2 &p2) const //������ȥ�أ�����߽��� 
	{
		if(p1.m_age == p2.m_age)
		{
			return false;
		}
		else
		{
			return p1.m_hight > p2.m_hight;
			// 170 	160
			// 160  170
		}
	}	
};

void test2()
{
    set<Person2,CmpPerson2> s1;  //ע����������治һ�� 
	Person2 p1("ada",16,145);
	Person2 p2("wge",16,185);
	Person2 p3("zwet",18,190);
	Person2 p4("opp",16,185);
	Person2 p5("ZHB",20,160);
	Person2 p6("yugl",20,170);
	Person2 p7("opp",16,199);   //���ﲻ���ˣ�ȥ�����ز�֪��Ϊ�� 
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);
	s1.insert(p6);
	s1.insert(p7);
	for(set<Person2>::iterator it = s1.begin(); it!=s1.end(); it++)
	{
		cout << it->m_name << " " << it->m_age << " " << it->m_hight << endl; 
	}	
} 


void test3()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(23);
	v1.push_back(30);
	cout << count_if(v1.begin(), v1.end(), not1(bind2nd(less<int>(), 20))) << endl;
	//��С��20���� 
} 



//------------------------------------------------------------------------------------
void print() //���һ�� 
{
	
}

template<typename T, typename... Types>  //ע��ÿ�е�...λ�� 
void print(const T& firstArg, const Types&... args)
{
    cout << firstArg << endl;
	print(args...);
}

void test4()
{
	//cout << __cplusplus << endl;
	print(7.5, "Hello", 61, 01010101001, "Word"); 
} 




//-------------------------------------------------------------------
void test5()
{
    char ch1 = 'a';
	cout << sizeof(ch1) << endl;	
	char& ch2 = ch1;
	cout << sizeof(ch2) << endl; //ch2�ײ�ʵ���Ǹ�ָ�룬4���ֽڣ�
		 				   		 //���������������sizeof(ch2) == sizeof(ch1);  &ch2 == &ch1; 
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test3();
	//test4();
	test5();
	return 0;
}

