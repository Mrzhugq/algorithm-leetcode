#include<iostream>
#include<string>
using namespace std;

//有些私有属性，也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
//友元的目的就是让一个函数或者类 访问另一个类中的私有成员

//友元的三种实现
//全局函数做友元
//类做友元
//成员函数做友元

//------------------------------------------------------------------------------ 
//1.全局函数做友元
class Building
{
	//18行这几代码只需要写道类内就行了，也不需要写到public下 
	//加上friend说明GoodGay是Building的好朋友，可以访问类内的私有成员 
	friend void GoodGay(Building &b);
public:
    string m_sittingRoom;//客厅 
private:
    string m_BedRoom;//卧室 
public:
	Building()
	{
		m_sittingRoom = "客厅";
        m_BedRoom = "卧室";
    } 
 
}; 

void GoodGay(Building &b)
{
    cout << "好朋友全局函数 正在访问：" << b.m_sittingRoom << endl; 
	//如果不加18行，m_BadRoom类外是访问不到的	
    cout << "好朋友全局函数 正在访问：" << b.m_BedRoom << endl; 	
}

int main()
{
	Building b;
	GoodGay(b);
} 


//------------------------------------------------------------------------------ 
//2.类做友元
class Building1
{
	//goodgay类是好朋友，就可以访问该类中的私有成员了 
	friend class goodgay;
public:
    string m_sittingRoom;//客厅 
private:
    string m_BedRoom;//卧室 
    
public:
	Building1()
	{
		m_sittingRoom = "客厅";
        m_BedRoom = "卧室";
    } 
 
};

class goodgay
{
public:
    Building1* building;	
		
	goodgay()
	{
		building = new Building1;
	}
	void visit()//访问Building1中的属性 
	{
		cout << "好朋友类正在访问：" << building->m_sittingRoom << endl;
		//因为有52行，所以类外可以访问另一个类中的私有成员 
		cout << "好朋友类正在访问：" << building->m_BedRoom << endl;
	}
}; 

int main1()
{
	goodgay g;
	g.visit();
}


//------------------------------------------------------------------------------ 
//3.成员函数做友元

class Building2;//声明 
//这里注意一下这两个类的定义位置 
class goodgay2
{
public:
    Building2* building;
		
	goodgay2();
	void visit1();
	void visit2();
};

class Building2
{
	//goodgay2类下的visit1成员函数是好朋友，可以访问本类的私有属性 
	friend void goodgay2::visit1();
public:
    string m_sittingRoom;//客厅 
private:
    string m_BedRoom;//卧室 
    
public:
	Building2();
};

//成员函数类外实现 
Building2::Building2()
{
	m_sittingRoom = "客厅";
    m_BedRoom = "卧室";
}
 
goodgay2::goodgay2()
{
	building = new Building2;
}

void goodgay2::visit1()//可以访问Building2中的私有成员 
{
    cout << "visit1 正在访问：" << building->m_sittingRoom << endl;
    //p109行作用 
    cout << "visit1 正在访问：" << building->m_BedRoom << endl;
}

void goodgay2::visit2()//不可以访问Building2中的私有成员  
{
	cout << "visit2 正在访问：" << building->m_sittingRoom << endl;
    //没有加friend visit2是不能访问私有属性的 
	//cout << "visit2 正在访问：" << building->m_BedRoom << endl;
}


int main2()
{
	goodgay2 g2;
	g2.visit1();
	g2.visit2(); 
}
