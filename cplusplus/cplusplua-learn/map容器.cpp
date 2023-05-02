#include<iostream>
#include<map> 
#include<string>
using namespace std;

//map/multimap容器： 
//map中所有元素都是pair
//pair第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
//所有元素都会根据元素的键值自动排序

//map/multimap属于关联式容器，底层实现结构是二叉树实现
//map/multimap迭代器也属于双向迭代器，不支持随机访问 

//优点：可以根据key值快速找到value值
//map和multimap区别：map不允许容器中有重复key元素(value可以重复)，multimap允许有重复key元素


//-------------------------------------------------------------------------------- 
//map构造与赋值
/*
构造：
map<T1,T2> mp;                //默认构造
map(const map &mp);           //拷贝构造
赋值：
map& operator=(const map &mp) //重载 
*/

//template<typename T1,typename T2>
//void PrintMap(const map<T1,T2> &mp)
//{
//	for(typename map<T1,T2>::const_iterator it = mp.begin(); it!=mp.end(); it++)
//	{
//		cout << "Key = " << (*it).first << " Value = " << it->second << endl; 
//	}
//}

void PrintMap(const map<int,int> &mp)
{
	for(typename map<int,int>::const_iterator it = mp.begin(); it!=mp.end(); it++)
	{
		cout << "Key = " << (*it).first << " Value = " << it->second << endl; 
	}
}

void test1()
{
	map<int,int> mp; 
	//map插入也只有insert,插入数据类型是队组 
	mp.insert(pair<int,int>(1,10));  //pair匿名对象放入map
	mp.insert(pair<int,int>(3,30));  //按key排序了 
	mp.insert(pair<int,int>(2,20));
	mp.insert(pair<int,int>(4,40));
    PrintMap(mp);
    
    map<int,int> mp2(mp);
    PrintMap(mp);
    
    map<int,int> mp3;
    mp3 = mp;
    PrintMap(mp3);
} 



//-------------------------------------------------------------------------------- 
//map容器的大小和交换
//size();               //大小 
//empty();              //是否为空 
//swap(mp);             //交换容器 

void test2()
{
	map<int,int> mp; 
	mp.insert(pair<int,int>(1,10));
	mp.insert(pair<int,int>(3,30));
	mp.insert(pair<int,int>(2,20));
	mp.insert(pair<int,int>(4,40));
    PrintMap(mp);
	cout << mp.empty() << endl;
	cout << mp.size() << endl;
	
	map<int,int> mp2; 
	mp2.insert(pair<int,int>(5,50));
	mp2.insert(pair<int,int>(6,60));	
	mp.swap(mp2);//交换 
}



//-------------------------------------------------------------------------------- 
//map的插入与删除
/*
insert(elem);     //elem是个队组
iterator erase(const_iterator pos);     //删除pos迭代器所指元素，返回下一元素的迭代器
iterator erase(const_iterator start, const_iterator end);
//删除[start,end)区间的数据，返回下一元素迭代器
int erase(key);                        //删除容器中值为key的元素
clear();                               //清空 
*/ 

void test3()
{
	map<int,int> mp; 
	//1.插入 
	mp.insert(pair<int,int>(1,10));
	mp.insert(pair<int,int>(3,30));
	//2.
	mp.insert(make_pair(4,40));
	//3.
	mp.insert(map<int,int>::value_type(5,50));
	//4.不建议插数用  ，（multimap不可以用[]做insert） 
	mp[6] = 60; //内部重载了[] 

	cout << mp[7] << endl; 
	//没有之前没有插入key为7的队组，但编译器自动创建了，value为0，mp里面多了一个队组(7,0) 
	//这个多数用key访问已有的队组里面的value，比如 cout << mp[1] << endl; 
	PrintMap(mp);
	//删除
	mp.erase(mp.begin());      //头删 
	int ret = mp.erase(4);               //删除key为3的队组	
	PrintMap(mp);
} 



//-------------------------------------------------------------------------------- 
//map查找和统计
//find(key);       //查找key是否存在，若存在，返回该建元素的迭代器，不存在返回mp.end();
//count(key);      //统计key的元素个数，对于map只能是0或1,对于multimap可能有其他值 


void test4()
{
	map<int,int> mp; 
	mp.insert(pair<int,int>(1,10));
	mp.insert(pair<int,int>(3,30));	
	map<int,int>::iterator it = mp.find(3);
    if(it != mp.end())
    {
    	cout << "找到了 value = " << (it->second) << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}
}



//-------------------------------------------------------------------------------- 
//map容器排序(自定义数据类型必须指明排序规则) 
//默认按key升序，可以利用仿函数改变排序规则 (和set几乎一样) 

class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

void test5()
{
	map<int,int,MyCompare> mp1;
	//或者 map<int,int,greater<int>> mp1;
	mp1.insert(pair<int,int>(1,10)); 
	mp1.insert(pair<int,int>(2,20)); 
	mp1.insert(make_pair(3,30));
	mp1.insert(make_pair(6,60));
	mp1.insert(make_pair(5,50));
    for(map<int,int,MyCompare>::iterator it = mp1.begin(); it!=mp1.end(); it++)
    {
        cout << "Key = " << (*it).first << " Value = " << it->second << endl; 	
	}
}




int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
    test5();
//    test6(); 
	return 0;
}

