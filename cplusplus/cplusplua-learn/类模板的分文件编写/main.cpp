#include <iostream>
#include<string> 
using namespace std;

//类模板分文件编写
//问题：类模板中的成员函数创建时机是在调用阶段，导致分文件编写时链接不到

//解决:
//1.直接包含.cpp源文件
//2.将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制

//#include"Person.cpp"
//1. #include"Person.h"  ->  #include"Person.cpp"   (用到少) 

//2.
#include"Person.hpp"    //主流 

int main() 
{
	Person<string,int> p1("jack",18);
	p1.Print();
	return 0;
}
