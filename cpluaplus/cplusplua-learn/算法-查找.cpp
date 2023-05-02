#include<iostream>
#include<algorithm> 
#include<numeric>
#include<functional>
#include<vector> 
#include<string>
using namespace std;

//常见查找算法
//find           查找元素
//find_if        按条件查找元素
//adjacent_find  查找相邻重复元素
//binary_search  二分查找法
//count          统计元素个数
//count_if       按条件统计元素个数

 
//--------------------------------------------------------------------------------------
//1.
//iterator find(iterator beg, iterator end, value);找到返回该元素迭代器，找不到返回end() 
class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(const Person &p)//查找自定义类型需要重载== 
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
	//查找内置数据类型 
	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	vector<int>::iterator it = find(v.begin(),v.end(),10);
	cout << *it << endl;
	//查找自定义数据类型
	vector<Person> v2;
	Person p1("afga",12); 
	Person p2("tryy",18);
	v2.push_back(p1);
	v2.push_back(p2);
	vector<Person>::iterator it2 = find(v2.begin(),v2.end(),p1);//查找自定义类型需要类内重载== 
	cout << it2->m_name << " " << it2->m_age << endl;
}




//--------------------------------------------------------------------------------------
//2.
//iterator find_if(iterator beg, iterator end, _Pred);
//找到返回该元素迭代器，找不到返回end() 
//第三个参数是 _Pred函数或者谓词(返回bool类型的仿函数) 

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
	//查找是否有年龄大于20的人 
	vector<Person>::iterator it2 = find_if(v2.begin(),v2.end(),Great20 ());
	cout << it2->m_name << " " << it2->m_age << endl;
}



//--------------------------------------------------------------------------------------
//3.
//iterator adjacent_find(iterator beg, iterator end);
//查找相邻重复元素，返回相邻元素的第一个位置的迭代器，没有返回end(); 

void test3()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	vector<int>::iterator it = adjacent_find(v.begin(),v.end());
	cout << *it << endl;
	//如果需要查找自定义数据类型需要重载==运算符 
}
 


//--------------------------------------------------------------------------------------
//4.
//bool binary_search(iterator beg, iterator end, value);
//在有序序列中查找value是否存在，返回真假（二分查找） 

void test4()
{
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	//找9是否存在
	bool ret = binary_search(v1.begin(), v1.end(), 9);
	cout << ret << endl;	
	
	//查找自定义类型需要类内重载<运算符，使元素有序（set/map插入自定义类型也需要重载<） 
} 



//--------------------------------------------------------------------------------------
//int count(iterator beg, iterator end, value);  统计value出现的次数 
class Person2 
{
public:
	Person2(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(const Person2 &p)//统计自定义类型需要重载== 
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
	//1.内置数据类型就不写了
	
	//2.自定义数据类型
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
	//统计和fff同岁的人的个数
	int sum = count(v2.begin(),v2.end(),p);//需要重载== 
	cout << sum << endl;	 
} 
 
 
//--------------------------------------------------------------------------------------
//int count_if(iterator beg, iterator end, _Pred); //按条件统计, _Pred为谓词(返回类型为bool的仿函数) 

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
	
	//自定义类型一样，也需要写一个仿函数 
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

