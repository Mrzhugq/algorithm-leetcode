#include<iostream>
#include<algorithm> 
#include<vector> 
#include<string>
#include<numeric> 
using namespace std;

//算术生成算法 需要头文件#include<numeric> 
//accumulate   计算容器中元素累计总和
//fill         向容器添加元素


//------------------------------------------------------------------------ 
//accumulate(iterator beg, iteator end, value);
//第三个参数表示从value开始累加 

//其实还有第四个参数，一个函数或者一个函数对象(类内重载了小括号)
 
void test1()
{
	vector<int> v;
	for(int i=0; i<=100; i++) //v总和为5050 
	{
		v.push_back(i);
	}
	int total = accumulate(v.begin(), v.end(), 0);
	cout << total << endl;
}




//------------------------------------------------------------------------ 
//fill(iterator beg, iterator end, value);
//把区间所有空间填充为value 

void test2()
{
	vector<int> v;
	v.resize(10); //10个0
	
	//后期重新填充 
	fill(v.begin(),v.end(),100); //10个100 
} 


int main()
{
    //test1();
    test2();
	return 0;
}

