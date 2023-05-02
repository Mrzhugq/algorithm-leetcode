#include<iostream>
#include<string>
using namespace std;

//------------------------------------------------------------------------------
//��ͨ������ģ�庯�������� (��ʽ����ת������ת����ת�������ܾͱ���) 
//1.��ͨ�������ÿ��Է���  ��ʽ����ת��
//2.����ģ�� ���Զ������Ƶ��������Է�����ʽ����ת��
//3.����ģ�� ����ʾָ�����ͣ����Է�����ʽ����ת�� 


//��ͨ���� 
int MyAdd(int a, int b)
{
	return a+b;
}

//ģ�庯�� 
template<typename T>
T MyAdd2(T a, T b)
{
	return a + b;
} 

//��ͨ�������� 
void test1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << MyAdd(a,b) << endl; 
	
	cout << MyAdd(a,c) << endl; 
	//��ʽ����ת����,�ڴ�������а��ַ���ת��Ϊ������ c -> 99 
	 
}

//ģ�庯������ 
void test2()
{
    int a = 10;
	int b = 20;
	char c = 'c';
	
	//1.�Զ������Ƶ� 
	cout << MyAdd2(a,b) << endl;  
	//cout << MyAdd2(a,c) << endl; //���� ������ʽ����ת������������֪��T��char����int
	
	//2.��ʾָ������ (һ�������ַ���) 
    cout << MyAdd2<int>(a,b) << endl;     
    cout << MyAdd2<int>(a,c) << endl; //��ȷ��T�������Ѿ���ȷint    
    
}  




//------------------------------------------------------------------------------
//��ͨ�����ͺ���ģ��ĵ��ù���
//1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//3.����ģ��Ҳ���Է�������
//4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

void MyPrint(int a, int b)
{
	cout << "���õ���ͨ����" << endl;
} 

template<typename T>
void MyPrint(T a, T b)
{
	cout << "���õĺ���ģ��" << endl; 
}

//ģ������ 
template<typename T>
void MyPrint(T a, T b, T c)
{
	cout << "���õ����صĺ���ģ��" << endl; 
}


void test3()
{
	int a = 10;
	int b = 20;
	MyPrint(a,b); //1.���ȵ�����ͨ����
	
	//2.ͨ����ģ������б���ǿ�Ƶ��ú���ģ�� 
	MyPrint<>(a,b);  // <> �����ģ�� 
	
	//3.����ģ��Ҳ���Է�������
	MyPrint<>(a,b,100);
	
	//4.���ģ��ɲ������õ�ƥ�䣬���ȵ�ģ��
	char ch1 = 'a';     //��Ϊ��char,������ͨ������Ҫ������ʽת�������Ե�ģ�� 
	char ch2 = 'b';
	MyPrint(ch1,ch2);
    
    //��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ����� 
}



//------------------------------------------------------------------------------
//ģ��ľ����� 

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};

template<typename T>
void fun(T a, T b)
{
	a = b;
}
//���a��b���Զ������ͣ�Person��������ȣ�Ҳ���޷�����������
//���C++Ϊ�˽���������⣬�ṩ��ģ������أ�����Ϊ��Щ�ض��������ṩ ���廯��ģ�� 
//��ȻҲ������������أ����鷳 


//�Ƚ��������Ƿ����ģ�� 
template<typename T>
bool MyCom(T &a, T &b)
{
	if(a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���廯Person��ģ�� -> �����Person�������ȵ��� 
//template<> bool MyCom<Person>(Person &p1, Person &p2)
template<> 
bool MyCom(Person &p1, Person &p2)
{
	if(p1.m_name == p2.m_name && p1.m_age == p2.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}
} 

void test4()
{
	int a = 10;
	int b = 20;
	cout << MyCom(a,b) << endl; 
	
	Person p1("����",18);
	Person p2("����",18);
	cout << MyCom(p1,p2) << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

