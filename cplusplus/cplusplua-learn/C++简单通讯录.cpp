#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

struct person
{
    string Name;
    int Sex;
    int Age;
    string Phone;
    string Address;
};

struct AddrassBooks
{
	struct person PersonArr[MAX];
	int Size;
}; 

void Menu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl; 
} 

void AddPerson(struct AddrassBooks* abs)
{
	if(abs->Size == MAX)
	{
		cout << "ͨѶ¼����" << endl; 
		return;
	}
	else
	{
		cout << "��ֱ�����: ���� �Ա�(1������,2����Ů) ���� �ֻ��� ��ͥסַ" << endl;
		cin >> abs->PersonArr[abs->Size].Name;//���� 
		
		int sex = 0; //�Ա� 
		while(true)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
			{
				abs->PersonArr[abs->Size].Sex = sex;
				break;
			}
			else
			{
				cout << "�Ա������������������:" << endl;
			}
		}
		
		cin >> abs->PersonArr[abs->Size].Age;//���� 
		
		cin >> abs->PersonArr[abs->Size].Phone;//�ֻ��� 
		
		cin >> abs->PersonArr[abs->Size].Address;//סַ 
		
		abs->Size++;
		cout << "��ӳɹ�!" << endl;
		
		system("pause");//�밴��������� 
		system("cls");//���� 
	}
}

void PrintPerson(const struct AddrassBooks* abs)
{
	if(abs->Size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl; 
	}
	
	for(int i=0; i<abs->Size; i++)
	{
		cout << "������" << abs->PersonArr[i].Name << "\t";
		cout << "�Ա�" << (abs->PersonArr[i].Sex==1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->PersonArr[i].Age << "\t";
		cout << "�绰��" << abs->PersonArr[i].Phone << "\t";
		cout << "��ַ��" << abs->PersonArr[i].Address << endl;
	} 
	
	system("pause");//�밴��������� 
	system("cls");//���� 
}

int IsExist(struct AddrassBooks* abs, string name)//��������������ϵ���Ƿ���� 
{
	for(int i=0; i<abs->Size; i++)
	{
		if(abs->PersonArr[i].Name == name) //string���Ϳ���ֱ�ӱȽ�
		{
			return i;
		} 
	}
	return -1;
}

void DeletePerson(struct AddrassBooks* abs)
{
	string name;
	cout << "������Ҫɾ���˵�����:" << endl;
	cin >> name;
	int ret = IsExist(abs,name);
	if(ret == -1)
	{
		cout << "���޴���" << endl;
	} 
	else
	{
		//ɾ�� -> ����Ҫɾ���˺����������ǰ���Ǿ�����
		for(int i=ret; i<(abs->Size-1); i++)
		{
			abs->PersonArr[i] = abs->PersonArr[i+1];
		} 
		abs->Size--;
		cout << "ɾ���ɹ���" << endl;
	}
	
	system("pause");//�밴��������� 
	system("cls");//���� 
}

void FindPerson(struct AddrassBooks* abs)
{
	string name;
	cout << "������Ҫ�����˵�����:" << endl;
	cin >> name;
	int ret = IsExist(abs, name);
	
	if(ret == -1)
	{
		cout << "���޴���" << endl;
	} 
	else
	{
		cout << "������" << abs->PersonArr[ret].Name << "\t";
		cout << "�Ա�" << (abs->PersonArr[ret].Sex==1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->PersonArr[ret].Age << "\t";
		cout << "�绰��" << abs->PersonArr[ret].Phone << "\t";
		cout << "��ַ��" << abs->PersonArr[ret].Address << endl;
	}
	
	system("pause");//�밴��������� 
	system("cls");//���� 
}

void ModifyPerson(struct AddrassBooks* abs) 
{
	string name;
	cout << "������Ҫ�޸��˵�����:" << endl;
	cin >> name;
	int ret = IsExist(abs, name);
	
	if(ret == -1)
	{
		cout << "���޴���" << endl;
	} 
	else
	{
		cout << "��ֱ���������µ�: ���� �Ա�(1������,2����Ů) ���� �ֻ��� ��ͥסַ" << endl;
		
		cin >> abs->PersonArr[ret].Name;//���� 
		int sex = 0; //�Ա� 
		while(true)
		{
			cin >> sex;
			if(sex == 1 || sex == 2)
			{
				abs->PersonArr[ret].Sex = sex;
				break;
			}
			else
			{
				cout << "�Ա������������������:" << endl;
			}
		}
		
		cin >> abs->PersonArr[ret].Age;//���� 
		
		cin >> abs->PersonArr[ret].Phone;//�ֻ��� 
		
		cin >> abs->PersonArr[ret].Address;//סַ 
		cout << "�޸ĳɹ�!" << endl; 
	}
	 
	system("pause");//�밴��������� 
	system("cls");//���� 
}

void CleanPerson(struct AddrassBooks* abs)
{
	abs->Size = 0;
	cout << "����ɹ�!" << endl;
	
	system("pause");//�밴��������� 
	system("cls");//���� 
}



int main()
{
	int falg = 0;
	struct AddrassBooks abs;
	abs.Size = 0;
	
	while(true)
	{
		Menu();
		cin >> falg;
		
		switch(falg)
		{
			case 1 :
				AddPerson(&abs);
				break;
			case 2 :
				PrintPerson(&abs);
				break;
			case 3 :
				DeletePerson(&abs);
				break;
			case 4 :
				FindPerson(&abs);
				break;
			case 5 :
				ModifyPerson(&abs);
				break;
			case 6 :
				CleanPerson(&abs);
				break;
			case 0 :
				return 0;
				break;
			default :
				cout << "�����������������" << endl; 
				system("pause");//�밴��������� 
	            system("cls");//���� 
				break;
		} 
	}
	return 0;
}
