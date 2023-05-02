#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<ctime>
#include<algorithm>
#include<iomanip>
using namespace std; 

class Person
{
public:
	string m_name;
	double m_score;
	Person(string name, int score)
	{
		m_name = name;
		m_score = score;
	}
};

void creatPerson(vector<Person> &v)
{
	for(int i=0; i<5; i++)
	{
		string n = "ABCDE";
		string name = "ѡ��";
		name += n[i];
		int score = 0;
		Person p(name,score);
		v.push_back(p);
	}
}

void setScore(vector<Person> &v)
{
	for(vector<Person>::iterator it = v.begin(); it!=v.end(); it++)
	{
		deque<int> d;
	    for(int i=0; i<10; i++)
		{
			int s = rand() % (41) + 60; //60~100
			d.push_back(s);	
		}
		sort(d.begin(),d.end()); //���� 
		d.pop_back();
		d.pop_front();
	
		double sum = 0; 
		for(deque<int>::iterator dit = d.begin(); dit!=d.end(); dit++)
		{
			sum += (*dit); 
		}
		double avg = sum / d.size();
		(*it).m_score = avg;
    }
}

void printScore(vector<Person> &v)
{
	for(int i=0; i<v.size(); i++)
	{
		cout << "������" << v[i].m_name 
             << " ƽ���ɼ���" << fixed  << setprecision(2)  //���ñ�����λС�� 
			 << v[i].m_score << endl;                       //ͷ�ļ�#include<iomanip> 
	}
}

int main()
{
	srand((unsigned int)time(NULL));  //��������� 
	//��������ѡ��
	vector<Person> v;
	creatPerson(v); 
	//��ƽ��ֵ
	setScore(v); 
	//��ӡƽ����
	printScore(v); 
	return 0;
}

