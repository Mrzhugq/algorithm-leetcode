#include<iostream>
using namespace std;
//
int main()
{
	cout << "Hello World" << endl;
	
	system("pause");
	return 0;
} 

#include<iostream>
using namespace std;

#define DAY 7


int main()
{
	const int month = 12; 
	int a = 10;
	cout <<"a = " << a << endl;
	cout << "һ���ܹ���" << DAY << "��" << endl;
	cout << "һ����" << month << "����" << endl; 
	return 0;
}



int main()
{
	double b = 3.12358267;
	float a = 3.12358267f;
	cout << "b = " << b << endl;
	return 0;
}  

int main()
{
	char ch = 'a';
	cout << "ch = " << ch << endl;
	cout << (int)ch << endl;
	
	cout << "aaa\thello world" << endl; //\t�˸��ո� -> ǰ�治������Ͳ��ո� 
	cout << "aa\thello world" << endl;
	cout << "aaaaaa\thello world" << endl;
	return 0; 
}

#include<string>
int main()
{
	//1.
	char str[] = "hello world";
	cout << str << endl;
	
	//2.
	string str2 = "hello world";  //�����д��� 
	cout << str2 << endl;
	 
	return 0;
}

int main()
{
	bool falg = true;
	cout << falg << endl;
	
	bool falg2 = false;
	cout << falg2 << endl;
} 




