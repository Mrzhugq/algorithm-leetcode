#include<iostream>
using namespace std;

//菱形继承
 
//         动物
//    羊类       驼类
//       羊驼类（草泥马） 

//概念：两个派生类继承同一个基类
//      又有某个类同时继承这两个派生类
//      这种继承称为菱形继承，或者砖石继承

//菱形继承问题：
//1.同多继承问题
//2.当我们继承这两个派生类时 -> 可能我们清楚我们继承这两个类中的数据，有些我们只需要一份就可以了 


//动物类 
class Animal
{
public:
    int m_age;	
}; 

//虚继承 -> 在继承方式前面加上virtual 
//Animal类称为 虚基类 
//羊类 
class Sheep : virtual  public Animal
{
    	
}; 

//虚继承 -> 在继承方式前面加上virtual  
//驼类 
class Tuo : virtual public Animal
{

}; 

//驼类 
class SheepTuo : public Sheep , public Tuo
{
    	
}; 

int main()
{
	SheepTuo st;
	st.Sheep::m_age = 18;
	st.Tuo::m_age = 28;
	
	//解决问题一  -> 加作用域 
	cout << "st.Sheep::m_age = " << st.Sheep::m_age << endl; //没虚继承前是18 
	cout << "st.Tuo::m_age = " << st.Tuo::m_age << endl;     //没虚继承前是28
	
	//问题二：现在羊驼多少岁？ -> 有两个年龄，资源浪费，其实只要一份就行了
	//解决：利用虚继承 解决菱形继承的问题二
	cout << "m_age = " << st.m_age << endl;//虚继承m_age就变成了一个 28 
	return 0;
}

