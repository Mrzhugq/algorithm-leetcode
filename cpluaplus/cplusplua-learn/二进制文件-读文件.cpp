#include<iostream>
#include<fstream>
using namespace std;

//以二进制的方式对文件进行读写操作 
//打开方式指定为ios::binary

//二进制 读文件 
//函数原型ostream& read(char* buffer,int len);
//参数：字符指针buffer指向内存中一段存储空间，len是读写的字节数

//二进制文件可以写入我们自定义类型数据 
class Person
{
public:
	char m_name[64]; //姓名
	int m_age; 
}; 


int main()
{
    ifstream ifs;
    ifs.open("Penson.txt", ios::in | ios::binary);
    
	if(!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return 0;
	}
	
	Person p1;
	ifs.read((char*)&p1, sizeof(Person));
	
	cout << "姓名：" << p1.m_name << endl;
	cout << "年龄：" << p1.m_age << endl;
	
	ifs.close(); 
	return 0;
}

