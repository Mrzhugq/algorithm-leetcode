#include<iostream>
#include<string>
using namespace std; 
#define PI 3.14 

//���е����Ժ���Ϊ ���Ƕ�ͳһ��Ϊ��Ա
//����Ҳ��Ϊ   ��Ա���� ��Ա����
//��ΪҲ��Ϊ   ��Ա���� ��Ա���� 


//�������һ��Բ�࣬����ܳ� 
//class �������һ���� ����������������          
class Circle
{
	//����Ȩ��
	//����Ȩ��
public :
	
    //����
	//�뾶 
    int r;
	
    //��Ϊ
	//��ȡԲ���ܳ� -> һ���ú�����ʵ��
	double calculateZC()
	{
		return 2 * PI * r; 
    } 
	 
}; 


int main1()
{
	//ͨ��Բ�࣬����һ�������Բ (����)
	//ʵ���� -> ͨ��һ���࣬����һ������Ĺ��� 
	Circle c1;
	//��Բ���� �����Խ��и�ֵ
	c1.r = 10;
	
	cout << "Բ���ܳ�Ϊ��" << c1.calculateZC() << endl;
	return 0;
}






class Student
{
	//Ȩ�� 
public:
	//����
	string MyName;
	int ID;
	//��Ϊ
	void Show()
	{
		cout << "������" << MyName << endl;
		cout << "ѧ�ţ�" << ID << endl;
	}
	
	//�����Ը�����Ϊ�����Ը�ֵ
	void Getname(string name)
	{
		MyName = name;
    } 
};

int main() 
{
	Student s1;
	s1.MyName = "����";
	s1.ID = 123;
	s1.Show();
	
	Student s2;
	s2.Getname("����");
	s2.ID = 456;
	s2.Show(); 
	return 0;
}
