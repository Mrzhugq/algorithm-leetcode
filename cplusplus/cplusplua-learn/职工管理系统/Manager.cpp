#include"Manager.h"

Manager::Manager(int ID, string name, int dID)
{
	m_ID = ID;
	m_Name = name;
	m_DeptID = dID;
}
//显示个人信息
void Manager::showInof()
{
	cout << "职工编号：" << this->m_ID
	     << "\t职工姓名：" << this->m_Name
	     << "\t岗位：" << this->getDeptName()
	     << "\t岗位职责：完成老板交给的任务，并且下发任务给普通员工" << endl; 
}
//获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
} 
