#include<iostream>
#include<string>
using namespace std;

//继承是面向对象的三大特征之一

//有些类与类中间存在特殊关系，例如下图中： 
//               动物
//     猫                  狗
//加菲猫 布偶猫..    哈士奇 京巴 ... 

//我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特征
//这个时候我们就可以考虑利用继承的技术，减少重复代码 


//传统方法------------------------------------------------------------------ 
//Java页面 
//class Java
//{
//public:
//	//公共部分 
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;		
//	}
//	void left()
//	{
//		cout << "Java、Python、C/C++...（公共左部分类列表）" << endl;	
//    } 
//    //不同部分
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	} 
//}; 
//
////Python页面 
//class Python
//{
//public:
//	//公共部分 
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;		
//	}
//	void left()
//	{
//		cout << "Java、Python、C/C++...（公共左部分类列表）" << endl;	
//    } 
//    //不同部分
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	} 
//};
//
////C/C++页面 
//class CPP
//{
//public:
//	//公共部分 
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;		
//	}
//	void left()
//	{
//		cout << "Java、Python、C/C++...（公共左部分类列表）" << endl;	
//    } 
//    //不同部分
//	void content()
//	{
//		cout << "C/C++学科视频" << endl;
//	} 
//};



//继承方法------------------------------------------------------------------ 
//语法 class 子类 ： 继承方式 父类
//子类 就是 派生类
//父类 就是 基类
 
//公共页面类 
class BasePage
{
public:
    //公共部分 
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;		
	}
	void left()
	{
		cout << "Java、Python、C/C++...（公共左部分类列表）" << endl;	
    } 
}; 

//Java页面 
class Java : public BasePage 
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	} 
}; 

//Python页面 
class Python : public BasePage 
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	} 
};

//C/C++页面 
class CPP : public BasePage 
{
public:
	void content()
	{
		cout << "C/C++学科视频" << endl;
	} 
};
 
void test1()
{
	cout << "Java下载视频页面如下" << endl;
	Java J;
	J.header();
	J.footer();
	J.left();
	J.content(); 
	
	cout << "--------------------------------" << endl;
	cout << "Python下载视频页面如下" << endl;
	Python p;
	p.header();
	p.footer();
	p.left();
	p.content(); 
	
	cout << "--------------------------------" << endl;
	cout << "C/C++下载视频页面如下" << endl;
	CPP c;
	c.header();
	c.footer();
	c.left();
	c.content(); 
}


int main()
{
	test1();
	return 0;
}

