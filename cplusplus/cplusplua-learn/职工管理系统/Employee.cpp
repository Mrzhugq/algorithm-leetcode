#include"Employee.h"

Employee::Employee(int ID, string name, int dID)
{
	m_ID = ID;
	m_Name = name;
	m_DeptID = dID;
}
//��ʾ������Ϣ
void Employee::showInof()
{
	cout << "ְ����ţ�" << this->m_ID
	     << "\tְ��������" << this->m_Name
	     << "\t��λ��" << this->getDeptName()
	     << "\t��λְ����ɾ�����������" << endl; 
}
//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
} 
