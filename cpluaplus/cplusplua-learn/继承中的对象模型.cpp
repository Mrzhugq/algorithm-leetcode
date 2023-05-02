#include<iostream> 
using namespace std;


//继承中的对象模型
//问题：从父类继承过来的成员，那些属于子类对象中？

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
    //父类中的所有 非静态成员属性 都会被子类继承下去
	//父类中的私有成员属性 是被编译器隐藏了，因此访问不到，但是它确实被继承下去了(仍然存在) 
    cout << "Son1占用字节数：" << sizeof(s1) << endl;//16 
	return 0;
}

