#include<iostream>
using namespace std;


//———————————————————————————————— 
//构造函数
//没有返回值，不用写void
//函数名与类名一样
//构造函数可以有参数，可以发生重载
//创建对象时，构造函数会 自动调用 ，而且只会调用一次


//析构函数
//没有返回值，不用写void
//函数名与类名一样，但要在名称前加一个 ~
//析构函数不可以参数，因此不能发生重载
//对象在销毁前会 自动调用 析构函数，而且只会调运一次

 
class Person1
{
public :
	
	//构造函数 
    Person1()
	{
		cout << "Person 构造函数的调用" << endl;
	}
	
	//析构函数
    ~Person1()
	{
		cout << "Person 析构函数的调用" << endl;
    } 
}; 

//构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构函数 
int main1()
{
	Person1 p;//局部变量，在栈上，执行完毕后，释放这个对象 
	return 0; 
} 



//——————————————————————————————————————— ———— 
//构造函数的分类以及调用
//两种分类方式
//    按参数分为：无参(默认构造)和有参构造
//    按类型分为：普通构造和拷贝构造
//三种调用方法
//    括号法，显示法，隐式转换法

class Person
{
public :
	
	int age;
	
	//构造函数  
	
	//普通构造 
    Person()//无参构造 
	{
		cout << "Person 构造函数的调用" << endl;
	}
    Person(int a)//有参构造 
	{
		age = a;
		cout << "Person(int a) 构造函数的调用" << endl;
	}
	//拷贝构造函数
	Person(const Person &p)
	{
		//将传入的人身上的所有属性，拷贝到我身上 
		age = p.age;
		cout << "Person 拷贝构造函数的调用" << endl;
    } 
    
    
//	//析构函数
//    ~Person()
//	{
//		cout << "Person 析构函数的调用" << endl;
//    } 
}; 
 
int main()
{
	//调用方式
	
	//1.括号法(喜欢用这种)                   注意1调用无参(默认)析构函数时候，后面不要加()  
    Person p1;      //无参构造函数调用   ->  如果写成Person p2();  ->  编译器就会看成一个函数的声明，不会认为在创建函数 
    Person p2(10);  //有参构造函数调用            
    Person p3(p2);  //拷贝构造函数调用
	
	cout << "p2的年龄为: " << p2.age << endl;	 
	cout << "p3的年龄为: " << p3.age << endl;	 
	
	
	//显示法
    Person c1;               //无参构造函数调用 
    Person c2 = Person(10);  //有参构造函数调用            
    Person c3 = Person(c2);  //拷贝构造函数调用
    
    Person(10);  //称匿名对象 特点： 当前行执行结束后，系统会立即回收掉匿名对象
                 //           注意2：不要用拷贝构造函数初始化一个匿名对象 ->
				 //如果这样写 Person(c3); 编译器认为 -> Person c3; c3上面已经定义了，这里会报错，重复定义 
    cout << "aaaaaa" <<endl; 
	 
	 
    //隐式转换法
    Person d1;      //无参构造函数调用 
    Person d2 = 10; //相当于写了 Person d1 = Person(10); 
    Person d3 = d2; //Person c3 = Person(c2); 
}


