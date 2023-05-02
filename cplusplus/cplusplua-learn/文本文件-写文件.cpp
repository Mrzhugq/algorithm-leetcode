#include<iostream>
#include<fstream>
using namespace std;

//文件操作
//程序运行时产生的数据都属于临时数据，程序一旦结束都会被释放
//通过文件可以将数据持久化 头文件<fstream> 

//文本类型分为两种
//1.文本文件：文件以文本的ASCII码形式存储在计算机中
//2.二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

//操作文件的三大类
//1.ofstream : 写文件
//2.ifstream : 读文件
//2.fstream  ：读写文件
 
//写文件步骤：
//1.包含头文件  2.创建流对象  3.打开文件  4.写数据  5.关闭文件

void test1()
{
	//1.包含头文件 
	//2.创建流对象 
	ofstream ofs;
	//3.打开文件  
	ofs.open("test1.txt",ios::out);
	//4.写数据 
	ofs << "姓名：张三" << endl;   //cout << 差不多cout是向标准输出流(屏幕)输出 
	ofs << "性别：男" << endl;     //ofs <<  是向文件流里面输出 
	ofs << "年龄：28" << endl; 
	//5.关闭文件 
	ofs.close(); 
}
 
int main()
{
	test1(); 
	return 0;
}

