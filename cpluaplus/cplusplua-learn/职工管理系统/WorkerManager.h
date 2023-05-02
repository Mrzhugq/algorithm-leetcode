#pragma once
#include<iostream>
#include<fstream> 
using namespace std;
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"


class WorkerManager
{
public:
	//�ж��ļ��Ƿ�Ϊ�յı�׼ 
	bool m_FileIsEmp;
	//��¼ְ������ 
	int m_EmpNum;
	//ְ������ָ�� 
	Worker** m_EmpArray;    //�����������ģ����������������� 
public:
	//���캯������ 
	WorkerManager();
	//������������
	~WorkerManager();
	//�˵�
	void ShowMenu(); 
	//�˳�ϵͳ
	void ExitSystem(); 
	//���� 
	void AddEmp();
	//������ļ�
	void save(); 
	//ͳ���ļ�������
	int GetEmpNum(); 
	//��ʼ��Ա�����飨��ԭ���ļ���������ݷ����������棩 
	void init_Emp(); 
	//��ʾ����
	void ShowEmp(); 
	//�ж�Ա���Ƿ����,���ڷ����������е�λ�� 
	int IsExist(int ID); 
	//ɾ��ְ��
	void DelEmp();
	//�޸�ְ��
	void ModEmp();
	//����ְ�������ַ�ʽ��
	void FindEmp(); 
	//����
	void SortEmp(); 
	//���
	void CleanFile(); 
};



