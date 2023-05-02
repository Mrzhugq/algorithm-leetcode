#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

//deque容器
//功能：双端数组，可以对头端进行插入删除操作

//deque与vector区别：
//vector对于头部的插入删除效率低，数据量越大，效率越低
//deque相对而言，对头部的插入删除比vector快
//vector访问元素的速度会比deque快，这和两者的内部实现有关

//deque的迭代器也是支持随机访问的（空间连续）



//----------------------------------------------------------------------------------
//deque构造 函数原型
/*
deque<T> deq              //默认构造 
deque(beg, end);          //[begin,end)赋值给本身，参数为迭代器 
deque(n, elem);           //n个elem 
deque(const deque &deq);  //拷贝构造 
*/ 

//打印  ->  注意我这里写成了模板 
template<typename T>
void PeintDeque(const deque<T> &d)
{
	for(typename deque<T>::const_iterator it = d.begin(); it!=d.end(); it++)
	{
		//*it = 100; 不能修改，因为25，27行加const了 
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	//1. 
	deque<int> deq;
	for(int i=0; i<10; i++)
	{
		deq.push_back(i);
	}
	PeintDeque(deq);
	//2.
	deque<int> deq2(deq.begin(),deq.end());
    PeintDeque(deq2);
    //3.
    deque<int> deq3(10,3); //10个3
	//4.
	deque<int> deq4(deq3); //拷贝构造 
} 



//----------------------------------------------------------------------------------
//deque赋值操作 函数原型
/*
deque& operator=(const deque &deq); //重载 
deque& assign(beg, end);                  //[beg,end)，参数为迭代器 
deque& assign(n, elem);                   //n个elem 
*/

void test2()
{
	deque<int> deq1;
	for(int i=0; i<10; i++)
	{
		deq1.push_back(i);
	}
	//1.
	deque<int> deq2 = deq1;
    PeintDeque(deq2);
    //2.
    deque<int> deq3;
    deq3.assign(deq1.begin(),deq1.end());
    //3.
    deque<int> deq4;
    deq4.assign(10,5); //10个5 
}  



//----------------------------------------------------------------------------------
//deque容器大小操作 函数原型
/*
empty();                   //是否为空 
size();                    //大小 （注意这里和vector不一样没有了capacity） 
resize(int num);           //重新指定大小，长了填0，短了后边数据删除 
resize(int num,int elem);  //重新指定大小，长了填elem，短了后边数据删除
*/ 

void test3()
{
	deque<int> deq1;
	for(int i=0; i<10; i++)
	{
		deq1.push_back(i);
	}
	cout << deq1.empty() << endl;
	cout << deq1.size() << endl;
	
	deq1.resize(15);     //补0 
	PeintDeque(deq1);
//	deq1.resize(15,6);   //补6
//	PeintDeque(deq1);
	
	deq1.resize(5);    //末尾删除 
	PeintDeque(deq1);	
}



//----------------------------------------------------------------------------------
//deque插入和删除 函数原型
/*
两端插入操作：
push_back(elem);   //尾插 
push_front(elem);  //头插
pop_back();
pop_front();
指定位置操作：pos为迭代器 
iterator insert(const_iterator pos, elem); //pos位置插入elem，返回新数据(迭代器)的位置 
void insert(const_iterator pos, int count, elem); //pos位置插入n个elem
void insert(const_iterator pos, const_iterator start, const_iterator end);
//pos位置插入[start,end)区间的数据，无返回值

iterator erase(const_iterator pos);        //删除迭代器pos指向元素
iterator erase(const_iterator start, const_iterator end); 
//删除迭代器从start到end之间的元素[start,end)
claer();                         //清空 
*/ 

void test4()
{
	deque<int> d1;
	for(int i=0; i<5; i++)
	{
		d1.push_back(i); //尾插 
	} 
	for(int i=0; i<5; i++)
	{
		d1.push_front(i); //头插 
	}
	PeintDeque(d1);
	
	//2.
	d1.insert(d1.begin()+1, 10);  //第二个位置插入10 
	//3.
	d1.insert(d1.begin(),5, 10); //头插5个10 
	//4.
	deque<int> d2;
	d2.push_back(66);
	d2.push_back(77);
	d2.push_back(88);
	d1.insert(d1.begin(),d2.begin(),d2.end()); //头部插入d2 
	PeintDeque(d1); 
	//5.
    //d2.erase(d2.begin()+1);
    deque<int>::iterator it = d2.erase(d2.begin()+1); //删除第二个数 
    cout << "删除后：" << endl;
    PeintDeque(d1); 
    cout << "下一个数为：" << *it << endl; 
}



//----------------------------------------------------------------------------------
//deque数据存储  
/*
at(int Index);   //返回索引Index所指的数据 （会检查下标是否越界） 
operator[];      //返回索引Index所指的数据 （不会检查）
front();         //返回容器中第一个元素
back();          //返回容器中 最后一个元素 
*/ 
void test5()
{
	deque<int> d1;
	for(int i=0; i<5; i++)
	{
		d1.push_back(i); //尾插 
	} 
	cout << d1[0] << endl;	
	cout << d1.at(1) << endl;
	
	cout << d1.front() << endl;	
	cout << d1.back() << endl;	
}
 
 
 
//----------------------------------------------------------------------------------
//deque排序 (vector也有)
//对于支持随机访问的迭代器的容器都可以利用sort算法排序(默认升序)，头文件algorithm 
//sort(iterator beg, iterator end); //对[beg,end)区间元素进行排序 

void test6()
{
	deque<float> d1;
	d1.push_back(23.7);
	d1.push_back(20.6);
	d1.push_back(50.4);
	sort(d1.begin(),d1.end());
	PeintDeque(d1); 
}



 
int main()
{
//	test1(); 
//	test2(); 
//	test3(); 
	test4(); 
//	test5(); 
//	test6(); 
	return 0;
}

