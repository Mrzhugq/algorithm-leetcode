#include <iostream>
using namespace std;
#include "WorkerManager.h"
 
int main() 
{
	WorkerManager wm;
	//wm.ShowMenu();
	
	int choice = 0;
	while(true)
	{
		wm.ShowMenu();//��ʾ�˵� 
		cout << "���������ѡ��" << endl;
		cin >> choice;
		
		switch(choice)
		{
		case 0: //�˳� 
			wm.ExitSystem();
		    break;
		case 1: //���� 
		    wm.AddEmp(); 
		    break;
        case 2: //��ʾ 
            wm.ShowEmp();
		    break;
        case 3: //ɾ�� 
            wm.DelEmp();
		    break;
		case 4: //�޸� 
		    wm.ModEmp();
		    break;
		case 5: //���� 
		    wm.FindEmp();
		    break;
		case 6: //���� 
		    wm.SortEmp();
		    break;
		case 7: //���
		    wm.CleanFile(); 
		    break;
        default:
            system("cls");//���� 
			break; 
	    } 
	}
	return 0;
}
