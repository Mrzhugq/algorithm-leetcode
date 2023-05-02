#include<iostream>
#include<algorithm> 
#include<numeric>
#include<functional>
#include<vector> 
using namespace std;

//算法 


//------------------------------------------------------------------------------------
//常见遍历算法
//Function for_each(iterator first, iterator last, Function fn);//第三参数是个函数或者仿函数 
//iterator transform(iterator beg1, iterator end1, iterator beg2, Function fn)
//第三参数是个函数或者仿函数,是在搬运过程中要执行的内容  

//普通函数
void Print01(int val)
{
	cout << val << " ";
} 
//仿函数
class Print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
}; 

void test1()
{
	vector<int> v;
	v.push_back(12);
	v.push_back(14);
	v.push_back(10);
	v.push_back(19);
	for_each(v.begin(),v.end(),Print01);     //放入函数名字就行 
	for_each(v.begin(),v.end(),Print02 ());  //利用仿函数需要放入匿名对象（函数对象） 
}



class Transform
{
public:
	int operator()(int val)
	{
		return val; //不需要操作v1中的值，就直接返回就行了 
	}
}; 

void test2()
{
	vector<int> v1;
	v1.push_back(12);
	v1.push_back(14);
	v1.push_back(10);
	v1.push_back(19);	
	//把v1数据搬到v2中 
	vector<int> v2;        //目标容器 
	v2.resize(v1.size()); //目标容器需要提前开辟空间 
	transform(v1.begin(),v1.end(),v2.begin(),Transform ());//利用仿函数需要放入匿名对象（函数对象） 
	for_each(v2.begin(),v2.end(),Print02 ());              //输出一下v2 
} 


int main()
{
    //test1();
    test2();
	return 0;
}

