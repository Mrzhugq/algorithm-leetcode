#include<iostream>
using namespace std;

//多态案例2-制作饮品
 
class AbstractDrinking 
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//导入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0; 
	
	//制作饮品 
	void MakeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
    } 
};

//制作咖啡
class MakeCoffee : public AbstractDrinking
{
public:
    //煮水
	virtual void Boil()  //virtual这里的virtual可加可不加 
	{
		cout << "煮自来水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//导入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	} 
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
    } 
}; 

//制作咖啡
class MakeTea : public AbstractDrinking
{
public:
    //煮水
	virtual void Boil()
	{
		cout << "煮矿泉水水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//导入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	} 
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入柠檬和枸杞" << endl;
    } 
}; 

//制作函数 
void DoWork(AbstractDrinking* abc)
{
	abc->MakeDrink();
	delete abc;
}
 
int main()
{
	//制作咖啡
	DoWork(new MakeCoffee);
	
	cout << "---------------------" << endl;
	//制作茶叶
	DoWork(new MakeTea);
	 
	return 0;
}

