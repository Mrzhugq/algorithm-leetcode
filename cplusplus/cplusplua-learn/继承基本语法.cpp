#include<iostream>
#include<string>
using namespace std;

//�̳�������������������֮һ

//��Щ�������м���������ϵ��������ͼ�У� 
//               ����
//     è                  ��
//�ӷ�è ��żè..    ��ʿ�� ���� ... 

//���Ƿ��֣�������Щ��ʱ���¼���ĳ�Ա����ӵ����һ���Ĺ��ԣ������Լ�������
//���ʱ�����ǾͿ��Կ������ü̳еļ����������ظ����� 


//��ͳ����------------------------------------------------------------------ 
//Javaҳ�� 
//class Java
//{
//public:
//	//�������� 
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;		
//	}
//	void left()
//	{
//		cout << "Java��Python��C/C++...�������󲿷����б�" << endl;	
//    } 
//    //��ͬ����
//	void content()
//	{
//		cout << "Javaѧ����Ƶ" << endl;
//	} 
//}; 
//
////Pythonҳ�� 
//class Python
//{
//public:
//	//�������� 
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;		
//	}
//	void left()
//	{
//		cout << "Java��Python��C/C++...�������󲿷����б�" << endl;	
//    } 
//    //��ͬ����
//	void content()
//	{
//		cout << "Pythonѧ����Ƶ" << endl;
//	} 
//};
//
////C/C++ҳ�� 
//class CPP
//{
//public:
//	//�������� 
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;		
//	}
//	void left()
//	{
//		cout << "Java��Python��C/C++...�������󲿷����б�" << endl;	
//    } 
//    //��ͬ����
//	void content()
//	{
//		cout << "C/C++ѧ����Ƶ" << endl;
//	} 
//};



//�̳з���------------------------------------------------------------------ 
//�﷨ class ���� �� �̳з�ʽ ����
//���� ���� ������
//���� ���� ����
 
//����ҳ���� 
class BasePage
{
public:
    //�������� 
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;		
	}
	void left()
	{
		cout << "Java��Python��C/C++...�������󲿷����б�" << endl;	
    } 
}; 

//Javaҳ�� 
class Java : public BasePage 
{
public:
	void content()
	{
		cout << "Javaѧ����Ƶ" << endl;
	} 
}; 

//Pythonҳ�� 
class Python : public BasePage 
{
public:
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	} 
};

//C/C++ҳ�� 
class CPP : public BasePage 
{
public:
	void content()
	{
		cout << "C/C++ѧ����Ƶ" << endl;
	} 
};
 
void test1()
{
	cout << "Java������Ƶҳ������" << endl;
	Java J;
	J.header();
	J.footer();
	J.left();
	J.content(); 
	
	cout << "--------------------------------" << endl;
	cout << "Python������Ƶҳ������" << endl;
	Python p;
	p.header();
	p.footer();
	p.left();
	p.content(); 
	
	cout << "--------------------------------" << endl;
	cout << "C/C++������Ƶҳ������" << endl;
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

