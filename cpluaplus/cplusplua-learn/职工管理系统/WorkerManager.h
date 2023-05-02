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
	//判断文件是否为空的标准 
	bool m_FileIsEmp;
	//记录职工人数 
	int m_EmpNum;
	//职工数组指针 
	Worker** m_EmpArray;    //这里用数组存的，后面可以用链表更好 
public:
	//构造函数声明 
	WorkerManager();
	//析构函数声明
	~WorkerManager();
	//菜单
	void ShowMenu(); 
	//退出系统
	void ExitSystem(); 
	//增加 
	void AddEmp();
	//保存成文件
	void save(); 
	//统计文件中人数
	int GetEmpNum(); 
	//初始化员工数组（把原来文件里面的数据放入数组里面） 
	void init_Emp(); 
	//显示数据
	void ShowEmp(); 
	//判断员工是否存在,存在返回在数组中的位置 
	int IsExist(int ID); 
	//删除职工
	void DelEmp();
	//修改职工
	void ModEmp();
	//查找职工（两种方式）
	void FindEmp(); 
	//排序
	void SortEmp(); 
	//清空
	void CleanFile(); 
};



