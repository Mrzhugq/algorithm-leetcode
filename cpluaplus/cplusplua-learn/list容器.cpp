#include<iostream>
#include<list> 
#include<algorithm>
#include<functional> 
using namespace std;

//list容器 -> 链表，物理空间非连续
//单向链表结点组成：一个是存储数据单元的数据域，另一个是存储下一个结点地址的指针

//STL中的链表是一个 双向循环链表
//由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器 
//list优点：采取动态分配，不会造成内存浪费和溢出
//          插入删除十分方便，不需要移动大量元素
//list缺点：虽然灵活，但是空间(指针域)，和遍历时间额外耗资较大
//list有一个重要的性质，插入删除操作都不会造成原有list迭代器的失效，这在vector是不成立的


//--------------------------------------------------------------------------------
//list构造函数
/*
list<T> ist;                  //默认构造
list(lst.begin(), lst.end()); //将lst中[begin,end)区间赋值给本身
list(int n, elem)             //n个elem拷贝给本身
list(const list &lst);        //拷贝构造 
*/ 

void PrintList(const list<int> &l)
{
	for(list<int>::const_iterator it = l.begin(); it!=l.end(); it++)
	{
		cout << (*it) << " "; 
	}
	cout << endl;
} 

void test1()
{
	list<int> l1;   //默认构造 
	//添加数据
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_back(40); 
	PrintList(l1);
	//2.
	list<int>::iterator it = l1.begin();
	//it += i;                  //错误 
	it++;                       //正确，因为++和--都被重载了，而+=和-=没有被重载 
	list<int> l2(it, l1.end()); //除了l1的第一个数据，其他都复制给l2 
	PrintList(l2);
	//3.
	list<int> l3(l1);
	PrintList(l3); 
	//4. 
	list<int> l4(5,10); //5个10  
} 



//--------------------------------------------------------------------------------
//list赋值和交换 函数原型
/*
list& operator=(const list &lst);  //重载
assign(beg, end);                  //将[beg,end)区间数据拷贝给本身，参数为迭代器
assign(n, elem);                   //n个elem
swap(lst);                         //将lst与本身元素互换    
*/  

void test2()
{
	list<int> l1;
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_back(40); 
	//1.
	list<int> l2;
	l2 = l1;
	PrintList(l2); 
	//2.
	list<int> l3;
	l3.assign(l1.begin(),l1.end());
	PrintList(l3);
	//3.
	list<int> l4;
	l4.assign(5,10); //5个10;
	PrintList(l4);
	//4.
	l4.swap(l1);
	PrintList(l1);
	PrintList(l4);	
}


//--------------------------------------------------------------------------------
//list大小操作 函数原型
/*
empty();                //是否为空 
size();                 //大小  (没有容量capacity可说） 
resize(int num);        //重新指定大小，变长补零，变短末尾超出的删除
resize(int num, elem)   //重新指定大小，变长elem，变短末尾超出的删除
*/ 

void test3()
{
    list<int> l1;
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_back(40);
	
	cout << l1.empty() << endl; 
	cout << l1.size() << endl; 
	
	l1.resize(10);
	PrintList(l1);
	
	l1.resize(20,66);
	PrintList(l1); 
}



//--------------------------------------------------------------------------------
//list插入和删除 函数原型
/*

push_back(elem);    //尾插
pop_back();         //尾删 
push_front(elem);   //头插
pop_front();        //头删

iterator insert(const_iterator pos, elem);  //迭代器指向位置pos插入元素ele,返回新数据位置 
void insert(const_iterator pos, int count, elem); //迭代器指向位置pos插入count个元素ele  
void insert(const_iterator pos, const_iterator start, const_iterator end);
//pos位置插入[start,end)区间的数据，无返回值

iterator erase(const_iterator pos);        //删除迭代器pos指向元素,返回下一个数据位置（迭代器） 
iterator erase(const_iterator start, const_iterator end); 
//删除迭代器从start到end之间的元素[start,end)，返回下一个数据位置（迭代器） 
remove(elem);       //删除容器中所有与elem值匹配的元素 
clear();            //清空 
*/ 


void test4()
{
    list<int> l1;
	l1.push_back(10); //尾插 
	l1.push_back(20); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_front(5); //头插 
	l1.push_front(6);
	l1.push_front(7);
	PrintList(l1);
	
	list<int>::iterator it = l1.begin();
	it++;
	l1.insert(it,1000); 
	PrintList(l1);
	
	it = l1.begin();
	l1.erase(it);
	PrintList(l1);
	
	l1.remove(20); //把是20的值都删除 
	PrintList(l1);
}
 

//--------------------------------------------------------------------------------
//list数据存取 （ 不支持operator[],lst.at(i) ） 
//front();  //返回第一个元素
//back();   //返回最后一个数据


void test5()
{
    list<int> l1;
	l1.push_back(10); 
	l1.push_back(20); 
	l1.push_back(30); 
	l1.push_back(40); 
	cout << "头数据：" << l1.front() << endl;
	cout << "尾数据：" << l1.back() << endl;
	
	//迭代器不支持随机访问
	list<int>::iterator it = l1.begin();
	//it += 3;      //错误，没有重载
	it++;           //正确，STL重载了，只能一次一次加 
	it--;           //正确，所以迭代器是双向迭代器 
}


//--------------------------------------------------------------------------------
//list反转和排序
//reverse();          //反转链表，注意区分reverse和reserve(vector的预留空间) 
//sort();             //链表排序 

bool myCompare(int a,int b) //自己写比较函数，实现降序 
{
	return a > b; 
} 

void test6()
{
	list<int> l1;
	l1.push_back(23); 
	l1.push_back(45); 
	l1.push_back(10); 
	l1.push_back(9);
	cout << "反转前：" << endl; 
	PrintList(l1); 
	cout << "反转后：" << endl; 
	l1.reverse();
	PrintList(l1);
	
	//sort(l1.begin(),l1.end()); //错误，因为只有迭代器支持随机访问，才能用标准算法
	//上面这个标准算法排序是个全局函数
	//所以不支持随机访问的迭代器的容器，内部会提供一些对应的算法(成员函数) 
	l1.sort();     //默认升序 
	cout << "排序后(升序)：" << endl; 
	PrintList(l1);
	
	//l1.sort(greater<int>());
	l1.sort(myCompare);  //或者l1.sort(greater<int>()); 头文件#include<functional>  
	cout << "排序后(降序)：" << endl; 
	PrintList(l1);
}
 
int main()
{
	//test1(); 
	//test2(); 
	//test3(); 
	//test4(); 
	//test5(); 
	test6(); 
	return 0;
}
