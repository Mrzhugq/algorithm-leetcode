#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


//谓词
//返回bool类型的仿函数称为谓词
//如果operator()接受一个参数，那么叫做一元谓词 
//如果operator()接受两个参数，那么叫做二元谓词 


//-------------------------------------------------------------------------------- 
//1.一元谓词 
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
}; 

void test1()
{
	vector<int> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(i);
	}
	
	//查找容器中有没有大于5的数字
	//GreaterFive() 匿名函数对象 
	vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());    
	//find_if算法,第三个参数需要一个谓词 
	//find_if找到返回迭代器，找不到返回v.end(); 
	if(it == v.end())
	{
		cout << "没找到" << endl; 
	}
	else
	{
		cout << "找到了" << *it << endl;
	}
}


//-----------------------------------------------------------------------------
//2.二元谓词 

class Mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
}; 

void test2()
{
	vector<int> v;
	v.push_back(10);	
	v.push_back(6);	
	v.push_back(20);	
	v.push_back(1);
	
	sort(v.begin(),v.end(),Mycompare());
	//Mycompare()也是一个匿名对象 
	//默认升序，可以用谓词改变默认排序，第三参数就是谓词（函数对象） 
	for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << *it << " ";
	}	
} 


int main()
{
    //test1();
    test2();
	return 0;
}

