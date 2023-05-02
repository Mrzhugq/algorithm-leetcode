#include<iostream>
#include<iomanip>

using namespace std; 

void test1()
{
	double s = 12.34518;
	cout << s << endl;   //cout默认只输出6位有效数字
	
	//输出7位
	cout << setprecision(7) << s << endl;
	cout << setprecision(10) << s << endl;  //不会补零 
	
	//设置输出小数位 （四舍五入） 
	cout << fixed << setprecision(2) << s << endl; 
	cout << fixed << setprecision(10) << s << endl;  //少了补零 
}
 
int main()
{
	test1();
	return 0;
}

