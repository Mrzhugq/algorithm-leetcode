#include<iostream>
#include<string> 
using namespace std;

//string��������һ����

//string��char* ����
//       char* ��һ��ָ�� 
//       string��һ���࣬���ڲ���װ��char*����������ַ�������һ��char*������ 

//string���ڷ�װ�˺ܶ��Ա����
//����find������copy��ɾ��delete���滻replace������insert
//string����char* ��������ڴ棬���õ��ĸ���Խ���ȡֵԽ�磬�����ڲ����и���




//--------------------------------------------------------------------------------
//string���캯��ԭ�� 
/* 
string();                    //string str;
string(const char* s)        //ʹ���ַ���s��ʼ��
string(const string &str)    //�������� string str2(str1);
string(int n,char c)         //ʹ��n���ַ�c��ʼ��
*/
 
//string��Ĺ��캯������ 
void test1()
{
	//1.
	string s1; //Ĭ�Ϲ���
	//2.
	const char* str = "hello word";
	string s2(str);
	cout << "s2 = " << s2 << endl;
	//3.
	string s3(s2); //��������
    cout << "s3 = " << s3 << endl;
	//4.
	string s4(10,'a');
	cout << "s4 = " << s4 << endl;	
	
	//cout << s4.length() << s4.size() << endl; 
}



//--------------------------------------------------------------------------------
//string��ֵ����ԭ�� 
/*
string& operator=(const char* s);       //char*�����ַ���������ǰ���ַ��� 
string& operator=(const string &str);   //���ַ���str������ǰ�ַ��� 
string& operator=(char c);              //�ַ�������ǰ�ַ��� 

string& assign(const char* s);          //��char*�����ַ���s������ǰ���ַ���  
string& assign(const char* s, int n);   //���ַ���s��ǰn���ַ�������ǰ���ַ��� 
string& assign(const string &str);      //���ַ���str������ǰ���ַ���  
string& assign(int n,char n)            //��n���ַ�c������ǰ�ַ��� 
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
	//3.(������) 
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
//string�ַ���ƴ�� ��׷�ӣ� 
/* 
string& operator+=(const char* s);  
string& operator+=(const char c);
string& operator+=(const string &str);

string& append(const char* s);
string& append(const char* s, int n);
string& append(const string &str);
string& append(const string &str,int pos,int n) 
//�ַ���str�д�pos��ʼ��n���ַ����ӵ���β��pos��ȡλ�ã�n��ȡ���ַ����� 
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
	s4.append(s7,3,4); //��posλ�ÿ�ʼ��n���ַ���׷�ӵ�s4�� 
	cout << s4 << endl;
} 



//--------------------------------------------------------------------------------
//string�Ĳ��Һ��滻 ����ԭ�� 
/* 
int find(const string &str, int pos = 0) const;    //����str��һ�γ���λ�ã�pos��ʼ�� 
int find(const char* s, int pos = 0) const;        //����s��һ�γ���λ�ã�pos��ʼ�� 
int find(const char* s, int pos = 0, int n) const; //posλ�ÿ�ʼ����n���ַ���s��һ�γ���λ�� 
int find(const char c, int pos = 0) const;         //�����ַ�c��һ�γ���λ�ã�pos��ʼ�� 

int rfind(const string &str, int pos = npos) const;//����str���һ�γ���λ�ã�pos��ʼ��  
int rfind(const char *s, int pos = npos) const;    //����s���һ�γ���λ�ã�pos��ʼ��
int rfind(const char *s, int pos, int n = npos) const;  //posλ�ÿ�ʼ����n���ַ���s���һ�γ���λ�� 
int rfind(const char c, int pos = npos) const;      //�����ַ�c���һ�γ���λ�ã�pos��ʼ��  
(��Ա���������const�����������������ڲ����޸ĳ�Ա����) 

string& replace(int pos, int n, const string &str);//�滻��pos��ʼ��n���ַ�Ϊ�ַ���str 
string& replace(int pos, int n, const char* s);    //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s 
*/ 

void test4()
{
	//����
	//1. 
	string s1 = "abcdefde";
	int ret1 = s1.find("de");
	cout << ret1 << endl;//�Ҳ�������-1
    //2.
    int ret2 = s1.rfind("de"); //rfind�Ǵ�������飬find�Ǵ������Ҳ� 
	cout << ret2 << endl; 
	
	//�滻
	string s2 = "abcdef";
	s2.replace(1,3,"hhhh");
	//��1λ�ÿ�ʼ��3���ַ��滻�������Ǵ���4���ַ������Դ�1��ʼ�滻��4�� 
	
	//s2.replace(1,3,"hh");
	//������Ǵ��������ַ���bcd -> hh ������һ���ַ���Ϊahhef 
	cout << s2 << endl; 
}



//--------------------------------------------------------------------------------
//string�ַ����Ƚ� ����ԭ�� 
/*
���ַ���ASCII������бȽ� 
��ȷ���0��> ����1(���������)��< ����-1(С�������)
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
//string�е����ַ���ȡ����
//1.char& operator[](int n);
//2.char& at(int n); 

void test6()
{
	string str = "Hello";
	//�� 
	for(int i=0; i<str.size(); i++)
	{
		cout << str[i] << " "; 
		//cout << str.at(i) << " "; 
	}
	cout << endl;
	//д
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl; 
}


//--------------------------------------------------------------------------------
//string������ɾ��
/*
string& insert(int pos, char* s);          //�����ַ��� 
string& insert(int pos, const string &str);//�����ַ��� 
string& insert(int pos, int n, char c);    //��posλ�ò���n��c�ַ� 
string& erase(int pos, int n = npos);      //ɾ����posλ�ÿ�ʼ��n���ַ�
//npos �� ֱ���ַ������� 
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
	str.erase(3,4);      //  -> ���±�3��ʼ(����3)ɾ��4���ַ� 
	cout << str << endl; 
	
	//str.erase(3); -> str.erase(3,npos) ->  ���±�3��ʼ(����3),һֱɾ�����ַ�������λ�� 
}
 
 
//--------------------------------------------------------------------------------
//string�ִ� ����ԭ�� 
//string substr(int pos = 0; int n = npos) //������pos��ʼ��n���ַ�����ɵ��ַ���
//                                         //����ֵ��string������string& 
void test8()
{
	//1. 
	string s1 = "abcdef";
	string s2 = s1.substr(1,3); //��1�±꿪ʼ�������ַ� 
	cout << s2 << endl;
	//2.ʵ�ò���
	string email = "zhangsan@qq.com";
	
	//�������н�ȡ�û���
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

