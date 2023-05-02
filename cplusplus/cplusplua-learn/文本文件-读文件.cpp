#include<iostream>
#include<fstream>
using namespace std; 

//文本文件 读文件
 
int main()
{
	ifstream ifs; //i代表input,输入，将文件内容输入到我们程序里面 
	
	ifs.open("test1.txt",ios::in);
	if(!ifs.is_open())  //判断是否打开成功，ifs.is_open()返回布尔值 
	{
		cout << "文件打开失败" << endl; 
		return 0;
	}
	
	//读数据
	//1. （直接读取，会以空格换行） 
	char buf[1024] = {0};
	while( ifs >> buf )
	{
		cout << buf << endl;
    } 
    //2. （逐行读取，可读空格） 
	char buf[1024] = {0};
	while(ifs.getline(buf,sizeof(buf))) //basic_istream& getline(E *s, streamsize n);
	{
		cout << buf << endl;
    } 
	//3. （逐行读取，可读空格）
	string buf;                  //istream& getline(istream *s, string &str, char delim); 
	while(getline(ifs, buf))     //istream *s，是一个输入流，
	{                            //string &n，从输入流读入字符串放入str中 
		cout << buf << endl;     //char delim，表达遇到这个字符就停止读取，不设置默认是\n 
	}
	//4. （逐字符读取，可读空格，效率低）
	char c;
	while( (c = ifs.get()) != EOF)//一个一个字符读取 
	{
	    cout << c;  //注意这后面没有endl,因为一个一个字符读取它会自己读取换行符 
	}
	
    ifs.close();
	return 0;
}

