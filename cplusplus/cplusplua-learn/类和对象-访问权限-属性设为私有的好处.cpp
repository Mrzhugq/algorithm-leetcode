#include<iostream>
#include<string>
using namespace std; 

//����Ȩ�� (��Ա���Ժͳ�Ա��������Ȩ��) 
//����Ȩ�� public    ��Ա ���ڿ��Է��� ����Ҳ���Է���
//����Ȩ�� protected ��Ա ���ڿ��Է��� ���ⲻ���Է���   ���ӿ��Է��ʸ����еı������� 
//˽��Ȩ�� private   ��Ա ���ڿ��Է��� ���ⲻ���Է���   ���Ӳ����Է��ʸ��׵�˽������ 

class Person
{
public :
	//����Ȩ��
	string Name;
protected :
	//����Ȩ��
	string Car;
private :
	//˽��Ȩ��
	int Password; //���п�����
	
public :
	void fun()
	{
		Name = "����";  //�����������ܷ��� 
		Car = "������";
		Password = 123456; 
	}
}; 

int main1()
{
	Person p1;
	
	p1.Name = "����";
	//p1.Car = "����";   //���� -> ����Ȩ�޵����ݣ���������ʲ���
	//p1.Password = 123; //���� -> ˽��Ȩ�޵����ݣ�������Ҳ���ʲ��� 
	p1.fun();
	return 0; 
} 



///////////////////////////////////////////////////////////////////////////
//class �� struct ������
//�����Ա�ʾһ����
//Ψһ������Ĭ�Ϸ���Ȩ�޲�ͬ
//struct Ĭ��Ȩ��Ϊ���� public
//class  Ĭ��Ȩ��Ϊ˽�� private

class C1
{
	int a;//Ĭ��private 
}; 

struct C2
{
	int b;//Ĭ��public 
}; 





/////////////////////////////////////////////////////////////////////////
//��Ա��������Ϊ˽��
//�ŵ� �������г�Աɫ��Ϊ˽�У������Լ����ƶ�дȨ��
//       ����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��

//�ŵ�1. 
class Person1
{
public :
	//�������� (д����)
	void SetName(string name)
	{
		MyName = name;
	}
	
	//��ȡ���� (������)
	string GetName()
	{
		return MyName;
    } 
    
    //��ȡ����  (������)
    int GetAge()
    {
    	age = 0;//��ʼ��һ�£�Ҫ�����ص������ֵ
		return age; 
	}
	
	//���ð���(д����)
	void SetLover(string love)
	{
		Lover = love;
    } 
    
private :
	string MyName;  //�ɶ���д 
	int age;      //ֻ�� 
	string Lover; //���� ֻд 
}; 

int main2()
{
	Person1 p;
	
	p.SetName("����");
	cout << "�����ǣ�" << p.GetName() << endl;
	
	//p.age = 100; //���� -> �Լ���Ƶ�ֻ�� 
	cout << "������: " << p.GetAge() << endl;
	
	p.SetLover("�Ȱ�"); 
	//cout << "��������Ϊ: " << p.Lover << endl;//���� -> �Լ���Ƶ�ֻд���ɶ� 
    return 0;
}




//�ŵ�2.����ֻ����Ϊ�ɶ���д -> д��ͬʱ���Լ���������Ч�� 
class Person2 
{
public :
	//�������� (д����)
	void SetName(string name)
	{
		MyName = name;
	}
	
	//��ȡ���� (������)
	string GetName()
	{
		return MyName;
    } 
    
    //��������(д����) -> �����Ч��(�������������0 ~ 150) 
    void SetAge(int A)
	{
		if(A<0 || A>150)
		{
			age = 0;
			cout << "������������" << endl;
			return;
		}
		age = A;
    } 
    
    //��ȡ����  (������)
    int GetAge()
    {
		return age; 
	}
	
	//���ð���(д����)
	void SetLover(string love)
	{
		Lover = love;
    } 
    
private :
	string MyName;  //�ɶ���д 
	int age;      //ֻ�� 
	string Lover; //���� ֻд 
}; 

int main()
{
	Person2 p;

	p.SetAge(1000); 
	cout << "������: " << p.GetAge() << endl;
	
	p.SetAge(80); 
	cout << "������: " << p.GetAge() << endl;

    return 0;
}






