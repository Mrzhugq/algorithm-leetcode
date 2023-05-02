#include<iostream>
#include<fstream>
using namespace std; 

//�ı��ļ� ���ļ�
 
int main()
{
	ifstream ifs; //i����input,���룬���ļ��������뵽���ǳ������� 
	
	ifs.open("test1.txt",ios::in);
	if(!ifs.is_open())  //�ж��Ƿ�򿪳ɹ���ifs.is_open()���ز���ֵ 
	{
		cout << "�ļ���ʧ��" << endl; 
		return 0;
	}
	
	//������
	//1. ��ֱ�Ӷ�ȡ�����Կո��У� 
	char buf[1024] = {0};
	while( ifs >> buf )
	{
		cout << buf << endl;
    } 
    //2. �����ж�ȡ���ɶ��ո� 
	char buf[1024] = {0};
	while(ifs.getline(buf,sizeof(buf))) //basic_istream& getline(E *s, streamsize n);
	{
		cout << buf << endl;
    } 
	//3. �����ж�ȡ���ɶ��ո�
	string buf;                  //istream& getline(istream *s, string &str, char delim); 
	while(getline(ifs, buf))     //istream *s����һ����������
	{                            //string &n���������������ַ�������str�� 
		cout << buf << endl;     //char delim�������������ַ���ֹͣ��ȡ��������Ĭ����\n 
	}
	//4. �����ַ���ȡ���ɶ��ո�Ч�ʵͣ�
	char c;
	while( (c = ifs.get()) != EOF)//һ��һ���ַ���ȡ 
	{
	    cout << c;  //ע�������û��endl,��Ϊһ��һ���ַ���ȡ�����Լ���ȡ���з� 
	}
	
    ifs.close();
	return 0;
}

