#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//��ͨԱ���ļ� 

class Employee : public Worker
{
public: 
	//���캯��
    Employee(int ID, string name, int dID);
    //��ʾ������Ϣ
	void showInof();
	//��ȡ��λ����
	string getDeptName();  
}; 
