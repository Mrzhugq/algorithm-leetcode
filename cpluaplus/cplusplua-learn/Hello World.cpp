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
	cout << "一周总共有" << DAY << "天" << endl;
	cout << "一年有" << month << "个月" << endl; 
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
	
	cout << "aaa\thello world" << endl; //\t八个空格 -> 前面不够后面就补空格 
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
	string str2 = "hello world";  //后面有大用 
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




