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
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清除联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl; 
} 

void AddPerson(struct AddrassBooks* abs)
{
	if(abs->Size == MAX)
	{
		cout << "通讯录已满" << endl; 
		return;
	}
	else
	{
		cout << "请分别输入: 姓名 性别(1代表男,2代表女) 年龄 手机号 家庭住址" << endl;
		cin >> abs->PersonArr[abs->Size].Name;//姓名 
		
		int sex = 0; //性别 
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
				cout << "性别输入错误，请重新输入:" << endl;
			}
		}
		
		cin >> abs->PersonArr[abs->Size].Age;//年龄 
		
		cin >> abs->PersonArr[abs->Size].Phone;//手机号 
		
		cin >> abs->PersonArr[abs->Size].Address;//住址 
		
		abs->Size++;
		cout << "添加成功!" << endl;
		
		system("pause");//请按任意键继续 
		system("cls");//清屏 
	}
}

void PrintPerson(const struct AddrassBooks* abs)
{
	if(abs->Size == 0)
	{
		cout << "通讯录为空" << endl; 
	}
	
	for(int i=0; i<abs->Size; i++)
	{
		cout << "姓名：" << abs->PersonArr[i].Name << "\t";
		cout << "性别：" << (abs->PersonArr[i].Sex==1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->PersonArr[i].Age << "\t";
		cout << "电话：" << abs->PersonArr[i].Phone << "\t";
		cout << "地址：" << abs->PersonArr[i].Address << endl;
	} 
	
	system("pause");//请按任意键继续 
	system("cls");//清屏 
}

int IsExist(struct AddrassBooks* abs, string name)//根据姓名查找联系人是否存在 
{
	for(int i=0; i<abs->Size; i++)
	{
		if(abs->PersonArr[i].Name == name) //string类型可以直接比较
		{
			return i;
		} 
	}
	return -1;
}

void DeletePerson(struct AddrassBooks* abs)
{
	string name;
	cout << "请输入要删除人的姓名:" << endl;
	cin >> name;
	int ret = IsExist(abs,name);
	if(ret == -1)
	{
		cout << "查无此人" << endl;
	} 
	else
	{
		//删除 -> 即把要删除人后面的数据往前覆盖就行了
		for(int i=ret; i<(abs->Size-1); i++)
		{
			abs->PersonArr[i] = abs->PersonArr[i+1];
		} 
		abs->Size--;
		cout << "删除成功！" << endl;
	}
	
	system("pause");//请按任意键继续 
	system("cls");//清屏 
}

void FindPerson(struct AddrassBooks* abs)
{
	string name;
	cout << "请输入要查找人的姓名:" << endl;
	cin >> name;
	int ret = IsExist(abs, name);
	
	if(ret == -1)
	{
		cout << "查无此人" << endl;
	} 
	else
	{
		cout << "姓名：" << abs->PersonArr[ret].Name << "\t";
		cout << "性别：" << (abs->PersonArr[ret].Sex==1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->PersonArr[ret].Age << "\t";
		cout << "电话：" << abs->PersonArr[ret].Phone << "\t";
		cout << "地址：" << abs->PersonArr[ret].Address << endl;
	}
	
	system("pause");//请按任意键继续 
	system("cls");//清屏 
}

void ModifyPerson(struct AddrassBooks* abs) 
{
	string name;
	cout << "请输入要修改人的姓名:" << endl;
	cin >> name;
	int ret = IsExist(abs, name);
	
	if(ret == -1)
	{
		cout << "查无此人" << endl;
	} 
	else
	{
		cout << "请分别输入该人新的: 姓名 性别(1代表男,2代表女) 年龄 手机号 家庭住址" << endl;
		
		cin >> abs->PersonArr[ret].Name;//姓名 
		int sex = 0; //性别 
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
				cout << "性别输入错误，请重新输入:" << endl;
			}
		}
		
		cin >> abs->PersonArr[ret].Age;//年龄 
		
		cin >> abs->PersonArr[ret].Phone;//手机号 
		
		cin >> abs->PersonArr[ret].Address;//住址 
		cout << "修改成功!" << endl; 
	}
	 
	system("pause");//请按任意键继续 
	system("cls");//清屏 
}

void CleanPerson(struct AddrassBooks* abs)
{
	abs->Size = 0;
	cout << "清除成功!" << endl;
	
	system("pause");//请按任意键继续 
	system("cls");//清屏 
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
				cout << "输入错误！请重新输入" << endl; 
				system("pause");//请按任意键继续 
	            system("cls");//清屏 
				break;
		} 
	}
	return 0;
}
