#include<iostream>
#include<string>
using namespace std;

int main()
{
	//1.整形输入
	int a = 0;
	cout << "请输入整形a的值" << endl;
	cin >> a;
	cout << "a = " << a << endl;
	
	//浮点型输入
	float f1 = 0;
	cin >> f1;
	cout << "f1 = " << f1 << endl; 
	
	//字符型
	char ch = 0;
	cin >> ch;
	cout << "ch = " << ch << endl;
	
	//字符串型
	string str1 = "hello";
	cin >> str1;
	cout << "str1 = " << str1 << endl;
	
	//布尔类型
	bool flag = false;
	cin >> flag;
	cout << "flag = " << flag << endl;
	
	return 0; 
}

//int main()
//{
//	int a = 10;
//	int b = 3;
//	cout << a/b << endl;//除数不能为0 
//	cout << a%b << endl;//除数不能为零，小数不能取模运算 
//}
