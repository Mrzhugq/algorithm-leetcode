#include<iostream>
#include<algorithm> 
#include<functional>
#include<vector> 
#include<string>
using namespace std;


//常用拷贝替换算法
//copy        容器指定范围元素拷贝到另一容器中
//replace     将容器中指定范围的旧元素修改为新元素
//replace_if  将容器中指定范围内满足条件的元素修改为新元素 
//swap        互换两个容器的元素

//replace_copy(iterator beg, iterator end, iterator dest, oldvalue, newvalue);
//区间内等于旧值的数据拷贝到新的容器中 

//--------------------------------------------------------------------------  
//copy(iterator beg, iterator end, iterator dest); 实际用的不多，可直接用=赋值 
//dest目标容器迭代器 

void MyPrint(int val)
{
	cout << val << " "; 
}

void test1()
{
	vector<int> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(i);
	}
	vector<int> v2;
	v2.resize(v.size()); //也需要提前开辟空间
	copy(v.begin(),v.end(),v2.begin());
    for_each(v2.begin(),v2.end(),MyPrint);
} 


//-------------------------------------------------------------------------- 
//replace(iterator beg, iterator end, oldvalue, newvalue); 

void test2()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	replace(v.begin(),v.end(),10,1000); //将区间内10替换为1000
	for_each(v.begin(),v.end(),MyPrint); 
	v.push_back(10);
}



//--------------------------------------------------------------------------
//replace_if(iterator beg, iterator end, _Pred, newvalue);
//_Pred谓词（ 返回类型是bool并且重载() ） 
class greater200
{
public:
	bool operator()(int val)
	{
		return val > 200;
	}
}; 

void test3()
{
	vector<int> v;
	v.push_back(233);
	v.push_back(110);
	v.push_back(220);
	v.push_back(310);
	replace_if(v.begin(),v.end(),greater200(), 999); //大于200替换为999
	for_each(v.begin(),v.end(),MyPrint);	
}



//-------------------------------------------------------------------------- 
//swap(container c1, container c2);
//两个容器必须为同种容器 
void test4()
{
	vector<int> v1;
	vector<int> v2;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+10);
	}	
	swap(v1, v2);
	for_each(v1.begin(),v1.end(),MyPrint); 
	cout << endl;
	for_each(v2.begin(),v2.end(),MyPrint); 
} 
 
 
int main()
{
    //test1();
    //test2();
    //test3();
    test4();
	return 0;
}

