#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//����Ա���ļ� 

class Manager : public Worker
{
public:
	//���캯��
    Manager(int ID, string name, int dID);
    //��ʾ������Ϣ
	void showInof();
	//��ȡ��λ����
	string getDeptName();  
}; 
