#include<iostream>
#include<string>
using namespace std;

//实现一个通用的数组类

//测试自定义数据类型
class Person
{
public:
	string m_name;
	int m_age;
	Person() //写了有参构造就编译器就不会提供无参构造了，而37行要用到无参构造 
	{
		
	}
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	} 
}; 

//通用数组 
template<class T>
class MyArrary
{
private:
	T* pAddress;     //指针指向堆区开辟的真实数组 
	int m_capacity;
	int m_size;
public:
    MyArrary(int capacity) //传入初始capacity
	{
		m_capacity = capacity;
		m_size = 0;
		pAddress = new T[m_capacity];
		//cout << "MyArrary 有参构造函数调用" << endl; 
	} 
	
	//拷贝构造函数-防止浅拷贝
	MyArrary(const MyArrary &arr)
	{
		m_capacity = arr.m_capacity;
		m_size = arr.m_size;
		//pAddress = arr.pAddress; //浅拷贝 
		
		//深拷贝
		pAddress = new T[arr.m_capacity];
		for(int i=0; i<arr.m_size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		} 	
		//cout << "MyArrary 拷贝构造函数" << endl;
	}
	
    //重载= 防止浅拷贝
	MyArrary& operator=(const MyArrary &arr)
	{
		//先判断原来堆区是否有数据，如果有先释放
		if(pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
			m_capacity = 0;
			m_size = 0;
		} 
		
		//深拷贝
		pAddress = new T[arr.m_capacity];
		m_capacity = arr.m_capacity;
		m_size = arr.m_size;
		for(int i=0; i<arr.m_size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
		//cout << "operator= 的调用" << endl;
		return *this;  //链式编程 
	}
	
	//尾插法
	void PushBack(const T &val)
	{
		//实现判断是不是满了
		if(m_capacity == m_size)
		{
			cout << "满了！" << endl;
			return;
		} 
		pAddress[m_size++] = val;
    } 
	
	//尾删
	void PopBack()
	{
		if(m_size == 0)
		{
			cout << "已经为空了！" << endl;
			return;
		}
		//逻辑删除 
		--m_size;
	}
	
	//重载[] 可以下标方式访问
	T& operator[](int Index)
	{
		if(Index < 0  && Index > m_size)
		{
			cout << "越界了！" << endl;
		}
		else
		{
			return pAddress[Index];
		}
	} 
	
	//返回数组容量
	int GetCapacity()
	{
		return m_capacity;
	} 
	
	//返回数组大小
	int GetSize()
	{
		return m_size;
	} 
	
	//析构 
	~MyArrary()
	{
		if(pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
			//cout << "MyArrary 析构函数的调用" << endl; 
		}
	}
}; 

template<class T>
ostream& operator<<(ostream &cout, MyArrary<T> &arr)
{
	for(int i=0; i<arr.GetSize(); i++)
	{
		cout << arr[i] << " ";  //[]已经重载了 
	} 
	cout << endl;
	return cout;
}
 
//打印Person类
void PrintPerson(MyArrary<Person> &arr)
{
	for(int i=0; i<arr.GetSize(); i++)
	{
		cout << "姓名：" << arr[i].m_name << " "
		     << "年龄" << arr[i].m_age << endl; 
	}
} 
 
 
 
 
void test1()
{
	MyArrary<int> arr1(10);
//	MyArrary<int> arr2(arr1);
//	MyArrary<int> arr3(20);
//	arr3 = arr2;
    
    for(int i=0; i<10; i++)
    {
    	arr1.PushBack(i);     //尾插 
	}
	cout << arr1 << endl;
	
	MyArrary<int> arr2(arr1); //拷贝构造 
	cout << arr2 << endl;
	
	arr1.PopBack();           //尾删 
	arr1.PopBack();
	cout << arr1 << endl;
}

void test2()
{
	MyArrary<double> arr0(5);
	arr0.PushBack(1.2);
	arr0.PushBack(3.5);
	arr0.PushBack(6.6);
	arr0.PushBack(0.9);
	arr0.PushBack(1.99);
	
	cout << arr0 << endl;; 
}

void test3()
{
	MyArrary<Person> arr(5);
	Person p1("孙悟空",99); 
	Person p2("猪八戒",89); 
	Person p3("韩信",77); 
	Person p4("露娜",30);
	arr.PushBack(p1); 
	arr.PushBack(p2); 
	arr.PushBack(p3); 
	arr.PushBack(p4);
	
    PrintPerson(arr);
}
 
int main()
{
	//test1(); 
	//test2();  
	test3();  
	return 0;
}

