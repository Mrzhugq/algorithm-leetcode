#include<iostream> 
using namespace std;


//�̳��еĶ���ģ��
//���⣺�Ӹ���̳й����ĳ�Ա����Щ������������У�

class Base1
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
 
class Son1 : public Base1
{
public:
	int m_d;
}; 

int main()
{
    Son1 s1;
    //�����е����� �Ǿ�̬��Ա���� ���ᱻ����̳���ȥ
	//�����е�˽�г�Ա���� �Ǳ������������ˣ���˷��ʲ�����������ȷʵ���̳���ȥ��(��Ȼ����) 
    cout << "Son1ռ���ֽ�����" << sizeof(s1) << endl;//16 
	return 0;
}

