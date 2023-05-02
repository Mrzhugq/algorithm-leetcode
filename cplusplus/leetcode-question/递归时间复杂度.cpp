#include<stdio.h>
//�ݹ鸴�Ӷȣ� �ݹ�Ĵ��� * ÿ�εݹ��еĲ������� 

//1.ʱ�临�Ӷ�O(N)
int function1(int x, int n) 
{
    if (n == 0) return 1;
    return function1(x, n - 1) * x;
} 


//2.ʱ�临�Ӷ�O(N)
int function2(int x, int n) 
{
    if (n == 0) return 1;
    if (n % 2 == 1) 
	{
        return function2(x, n / 2) * function2(x, n / 2)*x;
    }
    return function2(x, n / 2) * function2(x, n / 2);
} 


//2.ʱ�临�Ӷ�O(logN) 
int function3(int x,int n)
{
	if(n==0) return 1;
	int temp=function3(x,n/2);
	if(n%2==1)
	{
		return temp*temp*x;
	}
	return temp*temp;
}


int main()
{
	int n,x;
	scanf("%d%d",&x,&n);
	printf("%d ",function3(x,n));
} 
