#include<iostream>
#include<string> 
#include<vector> 
#include<algorithm> 
using namespace std;

//vector和数组非常相似，也称为单端数组 
//vector和普通数组的区别：数组是静态空间，而vector可以动态扩展
//动态扩展：并不是在原有空间之后接新空间，而是找更大的内存空间，然后把原数据拷贝新空间，释放原空间
//vector迭代器是支持随机访问的迭代器（空间连续） 



//----------------------------------------------------------------------------------
//vector的构造 函数原型
/*
vector<T> v;                   //采用模板实现类实现，默认构造函数 
vector( v.begin(), v.end() );  //将v中[begin(),end())区间中的元素拷贝给本身 
vector(n, elem);               //构造函数将n个elem拷贝给本身
vector(const vector &vec);     //拷贝构造函数 
*/

void Printvector(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	//1.
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	Printvector(v1);
	//2.
	vector<int> v2(v1.begin(),v1.end());
	Printvector(v2);
	//3.
	vector<int> v3(10,6); //10个都是6
	Printvector(v3); 
	//4.
	vector<int> v4(v1); //拷贝构造 
	Printvector(v4); 
}
 
 
//----------------------------------------------------------------------------------
//vector赋值操作 函数原型
/*
vector& operator=(const vector *vec);  //重载= 
assign(beg,end);                       //将[begin，end)区间中的数据拷贝赋值给本身  
assign(n,elem);                        //将n个elem拷贝赋值给本身 
*/ 

void test2()
{
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	//operator=
	vector<int> v2;
	v2 = v1;
	Printvector(v2);
	//2.
	vector<int> v3;
	v3.assign(v1.begin(),v1.end());
	Printvector(v3);
	//3.
	vector<int> v4;
	v4.assign(10,8); //10个8 
	Printvector(v4);	
}

 
 
//----------------------------------------------------------------------------------
//vector容量大小 函数原型 
/*
empty();                   //判断容器是否为空
capacity();                //容器的容量
size();                    //容器的元素的个数
resize(int num);           //重新指定容器的长度为num，若边长，则以默认值(0)填充新位置
                           //如果容器变短，则末尾超出容器长度的元素被删除
resize(int num, int elem); //重新指定容器的长度为num，若边长，则以elem值填充新位置 
                           //如果容器变短，则末尾超出容器长度的元素被删除 
*/ 
void test3()
{
    vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	cout << "是否为空：" << v1.empty() << endl;
	cout << "容器大小：" << v1.size() << endl; 
	cout << "容器容量：" << v1.capacity() << endl; 
	
	//调整大小
//	v1.resize(15);   //剩下的0填充 
//	Printvector(v1); 
	
	v1.resize(15,66); //剩下的用66填充
    Printvector(v1); 
    
    v1.resize(5);   //超出的删除 
    Printvector(v1); 
} 

//----------------------------------------------------------------------------------
//vector插入与删除 函数原型
/*
push_back(ele);   //尾插
pop_back();       //尾删
iterator insert(const_iterator pos, elem);  //迭代器指向位置pos插入元素ele,返回新数据位置 
void insert(const_iterator pos, int count, elem); //迭代器指向位置pos插入count个元素ele  
void insert(const_iterator pos, const_iterator start, const_iterator end);
//pos位置插入[start,end)区间的数据，无返回值

iterator erase(const_iterator pos);        //删除迭代器pos指向元素,返回下一个数据位置（迭代器） 
iterator erase(const_iterator start, const_iterator end); 
//删除迭代器从start到end之间的元素[start,end)，返回下一个数据位置（迭代器） 
clear();                          //清空容器中所有元素 
*/ 

void test4()
{
    vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	v1.pop_back();
	Printvector(v1); 
	
	//插入
	v1.insert(v1.begin(),100); //头插，第一个参数是迭代器 
	Printvector(v1);  
	
	v1.insert(v1.begin(),2,1000);
	Printvector(v1);  
	//删除
	//vector<int>::iterator it = v1.erase(v1.begin());      
	v1.erase(v1.begin());    //头删，参数也是迭代器
	Printvector(v1); 
	
	v1.erase(v1.begin()+1, v1.end()); //只留下了第一个数 
    Printvector(v1);
    //清空
	v1.clear();
	Printvector(v1); 
}
 

//----------------------------------------------------------------------------------
//vector容器数据的存取 
/*
at(int Index);   //返回索引Index所指的数据 （会检查下标是否越界） 
operator[];      //返回索引Index所指的数据 （不会检查）
front();         //返回容器中第一个元素
back();          //返回容器中 最后一个元素 
*/ 

void test5()
{
	vector<int> v1;
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	//访问 
	for(int i=0; i<v1.size(); i++)
	{
		//cout << v1[i] << " ";
		cout << v1.at(i) << " ";
	}
	cout << endl;
	
	cout << v1.front() << endl;	//0 
	cout << v1.front() << endl;	//0
	
	cout << v1.back() << endl; //9
	cout << v1.back() << endl; //9
} 



//----------------------------------------------------------------------------------
//vector容器互换容器
//swap(vec);  //将容器vec与本身的元素互换
 
void test6()
{
	//1.基本使用
	cout << "交换前：" << endl; 
	vector<int> v1; 
	for(int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
	Printvector(v1);
	vector<int> v2;
	for(int i=9; i>=0; i--)
	{
		v2.push_back(i);
	}
	Printvector(v2);
	
	cout << "交换后：" << endl;
	v1.swap(v2);
	Printvector(v1); 
	Printvector(v2); 
	
	//2.实际用途
	vector<int> v;
	for(int i=0; i<100000; i++)
	{
		v.push_back(i);
    }
	cout << "v的容量为：" << v.capacity() << endl; 
	cout << "v的大小为：" << v.size() << endl;
	
	v.resize(3);
	cout << "收缩前：" << endl;
	cout << "v的容量为：" << v.capacity() << endl; 
	cout << "v的大小为：" << v.size() << endl;
	
	vector<int> (v).swap(v);    
	//vector<int> (v);相当于利用拷贝构造函数初始化了一个匿名对象
	//此匿名对象的capacity就是原来v的size，然后互换两个对象，所以匿名对象指向原本大的capacity
	//而匿名对象会在改行结束后自动回收，所以大capacity就被回收了，而v指向了小capacity 
	cout << "收缩后：" << endl; 
	cout << "v的容量为：" << v.capacity() << endl; 
	cout << "v的大小为：" << v.size() << endl;
		 
}



//----------------------------------------------------------------------------------
//vector预留空间
//减少vector在动态扩展时的扩展次数 //注意是reserve(预定) 不是 reverse(颠倒) 
//函数原型  reserve(int len);      //容器预留len个 元素长度，预留位置不初始化，元素不可访问 

void test7()
{
	vector<int> v;
	int num = 0;// 记录开辟次数
	int*p = NULL;
	for(int i=0; i<100000; i++)
	{
		v.push_back(i);
		if(p != &v[0]) //记录空间移动了几次，就是开辟了几次 
		{
			p = &v[0];
			++num;
		}
	} 
	cout << num << endl; 
	
	//利用reserve预留空间
	//假设我们一开始就知道要添加100000个数据，就直接预留100000个，就不用每次不够重新开辟了 
	vector<int> v2;
	v2.reserve(100000); 
	int num2 = 0;// 记录开辟次数
	int* p2 = NULL;
	for(int i=0; i<100000; i++)
	{
		v2.push_back(i);
		if(p2 != &v[0]) //记录空间移动了几次，就是开辟了几次 
		{
			p2 = &v[0];
			++num2;
		}
	} 
	cout << num2 << endl; 
}





int main()
{
//	test1(); 
//	test2(); 
//	test3(); 
//	test4(); 
//	test5(); 
//	test6(); 
	test7(); 
	return 0;
}

