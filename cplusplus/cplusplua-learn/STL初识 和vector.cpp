#include<iostream>
#include<string> 
#include<vector>
#include<algorithm> 
using namespace std;

//STL (standard Template Library) 标准模板库
//STL 从广义上分为：容器，算法，迭代器
//容器，算法，之间通过 迭代器进行无缝链接
//STL 几乎所有的代码都采用了模板类或者模板函数

//STL六大组件：容器，算法，迭代器，仿函数，适配器（配接器），空间配置器
//1.容器：各种数据结构vector,list,deque,set,map等用来存放数据
//2.算法：各种常见的算法sort,find,copy,for_each(遍历)等
//3.迭代器：扮演了容器和算法之间的胶合剂
//4.仿函数：行为类似函数，可作为算法的某种策略
//5.适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
//6.空间适配器：负责空间的适配与管理

//容器：
//序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置(怎么放进去的容器内就是怎样的) 
//关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系 (放进去可能就被排序了) 

//算法Algorithms
//质变算法：指运算过程中会更该区间内元素的内容（拷贝，替换，删除） 
//非质变算法：指运算过程中不会更该区间内元素的内容（查找，计数，遍历，寻找极值）

//迭代器
//提供一种方法，使之能够依序访问某个容器所含的各个元素，而又无需暴露该容器的内部表达方式
//每个容器都有自己专属的迭代器
//迭代器非常类似于指针，常见容器迭代器种类为：双向迭代器，随机访问迭代器



//----------------------------------------------------------------------------
void myPrint(int val)
{
	cout << val << endl;
}


//vector存放内置数据类型 
void test1()
{
	//类似int数组 
	vector<int> v;
	//插入 
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	
	//第一种遍历
	
	//通过迭代器访问容器中的数据
	vector<int>::iterator itBagin = v.begin();//起始迭代器，指向容器中的第一个元素
	vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个位置 
	while(itBagin != itEnd)
	{
		cout << *itBagin << endl;
		itBagin++;
	} 
	
	//第二种遍历（多见） 
	for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << *it << endl;
	} 
	
	//第三种，利用STL中提供的遍历算法
    for_each(v.begin(),v.end(),myPrint); //myPrint需要自己写
	
	//第四种 ：下标访问 
	cout << v.at(1) << endl;  //会进行下标检查 
	cout << v[1] << endl;     //不会检查越界 
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

//vector存放自定义数据类型 
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
		//cout << "姓名：" << (*it).m_name << " 年龄：" << (*it).m_age << endl; 
		cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << endl; 
	}
	//或者 
	for(int i=0; i<v1.size(); i++)
	{
		//cout << "姓名：" << v1.at(i).m_name << " 年龄：" << v1.at(i).m_age << endl; 
		cout << "姓名：" << v1[i].m_name << " 年龄：" << v1[i].m_age << endl; 
	}
} 
 
 
//----------------------------------------------------------------------------
//vector容器里面嵌套容器

void test3()
{
	//相当于二维数组 
	vector< vector<int> > v;
	//先创建一维数组
	vector<int> v1; 
	vector<int> v2; 
	vector<int> v3;
	for(int i=0; i<4; i++)
	{
		v1.push_back(i);   // 0  1  2  3
		v2.push_back(i+4); // 4  5  6  7
		v3.push_back(i+8); // 8  9  10 11
	}
    //将小容器插入大容器
	v.push_back(v1); 
	v.push_back(v2); 
	v.push_back(v3);
	
	//遍历
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

