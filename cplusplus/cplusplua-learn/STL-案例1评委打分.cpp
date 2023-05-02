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
		string name = "选手";
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
		sort(d.begin(),d.end()); //排序 
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
		cout << "姓名：" << v[i].m_name 
             << " 平均成绩：" << fixed  << setprecision(2)  //设置保留二位小数 
			 << v[i].m_score << endl;                       //头文件#include<iomanip> 
	}
}

int main()
{
	srand((unsigned int)time(NULL));  //随机数种子 
	//创建五名选手
	vector<Person> v;
	creatPerson(v); 
	//求平均值
	setScore(v); 
	//打印平均分
	printScore(v); 
	return 0;
}

