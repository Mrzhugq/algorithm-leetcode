#include<iostream>
using namespace std;

//多态案例3--计算机组装类 

//抽象CPU类
class CPU
{
public:
	//计算 
	virtual void calculate() = 0;
}; 

//抽象显卡类
class VideoCard
{
public:
	//显示 
	virtual void display() = 0;
}; 

//抽象内存条类
class Memory 
{
public:
	//存储
	virtual void Storage() = 0;
}; 


class Computer
{
private: 
	CPU* m_cpu;      //CPU零件指针 
	VideoCard* m_vc; //显卡零件指针 
	Memory* m_mem;   //内存条零件指针 
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_mem = mem;
		m_vc = vc; 
	}
	
	//提供工作函数
	void dowork()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->Storage(); 
    } 
    //用来释放三个零件 
    ~Computer()
	{
		if(m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if(m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if(m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
    } 
}; 


//具体厂商零件
//Intel
class IntelCPU : public CPU
{
public:
	void calculate()
	{
		cout << "Intel的CPU开始计算了" << endl; 
	}
};

class IntelVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "Intel的显卡开始显示了" << endl; 
	}
};
 
class IntelMemory : public Memory
{
public:
	void Storage()
	{
		cout << "Intel的内存条开始存储了" << endl; 
	}
};

//Lenovo 
class LenovoCPU : public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo的CPU开始计算了" << endl; 
	}
};

class LenovoVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "Lenovo的显卡开始显示了" << endl; 
	}
};
 
class LenovoMemory : public Memory
{
public:
	void Storage()
	{
		cout << "Lenovo的内存条开始存储了" << endl; 
	}
};


//组装电脑 
int main()
{
	//1.第一台电脑 
	CPU* cpu = new IntelCPU;
	VideoCard* vc = new IntelVideoCard;
	Memory* mem = new IntelMemory;
	
	Computer* c1 = new Computer(cpu,vc,mem);
	c1->dowork();
	delete c1;
	
	//第二台电脑 
	Computer* c2 = new Computer(new LenovoCPU,new LenovoVideoCard,new IntelMemory);
	c2->dowork();
	delete c2;
	return 0;
}

