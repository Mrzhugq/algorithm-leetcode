#include"Employee.h"

Employee::Employee(int ID, string name, int dID)
{
	m_ID = ID;
	m_Name = name;
	m_DeptID = dID;
}
//显示个人信息
void Employee::showInof()
{
	cout << "职工编号：" << this->m_ID
	     << "\t职工姓名：" << this->m_Name
	     << "\t岗位：" << this->getDeptName()
	     << "\t岗位职责：完成经理交给的任务" << endl; 
}
//获取岗位名称
string Employee::getDeptName()
{
	return string("员工");
} 
