#include"Manager.h"

Manager::Manager(int ID, string name, int dID)
{
	m_ID = ID;
	m_Name = name;
	m_DeptID = dID;
}
//��ʾ������Ϣ
void Manager::showInof()
{
	cout << "ְ����ţ�" << this->m_ID
	     << "\tְ��������" << this->m_Name
	     << "\t��λ��" << this->getDeptName()
	     << "\t��λְ������ϰ彻�������񣬲����·��������ͨԱ��" << endl; 
}
//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
} 
