#include<iostream>
using namespace std;

//��̬����2-������Ʒ
 
class AbstractDrinking 
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0; 
	
	//������Ʒ 
	void MakeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
    } 
};

//��������
class MakeCoffee : public AbstractDrinking
{
public:
    //��ˮ
	virtual void Boil()  //virtual�����virtual�ɼӿɲ��� 
	{
		cout << "������ˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	} 
	//���븨��
	virtual void PutSomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
    } 
}; 

//��������
class MakeTea : public AbstractDrinking
{
public:
    //��ˮ
	virtual void Boil()
	{
		cout << "���Ȫˮˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	} 
	//���븨��
	virtual void PutSomething()
	{
		cout << "�������ʺ����" << endl;
    } 
}; 

//�������� 
void DoWork(AbstractDrinking* abc)
{
	abc->MakeDrink();
	delete abc;
}
 
int main()
{
	//��������
	DoWork(new MakeCoffee);
	
	cout << "---------------------" << endl;
	//������Ҷ
	DoWork(new MakeTea);
	 
	return 0;
}

