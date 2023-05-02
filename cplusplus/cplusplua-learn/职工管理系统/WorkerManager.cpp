#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	//三种情况初始化m_FileIsEmp
	//1.文件不存在
	ifstream ifs;
	ifs.open("empFile.text",ios::in);
	if(!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		this->m_FileIsEmp = true;      //初始化文件是否为空 
		this->m_EmpNum = 0;            //初始化人数 
	    this->m_EmpArray = NULL;       //初始化指针数组 
	    return;
	}
	
	//2.文件存在，但数据为空
	char ch;
	ifs >> ch; //因为eof()函数性质，要先读取一次
	if(ifs.eof())
	{
        //cout << "文件为空！" << endl;
		this->m_FileIsEmp = true;
		this->m_EmpNum = 0;
	    this->m_EmpArray = NULL;
	    ifs.close();
	    return;
	}
	
	//3.文件存在，数据不为空 
	int num = this->GetEmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_FileIsEmp = false;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker*[m_EmpNum];//创建大小为一开始文件里面存的员工数的Worker*数组 
	this->init_Emp();                        //把文件里面的员工输入到本程序里面 
	
	
//	for(int i=0; i<this->m_EmpNum; i++)
//	{
//		cout << "职工编号：" << this->m_EmpArray[i]->m_ID
//		     << "\t姓名：" << this->m_EmpArray[i]->m_Name
//			 << "\t部门编号：" << this->m_EmpArray[i]->m_DeptID << endl; 
//	} 

}

WorkerManager::~WorkerManager()
{
	if(this->m_EmpArray != NULL)
	{
		for(int i=0; i<this->m_EmpNum; i++)
		{
			if(this->m_EmpArray[i] != NULL)
			{
			    delete this->m_EmpArray[i];	
			}
		}
		
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	} 
}

void WorkerManager::ShowMenu()
{
	cout << "------------------------------" << endl; 
	cout << "-------0.退出管理系统---------" << endl; 
	cout << "-------1.增加职工信息---------" << endl; 
	cout << "-------2.显示职工信息---------" << endl; 
	cout << "-------3.删除离职职工---------" << endl; 
	cout << "-------4.修改职工信息---------" << endl; 
	cout << "-------5.查找职工信息---------" << endl; 
	cout << "-------6.按照编号排序---------" << endl; 
	cout << "-------7.清空所有文档---------" << endl; 
	cout << "------------------------------" << endl; 
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);  
}

void WorkerManager::AddEmp()
{
	int num = 0;
	cout << "请输入要添加职工数量：" << endl; 
	cin >> num;
	if(num > 0)
	{
		//计算添加完的数组大小 
		int newSize = this->m_EmpNum + num;
		Worker** newspace = new Worker*[newSize];
		
		//如果原来有数据，就把将原来的拷贝到新的大空间里面
		if(this->m_EmpArray != NULL)
		{
			for(int i=0; i<this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];  
			}
		}
		
		//添加新数据
		for(int i=0; i<num; i++)
		{
			int Id;
			string name;
			int dId;
			cout << "请输入第" << i+1 << "个新职工编号: " << endl;
			cin >> Id;
			
			//防止编号重复 
			for(int i=0; i<this->m_EmpNum; i++)
			{
				if(this->m_EmpArray[i]->m_ID == Id)
				{
					cout << "编号重复，请重新输入：" << endl;
					cin >> Id; 
				}
			}
			
			cout << "请输入第" << i+1 << "个新职工姓名: " << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dId;
			
			Worker* worker = NULL;
			switch(dId)
			{
			case 1:
				worker = new Employee(Id,name,dId); 
			    break;
			case 2:
				worker = new Employee(Id,name,dId); 
			    break;
			case 3:
				worker = new Boss(Id,name,dId); 
			    break;	
			} 
			
			//将创建的新员工，保存数组中
			newspace[this->m_EmpNum + i] = worker;
		} 
		
		//释放原来的空间
		delete[] m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newspace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		
		cout << "成功添加了" << num << "名职工! " << endl; 
		this->save();//保存文件 
		this->m_FileIsEmp = false;
    }
    
	else
	{
		cout << "输入有误！" << endl; 
	} 
	
	system("pause");
	system("cls");//清屏 
} 


void WorkerManager::save()
{
	ofstream ofs;
	ofs.open("empFile.text",ios::out); //写文件
	//将每个人数据写入文件
	for(int i=0; i<this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
		    << this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl; 
	} 
	ofs.close();
}

int WorkerManager::GetEmpNum()
{
	ifstream ifs;
	ifs.open("empFile.text",ios::in);
	
	int num = 0;
	int Id;
	string name;
	int dId;
	
	while(ifs >> Id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

void WorkerManager::init_Emp()
{
    ifstream ifs;
	ifs.open("empFile.text",ios::in);
	
	int Id;
	string name;
	int dId;
	
	int Index = 0;
	while(ifs >> Id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if(dId == 1)
		{
			worker = new Employee(Id,name,dId);
		}
		else if(dId == 2)
		{
			worker = new Manager(Id,name,dId);
		}
		else
		{
			worker = new Boss(Id,name,dId);
		}
		this->m_EmpArray[Index] = worker;
		Index++;
	}
	ifs.close();
}

void WorkerManager::ShowEmp()
{
	//判断文件是不是空或者不存在 
	if(this->m_FileIsEmp)
	{
		cout << "文件为空或者记录为空!" << endl;
	}
	else
	{
		for(int i=0; i<this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInof();
		}
	}
	
	system("pause");
	system("cls");//清屏 
}

int WorkerManager::IsExist(int ID)
{
	int Index = -1;
	for(int i=0; i<this->m_EmpNum; i++)
	{
		if(this->m_EmpArray[i]->m_ID == ID)
		{
			Index = i;
			break;
		}
	}
	return Index;
}

void WorkerManager::DelEmp()
{
	if(m_FileIsEmp)
	{
		cout << "文件不存在或者记录为空！" << endl;
		system("pause");
	    system("cls");//清屏
		return; 
	}
	
	cout << "请输入要删除职工编号：" << endl;
	int DelID = 0;
	cin >> DelID;
	int Index = this->IsExist(DelID);
	if(Index == -1)
	{
		cout << "删除失败，没有找到该编号记录！" << endl;
		system("pause");
	    system("cls");//清屏
		return;
	}
	
	for(int i=Index; i<this->m_EmpNum-1; i++)
	{
		this->m_EmpArray[i] = this->m_EmpArray[i+1];
	}
	this->m_EmpNum--; //人数减一
	this->save();     //更新文件
	cout << "删除成功！" << endl; 
	
	system("pause");
	system("cls");//清屏
}


void WorkerManager::ModEmp()
{
	if(m_FileIsEmp)
	{
		cout << "文件不存在或者记录为空！" << endl;
		system("pause");
	    system("cls");//清屏
		return; 
	}
	
	cout << "请输入要修改职工编号：" << endl;
	int ModID = 0;
	cin >> ModID;
	int Index = this->IsExist(ModID);
	if(Index == -1)
	{
		cout << "查无此人！" << endl;
		system("pause");
	    system("cls");//清屏
		return;
	}
	
	delete this->m_EmpArray[Index]; //释放掉旧的信息
	
	int newID;
	string newname;
	int newdId;
	cout << "查找到了" << ModID << "号职工，请输入新的职工编号：" << endl;
	cin >> newID;
	cout << "请输入新的姓名：" << endl;
	cin >> newname;
	cout << "请输入新的岗位：" << endl;
	cout << "1.普通员工" << endl; 
	cout << "2.经理" << endl; 
	cout << "3.老板" << endl; 
    cin >> newdId;
	
	Worker* worker = NULL;
	switch(newdId)
	{
	case 1:
		worker = new Employee(newID,newname,newdId); 
	    break;
	case 2:
		worker = new Manager(newID,newname,newdId);  
	    break;
	case 3:
		worker = new Boss(newID,newname,newdId); 
	    break;	
	}
	this->m_EmpArray[Index] = worker;
	this->save();//保存文件 
	cout << "修改成功！" << endl; 
	system("pause");
    system("cls");//清屏
}


void WorkerManager::FindEmp()
{
    if(m_FileIsEmp)
	{
		cout << "文件不存在或者记录为空！" << endl;
		system("pause");
	    system("cls");//清屏
		return; 
	}
	
	cout << "请输入查找的方式：" << endl;
	cout << "1.按照职工编号查找" << endl;
	cout << "2.按照职工姓名查找" << endl;
	int temp = 0;
    cin >> temp;
	if(temp == 1)
	{
		cout << "请输入要查找的编号：" << endl;
		int FID = 0;
		cin >> FID;
		int ret = IsExist(FID);
		if(ret != -1)
		{
			cout << "查找成功！该职工的信息如下：" << endl;
			this->m_EmpArray[ret]->showInof();//显示 
		}
		else
		{
			cout << "查无此人！" << endl; 
		}
    }
    else if(temp == 2)
    {
    	cout << "请输入要查找的姓名：" << endl;
    	bool flag = false; //是否按姓名查到的标志 
    	string Fname;
    	cin >> Fname;
    	for(int i=0; i<this->m_EmpNum; i++)
    	{
    		if(this->m_EmpArray[i]->m_Name == Fname)
    		{
    			cout << "查找成功！该职工的信息如下：" << endl;
    			this->m_EmpArray[i]->showInof();//显示 
    			flag = true; //也可以用return，但不要忘记清屏 
			}
		}
		if(!flag)
		{
			cout << "查无此人！" << endl; 
		}
	}
	else
	{
		cout << "查找方式输入错误！" << endl;
	}
	
	system("pause");
    system("cls");//清屏
}

void Swap(Worker* &a, Worker* &b)
{
	Worker* temp = a;
	a = b;
	b = temp;
}

void WorkerManager::SortEmp()
{
    if(m_FileIsEmp)
	{
		cout << "文件不存在或者记录为空！" << endl;
		system("pause");
	    system("cls");//清屏
		return; 
	}
	
	cout << "请选择排序方式：" << endl;
	cout << "1.按照职工编号升序" << endl; 
	cout << "2.按照职工编号降序" << endl; 
	int temp = 0;
	cin >> temp;
	
	//冒泡排序
	for(int i=0; i<this->m_EmpNum; i++)
	{
		for(int j=1; j<this->m_EmpNum-i; j++)
		{
			if(temp == 1)//升序 
			{
				if(m_EmpArray[j-1]->m_ID > m_EmpArray[j]->m_ID)
				{
					Swap(m_EmpArray[j-1],m_EmpArray[j]);
				}
			}
			else//降序 
			{
				if(m_EmpArray[j-1]->m_ID < m_EmpArray[j]->m_ID)
				{
					Swap(m_EmpArray[j-1],m_EmpArray[j]);
				}
			} 
		}
	}
	cout << "排序成功！" << endl; 
	this->save();//保存文件 
	this->ShowEmp();//显示排序后的职工信息，ShowEmp里面有清屏，这里就不用了 
}


void WorkerManager::CleanFile()
{
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if(select == 1)
	{
		ofstream ofs;
		ofs.open("empFile.text",ios::trunc); //删除后重新创建
		ofs.close(); 
		
		if(this->m_EmpArray != NULL)
		{
			for(int i=0; i<this->m_EmpNum; i++)
			{
				if(this->m_EmpArray[i] != NULL)
				{
				    delete this->m_EmpArray[i];	 //释放每个职工对象 
				    this->m_EmpArray[i] = NULL;
				}
			}
			
			delete[] this->m_EmpArray;//释放职工数组 
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmp = true;
		}
		cout << "清空成功！" << endl;
		system("pause");
	    system("cls");//清屏
	} 
	else
	{
	    system("pause");
	    system("cls");//清屏
	}
}



