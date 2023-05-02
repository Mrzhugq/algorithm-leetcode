#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//经理员工文件 

class Manager : public Worker
{
public:
	//构造函数
    Manager(int ID, string name, int dID);
    //显示个人信息
	void showInof();
	//获取岗位名称
	string getDeptName();  
}; 
