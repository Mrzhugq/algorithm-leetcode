#include<iostream>
#include<set>
#include<utility>
#include<functional>
using namespace std;


//set容器（集合） -> 所有元素都会在插入时自动排序 ，set迭代器不允许随机访问 
//set/multiset属于关联式容器，底层结构是二叉树实现
//set/multiset唯一区别：
//            set不允许容器中有重复的元素
//            multiset允许容器中有重复的元素


//-------------------------------------------------------------------------------- 
//set构造与赋值
/*
构造：
set<T> st;           //默认构造 
set(const set &st);  //拷贝构造
赋值：
set& operator=(const set &st); //重载了= 
*/ 
void PrintSet(const set<int> &st)
{
	//和list一样迭代器只允许++ --，不允许 += -=，因为只有++ --重载了  
	for(set<int>::const_iterator it = st.begin(); it!=st.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
} 

void test1()
{
	set<int> st;
	//set插入数据只有insert，没有push 
	st.insert(10);
	st.insert(30);
	st.insert(20);
	st.insert(30);
	PrintSet(st);     //10，20，30 set自动排序，并把重复的去掉 
	
	set<int> st2(st); //拷贝构造
	PrintSet(st2);
	//赋值 
	set<int> st3;
	st3 = st;
	PrintSet(st3); 
}
 
 
 
 
//--------------------------------------------------------------------------------
//set的大小和交换
// size();       //元素数目  （set不允许指定大小） 
// empty();      //是否为空
// swap(st);     //交换两个集合容器 

void test2()
{
	set<int> st;
	st.insert(10);
	st.insert(30);
	st.insert(20);
	cout << st.empty() << endl;
	cout << st.size() << endl;
	
	set<int> st2;
	st2.insert(50);
	st2.insert(90);
	st2.insert(40);
	st.swap(st2);
	PrintSet(st);
	PrintSet(st2);
}



//--------------------------------------------------------------------------------
//set插入删除 函数原型
/*
insert(elem);                           //在容器中插入元素

iterator erase(const_iterator pos);     //删除pos迭代器所指元素，返回下一元素的迭代器
iterator erase(const_iterator start, const_iterator end);
//删除[start,end)区间的数据，返回下一元素迭代器
int erase(elem);                        //删除容器中值为elem的元素
clear();                                //清空 
*/ 

void test3()
{
	set<int> st;
	st.insert(30);
	st.insert(30);
	st.insert(10);
	st.insert(20);
	
	st.erase(st.begin()); //删除排序后的第一个 -> 10 
	PrintSet(st);
	
	st.erase(30);         //值为30都删除 
	PrintSet(st);	
	//清空
	st.erase(st.begin(),st.end());
	st.clear(); 
}



//--------------------------------------------------------------------------------
//set查找和统计
//iterator find(key);     //查找key是否存在，存在返回该元素的迭代器；不存在返回set.end();
//int count(key);         //统计key元素个数。对于set只能是0或1,对于multiset可能有其他值 

void test4()
{
	set<int> st;
	st.insert(30);
	st.insert(30);
	st.insert(10);
	st.insert(20);
	
	set<int>::iterator fit = st.find(10);
	if(fit != st.end())
	{
		cout << "找到了：" << *fit << endl; 
	}
	else
	{
		cout << "没找到！" << endl;
	}
	
	cout << "set中30出现的次数：" << st.count(30) << endl;	
}


//--------------------------------------------------------------------------------
//set和multiset区别：
//1.set不能插入重复数据，而multiset可以
//2.set插入数据的同时会返回插入结果，表示是否插入成功
//3.multiset不会检测数据，因此可以插入重复数据 

//set下 
//pair<iterator, bool> insert(elem);
//返回一个pair类，iterator是elem插入的位置，bool是否插入成功 
void test5()
{
	set<int> st1;
	pair< set<int>::iterator, bool > ret1 = st1.insert(30);
	//pari是将两个元素合成一组数据，或者当一个函数需要返回两个数据时。pari的实现是一个结构体 
	if(ret1.second == true) //ret1.second 就是pair类中的第二个 
	{
		//cout << *(ret1.first) << endl; 
		cout << "第一次插入30成功！" << endl;
	}
	else
	{
		cout << "第一次插入30失败！" << endl; 
	}
	
	pair< set<int>::iterator, bool > ret2 = st1.insert(30);
	if(ret2.second == true) 
	{
		cout << "第二次插入30成功！" << endl;
	}
	else
	{
		cout << "第二次插入30失败！" << endl; 
	}
	
	st1.insert(10);
	st1.insert(20);
}

//multiset下 
//iterator insert(elem);   //只返回插入的位置 
void test6()
{
    multiset<int> ms;
    ms.insert(20); 
	ms.insert(10);  
	ms.insert(10);  
 	for(multiset<int>::iterator it = ms.begin(); it!=ms.end(); it++)
	{
		cout << (*it) << endl; 
	}
	cout << "10的个数为：" << ms.count(10) << endl;
}




//--------------------------------------------------------------------------------
//pair队组创建 
//成对出现的数据，利用队组可以返回两个数据
//(是将两个元素合成一组数据，或者当一个函数需要返回两个数据时)

//pair<type,type> p(value1,value2);              //有参构造
//pair<type,type> p = make_pair(value1,value2);  //
//pair& operator=(const pair &p);                //赋值操作 

void test7()
{
	//1.
	pair<string,int> p("汤姆",28);
	cout << "姓名：" << p.first << " 年龄：" << p.second << endl; 
	//2.
	pair<string,int> p2 = make_pair("杰润",18);
	cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;  
}



//--------------------------------------------------------------------------------
//set容器排序 默认从小到大排序
//利用仿函数，可以改变排序顺序

class Mycompare1
{
public:
	bool operator()(int val1, int val2)//重载小括号，叫仿函数 
	{
		return val1 > val2;
	}
};

//排序内置数据 
void test8()
{
	//set<int,greater<int>> s1;
	set<int,Mycompare1> s1;
	//要想要降序，必须要在插入前告诉set容器排序规则
	 
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	for(set<int,greater<int>>::iterator it = s1.begin(); it!=s1.end(); it++)
	{
		cout << *it << endl;
	}	
}



class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
}; 

class Mycompare2
{
public:
    bool operator()(const Person &p1,const Person &p2)
	{
		return p1.m_age > p2.m_age; //按年龄降序 
	}	
}; 
//排序自定义数据类型 
void test9()
{
	//自定义数据类型，都应该指定排序规则，因为编译器也不知道怎么排 
	set<Person,Mycompare2> s1; 
	Person p1("saf",13); 
	Person p2("ofa",10); 
	Person p3("ugh",25); 
	Person p4("pAF",5);
	s1.insert(p1); 
	s1.insert(p2); 
	s1.insert(p3); 
	s1.insert(p4); 
	for(set<Person,Mycompare2>::iterator it = s1.begin(); it!=s1.end(); it++)
	{
		cout << "姓名：" << it->m_name << "  年龄：" << it->m_age << endl;
	}
}

//set可以重载< 或者 () 实现自定义数据的排序和去重
//重载<一般写在想要比较多自定义类型的里面（类内） 
//而重载()一般再另写一个类放入set的参数类型列表中（类外） 
//只要让想要比较的属性相等的时候返回false就行 
//set容器判断是否相等时，会调用两次比较函数，A<B false; B<A false; -> A和B相等 
 
//--------------------------------------------------------------------------------
int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6(); 
//    test7();
//    test8();
      test9();
	return 0;
}

