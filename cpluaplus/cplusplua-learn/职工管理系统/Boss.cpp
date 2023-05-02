#include"Boss.h"

Boss::Boss(int ID, string name, int dID)
{
	m_ID = ID;
	m_Name = name;
	m_DeptID = dID;
}
//显示个人信息
void Boss::showInof()
{
	cout << "职工编号：" << this->m_ID
	     << "\t职工姓名：" << this->m_Name
	     << "\t岗位：" << this->getDeptName()
	     << "\t岗位职责：管理公司所有事务" << endl; 
}
//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
} 
