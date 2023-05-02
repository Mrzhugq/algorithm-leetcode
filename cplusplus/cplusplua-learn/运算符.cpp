#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	cout << (a == b) << endl; //()不要忘记 
	
	cout << !a << endl;
	
	cout << (a && b++) << endl;// &&无论怎样前后都要运算 
	cout << b << endl; 
	
	cout << (a || b++) << endl; // ||前面是真的话，后面就不用运算了
	cout << b << endl;
	 
} 


// ! 
// &&
// ||


