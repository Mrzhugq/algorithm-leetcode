#include<iostream>
#include<string>
using namespace std;

//��Щ˽�����ԣ�Ҳ�������������һЩ������������з��ʣ�����Ҫ�õ���Ԫ�ļ���
//��Ԫ��Ŀ�ľ�����һ������������ ������һ�����е�˽�г�Ա

//��Ԫ������ʵ��
//ȫ�ֺ�������Ԫ
//������Ԫ
//��Ա��������Ԫ

//------------------------------------------------------------------------------ 
//1.ȫ�ֺ�������Ԫ
class Building
{
	//18���⼸����ֻ��Ҫд�����ھ����ˣ�Ҳ����Ҫд��public�� 
	//����friend˵��GoodGay��Building�ĺ����ѣ����Է������ڵ�˽�г�Ա 
	friend void GoodGay(Building &b);
public:
    string m_sittingRoom;//���� 
private:
    string m_BedRoom;//���� 
public:
	Building()
	{
		m_sittingRoom = "����";
        m_BedRoom = "����";
    } 
 
}; 

void GoodGay(Building &b)
{
    cout << "������ȫ�ֺ��� ���ڷ��ʣ�" << b.m_sittingRoom << endl; 
	//�������18�У�m_BadRoom�����Ƿ��ʲ�����	
    cout << "������ȫ�ֺ��� ���ڷ��ʣ�" << b.m_BedRoom << endl; 	
}

int main()
{
	Building b;
	GoodGay(b);
} 


//------------------------------------------------------------------------------ 
//2.������Ԫ
class Building1
{
	//goodgay���Ǻ����ѣ��Ϳ��Է��ʸ����е�˽�г�Ա�� 
	friend class goodgay;
public:
    string m_sittingRoom;//���� 
private:
    string m_BedRoom;//���� 
    
public:
	Building1()
	{
		m_sittingRoom = "����";
        m_BedRoom = "����";
    } 
 
};

class goodgay
{
public:
    Building1* building;	
		
	goodgay()
	{
		building = new Building1;
	}
	void visit()//����Building1�е����� 
	{
		cout << "�����������ڷ��ʣ�" << building->m_sittingRoom << endl;
		//��Ϊ��52�У�����������Է�����һ�����е�˽�г�Ա 
		cout << "�����������ڷ��ʣ�" << building->m_BedRoom << endl;
	}
}; 

int main1()
{
	goodgay g;
	g.visit();
}


//------------------------------------------------------------------------------ 
//3.��Ա��������Ԫ

class Building2;//���� 
//����ע��һ����������Ķ���λ�� 
class goodgay2
{
public:
    Building2* building;
		
	goodgay2();
	void visit1();
	void visit2();
};

class Building2
{
	//goodgay2���µ�visit1��Ա�����Ǻ����ѣ����Է��ʱ����˽������ 
	friend void goodgay2::visit1();
public:
    string m_sittingRoom;//���� 
private:
    string m_BedRoom;//���� 
    
public:
	Building2();
};

//��Ա��������ʵ�� 
Building2::Building2()
{
	m_sittingRoom = "����";
    m_BedRoom = "����";
}
 
goodgay2::goodgay2()
{
	building = new Building2;
}

void goodgay2::visit1()//���Է���Building2�е�˽�г�Ա 
{
    cout << "visit1 ���ڷ��ʣ�" << building->m_sittingRoom << endl;
    //p109������ 
    cout << "visit1 ���ڷ��ʣ�" << building->m_BedRoom << endl;
}

void goodgay2::visit2()//�����Է���Building2�е�˽�г�Ա  
{
	cout << "visit2 ���ڷ��ʣ�" << building->m_sittingRoom << endl;
    //û�м�friend visit2�ǲ��ܷ���˽�����Ե� 
	//cout << "visit2 ���ڷ��ʣ�" << building->m_BedRoom << endl;
}


int main2()
{
	goodgay2 g2;
	g2.visit1();
	g2.visit2(); 
}
