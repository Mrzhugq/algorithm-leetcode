#include<iostream>
#include<string>
using namespace std;

int main()
{
	//1.��������
	int a = 0;
	cout << "����������a��ֵ" << endl;
	cin >> a;
	cout << "a = " << a << endl;
	
	//����������
	float f1 = 0;
	cin >> f1;
	cout << "f1 = " << f1 << endl; 
	
	//�ַ���
	char ch = 0;
	cin >> ch;
	cout << "ch = " << ch << endl;
	
	//�ַ�����
	string str1 = "hello";
	cin >> str1;
	cout << "str1 = " << str1 << endl;
	
	//��������
	bool flag = false;
	cin >> flag;
	cout << "flag = " << flag << endl;
	
	return 0; 
}

//int main()
//{
//	int a = 10;
//	int b = 3;
//	cout << a/b << endl;//��������Ϊ0 
//	cout << a%b << endl;//��������Ϊ�㣬С������ȡģ���� 
//}
