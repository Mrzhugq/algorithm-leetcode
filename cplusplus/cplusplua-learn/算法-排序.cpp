#include<iostream>
#include<algorithm> 
#include<numeric>
#include<functional>
#include<vector> 
#include<string>
#include<ctime>
using namespace std;

//排序算法 
//sort            排序
//random_shuffle  洗牌，指定范围内的元素随机调整顺序
//merge           容器元素合并，并储存到另一个容器中
//reverse         反转指定范围的元素


//-------------------------------------------------------------------------- 
//sort(iterator beg, iterator end, _Pred) 
//第三个参数需要一个谓词，有默认值（ 返回类型为bool并且重载() ） 

void MyPrint(int val)
{
	cout << val << " "; 
}

void test1()
{
	vector<int> v;
	v.push_back(12);
	v.push_back(14);
	v.push_back(10);
	sort(v.begin(),v.end(),greater<int>()); //降序
	//排序自定义类型，类内重载< 或者类外重载() 
	for_each(v.begin(),v.end(),MyPrint);
}


//-------------------------------------------------------------------------- 
//random_shuffle(iterator beg, iterator end); //打乱

void test2()
{
	srand((unsigned int)time(NULL)); //时间戳 
	
	vector<int> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(),v.end());//伪随机，可以加种子实现真随机 
	for_each(v.begin(),v.end(),MyPrint);
}

 

//--------------------------------------------------------------------------------- 
//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//注意：两个容器必须是有序的 （归并排序） 
//dest 目标容器迭代器

void test3()
{
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	for(int i=0; i<10; i++)
	{
		v2.push_back(i+2);
	}
	vector<int> v3;
	v3.resize(v1.size()+v2.size()); //提前给目标容器分配好空间才能归并
	 
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	for_each(v3.begin(),v3.end(),MyPrint);
}



//-------------------------------------------------------------------------- 
//reverse(iterator beg, iterator end);  反转  

void test4()
{
	vector<int> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(i);
	}
	reverse(v.begin(),v.end()); //反转 
	for_each(v.begin(),v.end(),MyPrint);	
} 
 
 
 
 
int main()
{
	//test1(); 
	//test2(); 
	//test3(); 
	test4(); 
	return 0;
}

