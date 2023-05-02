#include<stdio.h>
#include<math.h>

int run(int n)
{
	int a[32]={0};
	int i=31,t;
	while(n)
	{
		a[i--]+=n%2;
		n/=2;
	}
	for(i=0;i<32;i+=2)
	{
		t=a[i];
		a[i]=a[i+1];
		a[i+1]=t;
		n=n+a[i+1]*pow(2,31-i-1)+a[i]*pow(2,31-i);
	}
	return n;
}


//int run(int n)
//{
//	int a=0x55555555;
//	int b=0xAAAAAAAA;
//	a=a&n;
//	b=b&n;
//	n=(a<<1)+(b>>1);
//	return n;
//} 


int main()
{
	int ret=run(6);
	printf("%d ",ret);
} 






