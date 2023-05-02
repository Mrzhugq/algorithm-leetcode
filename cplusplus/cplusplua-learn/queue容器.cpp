#include<iostream>
#include<queue> 
using namespace std;

//队列 -> 先进先出(FIFO)，有两个口（一端只能进数据，一段只能出数据）
//队列允许从一段新增数据，一段移除数据
//队列中只有队头和队尾才可以被外界使用，因此队列也不允许有遍历行为
//入队push，出队pop 


//接口：
/*
构造函数： 
queue<T> que;            //默认构造
queue(const queue &que)  //拷贝构造
赋值操作：
queue& operator=(const queue &que); //重载
数据存储：
push(elem);              //往队尾添加数据
pop();                   //往队头移除第一个元素
back();                  //返回最后一个元素
front();                 //返回第一个数据 
大小操作：
empty();                 //判断队列是否为空
size();                  //返回队列大小 
*/ 


void test1()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	cout << "出队前大小：" << q.size() << endl; 
	while(!q.empty())
	{
		cout << "队头数据：" << q.front() <<endl;		
		cout << "队尾数据：" << q.back() <<endl;
		q.pop();
		cout << endl;		
	}
	cout << "出队后大小：" << q.size() << endl; 
}

int main()
{
    test1();
	return 0;
}

