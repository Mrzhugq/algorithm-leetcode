#include<iostream>
#include<iomanip>

using namespace std; 

void test1()
{
	double s = 12.34518;
	cout << s << endl;   //coutĬ��ֻ���6λ��Ч����
	
	//���7λ
	cout << setprecision(7) << s << endl;
	cout << setprecision(10) << s << endl;  //���Ჹ�� 
	
	//�������С��λ ���������룩 
	cout << fixed << setprecision(2) << s << endl; 
	cout << fixed << setprecision(10) << s << endl;  //���˲��� 
}
 
int main()
{
	test1();
	return 0;
}

