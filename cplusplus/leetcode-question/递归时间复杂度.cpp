#include<stdio.h>
//递归复杂度： 递归的次数 * 每次递归中的操作次数 

//1.时间复杂度O(N)
int function1(int x, int n) 
{
    if (n == 0) return 1;
    return function1(x, n - 1) * x;
} 


//2.时间复杂度O(N)
int function2(int x, int n) 
{
    if (n == 0) return 1;
    if (n % 2 == 1) 
	{
        return function2(x, n / 2) * function2(x, n / 2)*x;
    }
    return function2(x, n / 2) * function2(x, n / 2);
} 


//2.时间复杂度O(logN) 
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
