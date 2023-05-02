#include<iostream>
#include<algorithm> 
#include<functional>
#include<vector> 
#include<string>
using namespace std;

//常见的集合算法
//set_intersection 求两个容器的交集
//set_union        求两个容器的并集
//set_difference   求两个容器的差集

//---------------------------------------------------------------------------------
//iterator set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

//iterator set_intersection //（如果是自定义数据类型需要_Pred函数指针或函数对象(谓词) ）
//(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest, _Pred);

//返回交集的最后位置迭代器 
//两个容器(前提必须有序)的交集放到目标容器中，dest为目标容器的迭代器 
void Print(int val)
{
	cout << val << " ";
}
 
void test1()
{
    vector<int> v1;
	vector<int> v2;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}	
	vector<int> vTarget; //需要提前开辟空间
	//最坏情况是一个容器被另一个容器包含，所以要开辟两个容器里面小的size大小
	int size = min(v1.size(), v2.size()); 
	vTarget.resize(size);//开辟了10个空间（5，6，7，8，9，0，0，0，0，0） 
	
	vector<int>::iterator itEnd = 
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//返回的其实是9后面的位置 
	for_each(vTarget.begin(), itEnd, Print);
	//for_each(vTarget.begin(), vTarget.end(), Print); //这样会把后面的值打印出来 
}


//---------------------------------------------------------------------------------
//iterator set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//两个容器前提是有序（返回值和交集一样） 
//自定义数据类型和set_intersection一样，需要第五个参数 
void test2()
{
    vector<int> v1;
	vector<int> v2;
	for(int i=0; i<5; i++)
	{
		v1.push_back(i);   //(0,1,2,3,4)
		v2.push_back(i+2); //(2,3,4,5,6)
	}
	vector<int> vTarget; //也需要提前开辟空间
	int size = v1.size() + v2.size(); //最特殊时候 
	vTarget.resize(size);  //(1,2,3,4,5,6,0,0,0,0)
	
	vector<int>::iterator itEnd = 
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//返回值是交集的最后的下一个元素位置，即6后面的位置 
	for_each(vTarget.begin(), itEnd, Print);	
}


//---------------------------------------------------------------------------------
//iterator set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//两个容器前提是有序（返回值和交集一样） 
//自定义数据类型和set_intersection一样，需要第五个参数 


void test3()
{
    vector<int> v1;
	vector<int> v2;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);   //(0,1,2,3,4,5,6,7,8,9)
		v2.push_back(i+5); //(5,6,7,8,9,10,11,12,13,14)
	}	
	//v1与v2的差集 = v1 - (v1 ∩v2)  ->  1,2,3,4  
	//v2与v1的差集 = v2 - (v1 ∩v2)  ->  10,11,12,13,14
	vector<int> vTarget;
	int size =  max(v1.size(), v2.size()); //最坏它们两个容器没有交集
	vTarget.resize(size);
	
	//v1与v2差集 
	vector<int>::iterator itEnd = 
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, Print);
    cout << endl <<  "----------------" << endl; 
    //v2与v1差集
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());  
	for_each(vTarget.begin(), itEnd, Print);
}




int main()
{
	//test1(); 
	//test2(); 
	test3(); 
	return 0;
}

