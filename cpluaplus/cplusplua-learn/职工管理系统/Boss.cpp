#include"Boss.h"

Boss::Boss(int ID, string name, int dID)
{
	m_ID = ID;
	m_Name = name;
	m_DeptID = dID;
}
//��ʾ������Ϣ
void Boss::showInof()
{
	cout << "ְ����ţ�" << this->m_ID
	     << "\tְ��������" << this->m_Name
	     << "\t��λ��" << this->getDeptName()
	     << "\t��λְ�𣺹���˾��������" << endl; 
}
//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
} 
