//1.
#include<stdio.h>
int main()
{
	int x,y,z;
	for(x=0;x<=20;x++)
	{
		for(y=0;y<=33;y++)
		{
			z=100-x-y;
			if(z%3==0 && (5*x+3*y+z/3)==100)
			{
				printf("�����У�%d�� ĸ���У�%d�� С���У�%d��\n",x,y,z);
			}
		}
	}
 } 
 

 
#include<stdio.h>
//int main()
//{
//	int x,y,z;
//	for(x=0;x<=20;x++)
//	{
//		for(y=0;y<=33;y++)
//		{
//			z=100-x-y;
//			if(z%5==0 && (5*x+3*y+z/5)==100)
//			{
//				printf("�����У�%d�� ĸ���У�%d�� С���У�%d��\n",x,y,z);
//			}
//		}
//	}
// } 
