#include<iostream>
#include<string> 
using namespace std;

//string本质上是一个类

//string和char* 区别：
//       char* 是一个指针 
//       string是一个类，类内部封装了char*，管理这个字符串，是一个char*的容器 

//string类内封装了很多成员方法
//查找find，拷贝copy，删除delete，替换replace，插入insert
//string管理char* 所分配的内存，不用担心复制越界和取值越界，由类内部进行负责




//--------------------------------------------------------------------------------
//string构造函数原型 
/* 
string();                    //string str;
string(const char* s)        //使用字符串s初始化
string(const string &str)    //拷贝构造 string str2(str1);
string(int n,char c)         //使用n个字符c初始化
*/
 
//string类的构造函数测试 
void test1()
{
	//1.
	string s1; //默认构造
	//2.
	const char* str = "hello word";
	string s2(str);
	cout << "s2 = " << s2 << endl;
	//3.
	string s3(s2); //拷贝构造
    cout << "s3 = " << s3 << endl;
	//4.
	string s4(10,'a');
	cout << "s4 = " << s4 << endl;	
	
	//cout << s4.length() << s4.size() << endl; 
}



//--------------------------------------------------------------------------------
//string赋值操作原型 
/*
string& operator=(const char* s);       //char*类型字符串赋给当前的字符串 
string& operator=(const string &str);   //把字符串str赋给当前字符串 
string& operator=(char c);              //字符赋给当前字符串 

string& assign(const char* s);          //把char*类型字符串s赋给当前的字符串  
string& assign(const char* s, int n);   //把字符串s的前n个字符赋给当前的字符串 
string& assign(const string &str);      //把字符串str赋给当前的字符串  
string& assign(int n,char n)            //用n个字符c赋给当前字符串 
*/ 
void test2()
{
	//1.
	const char* temp = "Hello Word";
	string s1 = temp;  //string s1 = "Hello Word";
	cout << "s1 = " << s1 << endl; 
	//2.
	string s2;
	s2 = s1;
	cout << "s2 = " << s2 << endl;
	//3.(不常用) 
	string s3;
	s3 = 'a';
	cout << "s3 = " << s3 << endl;
	
	//4.
	string s4;
	s4.assign("Hello C++");
	cout << "s4 = " << s4 << endl;
	//5.
	string s5;
	s5.assign("Hello C++",5);
	cout << "s5 = " << s5 << endl;
	//6.
	string s6;
	s6.assign(s5);
	cout << "s6 = " << s6 << endl;
	//7.
	string s7;
	s7.assign(10,'a');
	cout << "s7 = " << s7 << endl;      
}


//--------------------------------------------------------------------------------
//string字符串拼接 （追加） 
/* 
string& operator+=(const char* s);  
string& operator+=(const char c);
string& operator+=(const string &str);

string& append(const char* s);
string& append(const char* s, int n);
string& append(const string &str);
string& append(const string &str,int pos,int n) 
//字符串str中从pos开始的n的字符连接到结尾，pos截取位置，n截取的字符个数 
*/ 

void test3()
{
    //1.
	string s1 = "Hello";
	s1 += " Word";
	cout << s1 << endl;
	//2.
	string s2 = "Hello";
	s2 += 'C';
	cout << s2 << endl;
	//3.
	string s3 = " C++";
	s1 += s3;
	cout << s1 << endl;
	//4.
	string s4 = "II";
	s4.append(" love");
	cout << s4 << endl;
	//5.
	string s5 = "zgq";
	s5.append("Hello Word",5);
	cout << s5 << endl;
	//6.
	string s6 = " you";
	s4.append(s6);
	cout << s4 << endl;
	//7.
	string s7 = "youabcdef";
	s4.append(s7,3,4); //从pos位置开始的n个字符，追加到s4上 
	cout << s4 << endl;
} 



//--------------------------------------------------------------------------------
//string的查找和替换 函数原型 
/* 
int find(const string &str, int pos = 0) const;    //查找str第一次出现位置，pos开始查 
int find(const char* s, int pos = 0) const;        //查找s第一次出现位置，pos开始查 
int find(const char* s, int pos = 0, int n) const; //pos位置开始查找n个字符，s第一次出现位置 
int find(const char c, int pos = 0) const;         //查找字符c第一次出现位置，pos开始查 

int rfind(const string &str, int pos = npos) const;//查找str最后一次出现位置，pos开始查  
int rfind(const char *s, int pos = npos) const;    //查找s最后一次出现位置，pos开始查
int rfind(const char *s, int pos, int n = npos) const;  //pos位置开始查找n个字符，s最后一次出现位置 
int rfind(const char c, int pos = npos) const;      //查找字符c最后一次出现位置，pos开始查  
(成员函数后面加const代表常函数，常函数内不可修改成员属性) 

string& replace(int pos, int n, const string &str);//替换从pos开始的n个字符为字符串str 
string& replace(int pos, int n, const char* s);    //替换从pos开始的n个字符为字符串s 
*/ 

void test4()
{
	//查找
	//1. 
	string s1 = "abcdefde";
	int ret1 = s1.find("de");
	cout << ret1 << endl;//找不到返回-1
    //2.
    int ret2 = s1.rfind("de"); //rfind是从右往左查，find是从左往右查 
	cout << ret2 << endl; 
	
	//替换
	string s2 = "abcdef";
	s2.replace(1,3,"hhhh");
	//从1位置开始的3个字符替换，但我们传了4个字符，所以从1开始替换了4个 
	
	//s2.replace(1,3,"hh");
	//如果我们传了两个字符，bcd -> hh ，会少一个字符变为ahhef 
	cout << s2 << endl; 
}



//--------------------------------------------------------------------------------
//string字符串比较 函数原型 
/*
按字符串ASCII逐个进行比较 
相等返回0，> 返回1(大于零的数)，< 返回-1(小于零的数)
int compare(const string &str) const; 
int compare(const char* s) const; 
*/ 

void test5()
{
	string s1 = "Hello";
	string s2 = "abc";
	int ret = s1.compare(s2);
	cout << ret << endl;
}


//--------------------------------------------------------------------------------
//string中单个字符存取方法
//1.char& operator[](int n);
//2.char& at(int n); 

void test6()
{
	string str = "Hello";
	//读 
	for(int i=0; i<str.size(); i++)
	{
		cout << str[i] << " "; 
		//cout << str.at(i) << " "; 
	}
	cout << endl;
	//写
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl; 
}


//--------------------------------------------------------------------------------
//string插入与删除
/*
string& insert(int pos, char* s);          //插入字符串 
string& insert(int pos, const string &str);//插入字符串 
string& insert(int pos, int n, char c);    //在pos位置插入n个c字符 
string& erase(int pos, int n = npos);      //删除从pos位置开始的n个字符
//npos 是 直到字符串结束 
*/ 

void test7()
{
	//1.
	string str = "Hello";
	str.insert(1,"Love");
	cout << str << endl; 
	//2.
	str.insert(0,2,'W');
	cout << str << endl; 
	//3.(WWHLoveello)
	str.erase(3,4);      //  -> 从下标3开始(包括3)删除4个字符 
	cout << str << endl; 
	
	//str.erase(3); -> str.erase(3,npos) ->  从下标3开始(包括3),一直删除到字符串结束位置 
}
 
 
//--------------------------------------------------------------------------------
//string字串 函数原型 
//string substr(int pos = 0; int n = npos) //返回由pos开始的n个字符串组成的字符串
//                                         //返回值是string，不是string& 
void test8()
{
	//1. 
	string s1 = "abcdef";
	string s2 = s1.substr(1,3); //从1下标开始的三个字符 
	cout << s2 << endl;
	//2.实用操作
	string email = "zhangsan@qq.com";
	
	//从邮箱中截取用户名
	int pos = email.find("@"); //8
	string usrName = email.substr(0,pos);
	cout << usrName << endl; 
} 
 

//push pop
void test9()
{
	//1.
	string str = "Hello Word";
	str.push_back('C');
	cout << str << endl;  // "Hello WordC"
	
	//2.
	str.pop_back();
	cout << str << endl; //"Hello Word"
}


int main()
{
	//test1(); 
	//test2(); 
	//test3(); 
	//test4(); 
	//test5(); 
	//test6(); 
	//test7(); 
	//test8();
	test9(); 
	return 0;
}

