#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ�������ࣨ���ࣩ 
class Worker
{
public:
	//ְ����� 
	int m_ID;
	//����
	string m_Name;
	//���ű��
	int m_DeptID;
	
	//��ʾ������Ϣ
	virtual void showInof() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;  
}; 
