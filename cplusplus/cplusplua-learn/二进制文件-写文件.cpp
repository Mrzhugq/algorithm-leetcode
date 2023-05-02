#include<iostream>
#include<fstream>
using namespace std;

//以二进制的方式对文件进行读写操作 
//打开方式指定为ios::binary


//二进制 写文件 
//函数原型ostream& write(const char* buffer,int len);
//参数：字符指针buffer指向内存中一段存储空间，len是读写的字节数

//二进制文件可以写入我们自定义类型数据 
class Person
{
public:
	char m_name[64]; //姓名，这里文件操作一般同char*,不用string
	int m_age; 
}; 


int main()
{
	//还可以ofstream ofs("Penson.txt",ios::out | ios::binary);
	
	//1.头文件 
	//2.创建流对象 
	ofstream ofs;
	//3.打开文件 
	ofs.open("Penson.txt",ios::out | ios::binary); //  两种打开方式中间用 | 
	//4.写文件 
	Person p1 = {"张三", 18};
	ofs.write( (const char*)&p1, sizeof(Person) );
	//5.关闭文件 
	ofs.close();
	return 0;
}

