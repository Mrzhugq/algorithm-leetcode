#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//�ϰ�Ա���ļ�

class Boss : public Worker
{
public:
	//���캯��
    Boss(int ID, string name, int dID);
    //��ʾ������Ϣ
	void showInof();
	//��ȡ��λ����
	string getDeptName();  
};  
