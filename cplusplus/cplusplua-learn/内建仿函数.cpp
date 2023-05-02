#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional> 
using namespace std;

//内建函数对象(内建仿函数)
//算术仿函数，关系仿函数，逻辑仿函数

//这些仿函数所产生的对象，用法和一般函数完全相同
//使用内建仿函数，需要头文件#include<functional> 


//---------------------------------------------------------------------------------
//算术仿函数
//功能：实现四则运算，其中negate是一元运算，其他都是二元运算 
/*
template<class T> plus<T>        //加法 
template<class T> minus<T>       //加法 
template<class T> multiplies<T>  //乘法 
template<class T> divides<T>     //除法 
template<class T> modulus<T>     //取模 
template<class T> negate<T>      //取反 
*/

void test1()
{
	//取反 
	negate<int> n;
	cout << n(50) << endl; 
	//加法
	plus<int> p;
	cout << p(10,20) << endl; 
}


//---------------------------------------------------------------------------------
//关系仿函数
/*
template<class T>  bool equal_to<T>       //等于 
template<class T>  bool not_equal_to<T>   //不等于 
template<class T>  bool greater<T>        //大于 
template<class T>  bool greater_equal<T>  //大于等于 
template<class T>  bool less<T>           //小于 
template<class T>  bool less_equal<T>     //小于等于 
*/ 

void test2()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(5);
	sort(v.begin(),v.end(),less<int>());     //升序(第三个默认参数就是less<T>(),可以不写) 
	sort(v.begin(),v.end(),greater<int>());  //降序	 
}


//---------------------------------------------------------------------------------
//逻辑仿函数(基本用不到) 
/*
template<class T>   bool logical_and<T>   //逻辑与 
template<class T>   bool logical_or<T>    //逻辑或 
template<class T>   bool logical_not<T>   //逻辑非 
*/ 

void test3()
{
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	
	//利用逻辑非，将容器v1搬运到v2容器中，并进行取反操作
	vector<bool> v2;
	v2.resize(v1.size()); //需要先开辟好空间 
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>()); 
	//transform算法 前两个参数是要搬运容器的区间，第三个是搬运到容器的起始位置，
	//第四个参数是搬运过程中需要做的事 
}



int main()
{
	//test1(); 
	//test2(); 
	test3(); 
	return 0;
}

