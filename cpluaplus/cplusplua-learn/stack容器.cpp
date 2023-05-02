#include<iostream>
#include<string> 
#include<stack> 
using namespace std;


//栈 -> 先进后出(FILO),只有一个出口
//栈中只有顶端元素才可以被外界使用，因此栈不允许有遍历行为
//入栈push，出栈pop 

//接口：
/*
构造函数： 
stack<T> stk;            //默认构造 
stack(const stack &stk)  //拷贝构造
赋值操作：
stack& operator=(const stack &stk); //重载
数据存储：
push(elem);  //向栈顶添加数据
pop();       //从栈顶移除第一个元素
top();       //返回栈顶元素
大小操作：
empty();     //判断栈是否为空
size();      //返回栈的大小  
*/ 

void test1()
{
	stack<int> s1;
	s1.push(10);//入栈 
	s1.push(20);
	s1.push(30);
	s1.push(40);
	cout << "出栈前大小：" << s1.size() << endl; 
	while(!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();//出栈 
    } 
    cout << endl; 
	cout << "出栈后大小：" << s1.size() << endl; 
}
 
int main()
{
	test1(); 
	return 0;
}

