#include<iostream>
#include<string>
using namespace std;

//ʵ��һ��ͨ�õ�������

//�����Զ�����������
class Person
{
public:
	string m_name;
	int m_age;
	Person() //д���вι���ͱ������Ͳ����ṩ�޲ι����ˣ���37��Ҫ�õ��޲ι��� 
	{
		
	}
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	} 
}; 

//ͨ������ 
template<class T>
class MyArrary
{
private:
	T* pAddress;     //ָ��ָ��������ٵ���ʵ���� 
	int m_capacity;
	int m_size;
public:
    MyArrary(int capacity) //�����ʼcapacity
	{
		m_capacity = capacity;
		m_size = 0;
		pAddress = new T[m_capacity];
		//cout << "MyArrary �вι��캯������" << endl; 
	} 
	
	//�������캯��-��ֹǳ����
	MyArrary(const MyArrary &arr)
	{
		m_capacity = arr.m_capacity;
		m_size = arr.m_size;
		//pAddress = arr.pAddress; //ǳ���� 
		
		//���
		pAddress = new T[arr.m_capacity];
		for(int i=0; i<arr.m_size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		} 	
		//cout << "MyArrary �������캯��" << endl;
	}
	
    //����= ��ֹǳ����
	MyArrary& operator=(const MyArrary &arr)
	{
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if(pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
			m_capacity = 0;
			m_size = 0;
		} 
		
		//���
		pAddress = new T[arr.m_capacity];
		m_capacity = arr.m_capacity;
		m_size = arr.m_size;
		for(int i=0; i<arr.m_size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
		//cout << "operator= �ĵ���" << endl;
		return *this;  //��ʽ��� 
	}
	
	//β�巨
	void PushBack(const T &val)
	{
		//ʵ���ж��ǲ�������
		if(m_capacity == m_size)
		{
			cout << "���ˣ�" << endl;
			return;
		} 
		pAddress[m_size++] = val;
    } 
	
	//βɾ
	void PopBack()
	{
		if(m_size == 0)
		{
			cout << "�Ѿ�Ϊ���ˣ�" << endl;
			return;
		}
		//�߼�ɾ�� 
		--m_size;
	}
	
	//����[] �����±귽ʽ����
	T& operator[](int Index)
	{
		if(Index < 0  && Index > m_size)
		{
			cout << "Խ���ˣ�" << endl;
		}
		else
		{
			return pAddress[Index];
		}
	} 
	
	//������������
	int GetCapacity()
	{
		return m_capacity;
	} 
	
	//���������С
	int GetSize()
	{
		return m_size;
	} 
	
	//���� 
	~MyArrary()
	{
		if(pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
			//cout << "MyArrary ���������ĵ���" << endl; 
		}
	}
}; 

template<class T>
ostream& operator<<(ostream &cout, MyArrary<T> &arr)
{
	for(int i=0; i<arr.GetSize(); i++)
	{
		cout << arr[i] << " ";  //[]�Ѿ������� 
	} 
	cout << endl;
	return cout;
}
 
//��ӡPerson��
void PrintPerson(MyArrary<Person> &arr)
{
	for(int i=0; i<arr.GetSize(); i++)
	{
		cout << "������" << arr[i].m_name << " "
		     << "����" << arr[i].m_age << endl; 
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
    	arr1.PushBack(i);     //β�� 
	}
	cout << arr1 << endl;
	
	MyArrary<int> arr2(arr1); //�������� 
	cout << arr2 << endl;
	
	arr1.PopBack();           //βɾ 
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
	Person p1("�����",99); 
	Person p2("��˽�",89); 
	Person p3("����",77); 
	Person p4("¶��",30);
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

