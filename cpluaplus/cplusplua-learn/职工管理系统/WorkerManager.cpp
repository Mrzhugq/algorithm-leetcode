#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	//���������ʼ��m_FileIsEmp
	//1.�ļ�������
	ifstream ifs;
	ifs.open("empFile.text",ios::in);
	if(!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		this->m_FileIsEmp = true;      //��ʼ���ļ��Ƿ�Ϊ�� 
		this->m_EmpNum = 0;            //��ʼ������ 
	    this->m_EmpArray = NULL;       //��ʼ��ָ������ 
	    return;
	}
	
	//2.�ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch; //��Ϊeof()�������ʣ�Ҫ�ȶ�ȡһ��
	if(ifs.eof())
	{
        //cout << "�ļ�Ϊ�գ�" << endl;
		this->m_FileIsEmp = true;
		this->m_EmpNum = 0;
	    this->m_EmpArray = NULL;
	    ifs.close();
	    return;
	}
	
	//3.�ļ����ڣ����ݲ�Ϊ�� 
	int num = this->GetEmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_FileIsEmp = false;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker*[m_EmpNum];//������СΪһ��ʼ�ļ�������Ա������Worker*���� 
	this->init_Emp();                        //���ļ������Ա�����뵽���������� 
	
	
//	for(int i=0; i<this->m_EmpNum; i++)
//	{
//		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_ID
//		     << "\t������" << this->m_EmpArray[i]->m_Name
//			 << "\t���ű�ţ�" << this->m_EmpArray[i]->m_DeptID << endl; 
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
	cout << "-------0.�˳�����ϵͳ---------" << endl; 
	cout << "-------1.����ְ����Ϣ---------" << endl; 
	cout << "-------2.��ʾְ����Ϣ---------" << endl; 
	cout << "-------3.ɾ����ְְ��---------" << endl; 
	cout << "-------4.�޸�ְ����Ϣ---------" << endl; 
	cout << "-------5.����ְ����Ϣ---------" << endl; 
	cout << "-------6.���ձ������---------" << endl; 
	cout << "-------7.��������ĵ�---------" << endl; 
	cout << "------------------------------" << endl; 
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);  
}

void WorkerManager::AddEmp()
{
	int num = 0;
	cout << "������Ҫ���ְ��������" << endl; 
	cin >> num;
	if(num > 0)
	{
		//���������������С 
		int newSize = this->m_EmpNum + num;
		Worker** newspace = new Worker*[newSize];
		
		//���ԭ�������ݣ��Ͱѽ�ԭ���Ŀ������µĴ�ռ�����
		if(this->m_EmpArray != NULL)
		{
			for(int i=0; i<this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];  
			}
		}
		
		//���������
		for(int i=0; i<num; i++)
		{
			int Id;
			string name;
			int dId;
			cout << "�������" << i+1 << "����ְ�����: " << endl;
			cin >> Id;
			
			//��ֹ����ظ� 
			for(int i=0; i<this->m_EmpNum; i++)
			{
				if(this->m_EmpArray[i]->m_ID == Id)
				{
					cout << "����ظ������������룺" << endl;
					cin >> Id; 
				}
			}
			
			cout << "�������" << i+1 << "����ְ������: " << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			
			//����������Ա��������������
			newspace[this->m_EmpNum + i] = worker;
		} 
		
		//�ͷ�ԭ���Ŀռ�
		delete[] m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newspace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		
		cout << "�ɹ������" << num << "��ְ��! " << endl; 
		this->save();//�����ļ� 
		this->m_FileIsEmp = false;
    }
    
	else
	{
		cout << "��������" << endl; 
	} 
	
	system("pause");
	system("cls");//���� 
} 


void WorkerManager::save()
{
	ofstream ofs;
	ofs.open("empFile.text",ios::out); //д�ļ�
	//��ÿ��������д���ļ�
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
	//�ж��ļ��ǲ��ǿջ��߲����� 
	if(this->m_FileIsEmp)
	{
		cout << "�ļ�Ϊ�ջ��߼�¼Ϊ��!" << endl;
	}
	else
	{
		for(int i=0; i<this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInof();
		}
	}
	
	system("pause");
	system("cls");//���� 
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
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		system("pause");
	    system("cls");//����
		return; 
	}
	
	cout << "������Ҫɾ��ְ����ţ�" << endl;
	int DelID = 0;
	cin >> DelID;
	int Index = this->IsExist(DelID);
	if(Index == -1)
	{
		cout << "ɾ��ʧ�ܣ�û���ҵ��ñ�ż�¼��" << endl;
		system("pause");
	    system("cls");//����
		return;
	}
	
	for(int i=Index; i<this->m_EmpNum-1; i++)
	{
		this->m_EmpArray[i] = this->m_EmpArray[i+1];
	}
	this->m_EmpNum--; //������һ
	this->save();     //�����ļ�
	cout << "ɾ���ɹ���" << endl; 
	
	system("pause");
	system("cls");//����
}


void WorkerManager::ModEmp()
{
	if(m_FileIsEmp)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		system("pause");
	    system("cls");//����
		return; 
	}
	
	cout << "������Ҫ�޸�ְ����ţ�" << endl;
	int ModID = 0;
	cin >> ModID;
	int Index = this->IsExist(ModID);
	if(Index == -1)
	{
		cout << "���޴��ˣ�" << endl;
		system("pause");
	    system("cls");//����
		return;
	}
	
	delete this->m_EmpArray[Index]; //�ͷŵ��ɵ���Ϣ
	
	int newID;
	string newname;
	int newdId;
	cout << "���ҵ���" << ModID << "��ְ�����������µ�ְ����ţ�" << endl;
	cin >> newID;
	cout << "�������µ�������" << endl;
	cin >> newname;
	cout << "�������µĸ�λ��" << endl;
	cout << "1.��ͨԱ��" << endl; 
	cout << "2.����" << endl; 
	cout << "3.�ϰ�" << endl; 
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
	this->save();//�����ļ� 
	cout << "�޸ĳɹ���" << endl; 
	system("pause");
    system("cls");//����
}


void WorkerManager::FindEmp()
{
    if(m_FileIsEmp)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		system("pause");
	    system("cls");//����
		return; 
	}
	
	cout << "��������ҵķ�ʽ��" << endl;
	cout << "1.����ְ����Ų���" << endl;
	cout << "2.����ְ����������" << endl;
	int temp = 0;
    cin >> temp;
	if(temp == 1)
	{
		cout << "������Ҫ���ҵı�ţ�" << endl;
		int FID = 0;
		cin >> FID;
		int ret = IsExist(FID);
		if(ret != -1)
		{
			cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
			this->m_EmpArray[ret]->showInof();//��ʾ 
		}
		else
		{
			cout << "���޴��ˣ�" << endl; 
		}
    }
    else if(temp == 2)
    {
    	cout << "������Ҫ���ҵ�������" << endl;
    	bool flag = false; //�Ƿ������鵽�ı�־ 
    	string Fname;
    	cin >> Fname;
    	for(int i=0; i<this->m_EmpNum; i++)
    	{
    		if(this->m_EmpArray[i]->m_Name == Fname)
    		{
    			cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
    			this->m_EmpArray[i]->showInof();//��ʾ 
    			flag = true; //Ҳ������return������Ҫ�������� 
			}
		}
		if(!flag)
		{
			cout << "���޴��ˣ�" << endl; 
		}
	}
	else
	{
		cout << "���ҷ�ʽ�������" << endl;
	}
	
	system("pause");
    system("cls");//����
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
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		system("pause");
	    system("cls");//����
		return; 
	}
	
	cout << "��ѡ������ʽ��" << endl;
	cout << "1.����ְ���������" << endl; 
	cout << "2.����ְ����Ž���" << endl; 
	int temp = 0;
	cin >> temp;
	
	//ð������
	for(int i=0; i<this->m_EmpNum; i++)
	{
		for(int j=1; j<this->m_EmpNum-i; j++)
		{
			if(temp == 1)//���� 
			{
				if(m_EmpArray[j-1]->m_ID > m_EmpArray[j]->m_ID)
				{
					Swap(m_EmpArray[j-1],m_EmpArray[j]);
				}
			}
			else//���� 
			{
				if(m_EmpArray[j-1]->m_ID < m_EmpArray[j]->m_ID)
				{
					Swap(m_EmpArray[j-1],m_EmpArray[j]);
				}
			} 
		}
	}
	cout << "����ɹ���" << endl; 
	this->save();//�����ļ� 
	this->ShowEmp();//��ʾ������ְ����Ϣ��ShowEmp����������������Ͳ����� 
}


void WorkerManager::CleanFile()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if(select == 1)
	{
		ofstream ofs;
		ofs.open("empFile.text",ios::trunc); //ɾ�������´���
		ofs.close(); 
		
		if(this->m_EmpArray != NULL)
		{
			for(int i=0; i<this->m_EmpNum; i++)
			{
				if(this->m_EmpArray[i] != NULL)
				{
				    delete this->m_EmpArray[i];	 //�ͷ�ÿ��ְ������ 
				    this->m_EmpArray[i] = NULL;
				}
			}
			
			delete[] this->m_EmpArray;//�ͷ�ְ������ 
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmp = true;
		}
		cout << "��ճɹ���" << endl;
		system("pause");
	    system("cls");//����
	} 
	else
	{
	    system("pause");
	    system("cls");//����
	}
}



