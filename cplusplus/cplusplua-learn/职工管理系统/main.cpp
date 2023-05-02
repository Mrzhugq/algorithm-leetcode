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
		wm.ShowMenu();//显示菜单 
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		
		switch(choice)
		{
		case 0: //退出 
			wm.ExitSystem();
		    break;
		case 1: //增加 
		    wm.AddEmp(); 
		    break;
        case 2: //显示 
            wm.ShowEmp();
		    break;
        case 3: //删除 
            wm.DelEmp();
		    break;
		case 4: //修改 
		    wm.ModEmp();
		    break;
		case 5: //查找 
		    wm.FindEmp();
		    break;
		case 6: //排序 
		    wm.SortEmp();
		    break;
		case 7: //清空
		    wm.CleanFile(); 
		    break;
        default:
            system("cls");//清屏 
			break; 
	    } 
	}
	return 0;
}
