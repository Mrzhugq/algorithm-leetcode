#include<iostream>
using namespace std;

//案例：分别利用普通写法和多态计数，设计实现两个操作符进行运算的计算机类
//多态优点：
//  代码组织结构清晰
//  可读性强
//  利用前期后后期的扩展以及维护 


//--------------------------------------------------------------------------------------- 
//普通写法
class Calculator
{
public:
	int m_num1;
	int m_num2;
	int GetResult(string oper)
	{
		if(oper == "+")
		{
			return m_num1+m_num2;
		}
		else if(oper == "-")
		{
			return m_num1-m_num2;
		}
		else if(oper == "*")
		{
			return m_num1*m_num2;
		}
		//如果我们想要添加除法运算，我们必须修改源码。在真实开发者，我们提倡 开闭原则
		//开闭原则，即对扩展进行开发，对修改进行关闭 
	}
}; 


//--------------------------------------------------------------------------------------- 
//多态写法

//首先实现计算机抽象类 
class AbstractCalculator
{
public:
	int m_num1;
	int m_num2;
	virtual int Getresult() 
	{
		return 0;
	}
}; 

//加法计算机
class AddCalculator : public AbstractCalculator
{
public:
	int Getresult()
	{
		return m_num1 + m_num2;
	}
};

//减法计算机 
class SubCalculator : public AbstractCalculator
{
public:
	int Getresult()
	{
		return m_num1 - m_num2;
	}
};
 
//乘法计算机
class MulCalculator : public AbstractCalculator
{
public:
	int Getresult()
	{
		return m_num1 * m_num2;
	}
};



//多态写法测试 
void test2()
{
	//多态使用条件
	//父类指针或者引用指向子类对象
	
	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->Getresult() << endl;
	delete abc;
	
	//加法运算
    abc = new SubCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->Getresult() << endl;
	delete abc; 
}

//普通写法测试 
void test1()
{
	Calculator c;
	c.m_num1 = 10;
	c.m_num2 = 20;
	
	cout << c.m_num1 << "+" << c.m_num2 << "=" << c.GetResult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.GetResult("-") << endl;
}

int main()
{
	//test1(); 
	test2(); 
	return 0;
}

