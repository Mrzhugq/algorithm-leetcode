#include<iostream>
#include<string> 
#include<vector>
#include<algorithm> 
using namespace std;

//STL (standard Template Library) ��׼ģ���
//STL �ӹ����Ϸ�Ϊ���������㷨��������
//�������㷨��֮��ͨ�� �����������޷�����
//STL �������еĴ��붼������ģ�������ģ�庯��

//STL����������������㷨�����������º�����������������������ռ�������
//1.�������������ݽṹvector,list,deque,set,map�������������
//2.�㷨�����ֳ������㷨sort,find,copy,for_each(����)��
//3.���������������������㷨֮��Ľ��ϼ�
//4.�º�������Ϊ���ƺ���������Ϊ�㷨��ĳ�ֲ���
//5.��������һ�����������������߷º�����������ӿڵĶ���
//6.�ռ�������������ռ�����������

//������
//����ʽ������ǿ��ֵ����������ʽ�����е�ÿ��Ԫ�ؾ��й̶���λ��(��ô�Ž�ȥ�������ھ���������) 
//����ʽ�������������ṹ����Ԫ��֮��û���ϸ�������ϵ�˳���ϵ (�Ž�ȥ���ܾͱ�������) 

//�㷨Algorithms
//�ʱ��㷨��ָ��������л����������Ԫ�ص����ݣ��������滻��ɾ���� 
//���ʱ��㷨��ָ��������в������������Ԫ�ص����ݣ����ң�������������Ѱ�Ҽ�ֵ��

//������
//�ṩһ�ַ�����ʹ֮�ܹ��������ĳ�����������ĸ���Ԫ�أ��������豩¶���������ڲ���﷽ʽ
//ÿ�����������Լ�ר���ĵ�����
//�������ǳ�������ָ�룬������������������Ϊ��˫���������������ʵ�����



//----------------------------------------------------------------------------
void myPrint(int val)
{
	cout << val << endl;
}


//vector��������������� 
void test1()
{
	//����int���� 
	vector<int> v;
	//���� 
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	
	//��һ�ֱ���
	
	//ͨ�����������������е�����
	vector<int>::iterator itBagin = v.begin();//��ʼ��������ָ�������еĵ�һ��Ԫ��
	vector<int>::iterator itEnd = v.end();//������������ָ�����������һ��Ԫ�ص���һ��λ�� 
	while(itBagin != itEnd)
	{
		cout << *itBagin << endl;
		itBagin++;
	} 
	
	//�ڶ��ֱ���������� 
	for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << *it << endl;
	} 
	
	//�����֣�����STL���ṩ�ı����㷨
    for_each(v.begin(),v.end(),myPrint); //myPrint��Ҫ�Լ�д
	
	//������ ���±���� 
	cout << v.at(1) << endl;  //������±��� 
	cout << v[1] << endl;     //������Խ�� 
}
 
 
 
//----------------------------------------------------------------------------
class Person
{
public:
	string m_name;
	int m_age;
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
}; 

//vector����Զ����������� 
void test2()
{
	vector<Person> v1;
	Person p1("ada",69);
	Person p2("fgs",79);
	Person p3("afb",49);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	for(vector<Person>::iterator it = v1.begin(); it!=v1.end(); it++)
	{
		//cout << "������" << (*it).m_name << " ���䣺" << (*it).m_age << endl; 
		cout << "������" << it->m_name << " ���䣺" << it->m_age << endl; 
	}
	//���� 
	for(int i=0; i<v1.size(); i++)
	{
		//cout << "������" << v1.at(i).m_name << " ���䣺" << v1.at(i).m_age << endl; 
		cout << "������" << v1[i].m_name << " ���䣺" << v1[i].m_age << endl; 
	}
} 
 
 
//----------------------------------------------------------------------------
//vector��������Ƕ������

void test3()
{
	//�൱�ڶ�ά���� 
	vector< vector<int> > v;
	//�ȴ���һά����
	vector<int> v1; 
	vector<int> v2; 
	vector<int> v3;
	for(int i=0; i<4; i++)
	{
		v1.push_back(i);   // 0  1  2  3
		v2.push_back(i+4); // 4  5  6  7
		v3.push_back(i+8); // 8  9  10 11
	}
    //��С�������������
	v.push_back(v1); 
	v.push_back(v2); 
	v.push_back(v3);
	
	//����
	//1.
	for(vector< vector<int> >::iterator it = v.begin(); it!=v.end(); it++)
	{
		for(vector<int>::iterator vit = (*it).begin(); vit!=(*it).end(); vit++)
		{
			cout << (*vit) << " ";
		}
		cout << endl;
    }
    //2.
    for(int i=0; i<v.size(); i++)
    {
    	for(int j=0; j < v[i].size(); j++)
    	{
    		cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
 
int main()
{
	//test1(); 
	//test2(); 
	test3(); 
	return 0;
}

