#include<iostream>
using namespace std;

//��̬����3--�������װ�� 

//����CPU��
class CPU
{
public:
	//���� 
	virtual void calculate() = 0;
}; 

//�����Կ���
class VideoCard
{
public:
	//��ʾ 
	virtual void display() = 0;
}; 

//�����ڴ�����
class Memory 
{
public:
	//�洢
	virtual void Storage() = 0;
}; 


class Computer
{
private: 
	CPU* m_cpu;      //CPU���ָ�� 
	VideoCard* m_vc; //�Կ����ָ�� 
	Memory* m_mem;   //�ڴ������ָ�� 
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_mem = mem;
		m_vc = vc; 
	}
	
	//�ṩ��������
	void dowork()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->Storage(); 
    } 
    //�����ͷ�������� 
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


//���峧�����
//Intel
class IntelCPU : public CPU
{
public:
	void calculate()
	{
		cout << "Intel��CPU��ʼ������" << endl; 
	}
};

class IntelVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "Intel���Կ���ʼ��ʾ��" << endl; 
	}
};
 
class IntelMemory : public Memory
{
public:
	void Storage()
	{
		cout << "Intel���ڴ�����ʼ�洢��" << endl; 
	}
};

//Lenovo 
class LenovoCPU : public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo��CPU��ʼ������" << endl; 
	}
};

class LenovoVideoCard : public VideoCard
{
public:
	void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ��" << endl; 
	}
};
 
class LenovoMemory : public Memory
{
public:
	void Storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢��" << endl; 
	}
};


//��װ���� 
int main()
{
	//1.��һ̨���� 
	CPU* cpu = new IntelCPU;
	VideoCard* vc = new IntelVideoCard;
	Memory* mem = new IntelMemory;
	
	Computer* c1 = new Computer(cpu,vc,mem);
	c1->dowork();
	delete c1;
	
	//�ڶ�̨���� 
	Computer* c2 = new Computer(new LenovoCPU,new LenovoVideoCard,new IntelMemory);
	c2->dowork();
	delete c2;
	return 0;
}

