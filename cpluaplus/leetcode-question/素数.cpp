#include<stdio.h>

void ss()
{
	int i,j,num=0;
	for(i=100;i<=200;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				break;
			}
		}
		if(j==i)
		{
			num++;
			printf("%d ",i);
			if(num%10==0)
			{
				printf("\n");
			}
		}
	}
}
int main()
{
	ss();
} 
