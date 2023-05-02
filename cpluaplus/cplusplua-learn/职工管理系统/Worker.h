#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象类（父类） 
class Worker
{
public:
	//职工编号 
	int m_ID;
	//姓名
	string m_Name;
	//部门编号
	int m_DeptID;
	
	//显示个人信息
	virtual void showInof() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;  
}; 
