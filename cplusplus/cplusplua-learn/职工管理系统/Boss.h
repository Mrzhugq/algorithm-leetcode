#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//老板员工文件

class Boss : public Worker
{
public:
	//构造函数
    Boss(int ID, string name, int dID);
    //显示个人信息
	void showInof();
	//获取岗位名称
	string getDeptName();  
};  
