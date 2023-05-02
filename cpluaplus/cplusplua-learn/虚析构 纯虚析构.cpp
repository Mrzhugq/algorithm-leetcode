#include<iostream>
#include<string>
using namespace std;

//��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
//�����ʽ���������е�����������Ϊ������ ���� ��������

//������ �����������ԣ�
//    �����Խ������ָ���ͷ��������
//    ����Ҫ�о����ʵ��
//������ ������������
//    ����Ǵ����������������ڳ����࣬�޷�ʵ�������� 

//�����﷨
//virtual ~����() {}
//���鹹�﷨
//virtual ~����() = 0;
//��������~����() {} 


class Animal
{
public:
	Animal()
	{
		cout << "Animal �Ĺ��캯������" << endl;
	}
	//1. ���鹹 
	//�ڸ�����������ǰ����Virtual��Ϊ���������ɽ������ָ���ͷ�������󲻸ɾ������� 
//	virtual ~Animal()
//	{
//		cout << "Animal ��������������" << endl;
//	} 
	//2. �����鹹 -> ��Ҫ�о����ʵ�� 
	virtual ~Animal() = 0; 
	
	virtual void speak() = 0;
}; 

//2. ���˴����鹹 �����Ҳ���ڳ������� 
Animal::~Animal()
{
	cout << "Animal �Ĵ���������������" << endl;
} 


class Cat : public Animal
{
public:
	string* m_name;
	
	Cat(string name)//���캯�� 
	{
		m_name = new string(name);//���ڶ��� 
		cout << "Cat ���캯������" << endl; 
    } 
    ~Cat()//�������� 
	{
		if(m_name != NULL)
		{
			delete m_name;
			m_name = NULL;
			cout << "Cat ������������" << endl; 
		}
	} 
	
	void speak()
	{
		cout << (*m_name) << "Сè��˵��" << endl;
	}
};


int main()
{
	Animal* a = new Cat("��ķ");
	a->speak();
	//����ָ�����ͷ�ʱ��������������е���������(����һЩ�����ͷ�)��������������ж������ԣ�������ڴ�й© 
	delete a;
	 
	return 0;
}

