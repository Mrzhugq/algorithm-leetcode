#include<stdio.h>
#include<stdlib.h>
#include<search.h>

////1.
//int cmp(const void* a,const void* b)
//{
//	return *(int*)b-*(int*)a;
//}
//int lastStoneWeight(int *stones,int stonesSize)
//{
//	if(stonesSize<2)   return stones[0];
//	
//	while(1)
//	{
//		qsort(stones,stonesSize,sizeof(int),cmp);
//		int y=stones[0];
//		int x=stones[1];
//		if(x==0)
//		{
//			return y;
//		}
//		if(x!=y)
//		{
//			stones[0]=y-x;
//		}
//	}
//	return 0;
//} 




//2.
int extracMax(int *count,int upperBound)//取最大值函数 
{
	for(int i=upperBound;i>=0;i--)
	{
		if(count[i]!=0)
		{
			count[i]--;
			return i;
		}
	}
    return 0;
}
void insert(int *count,int value)//插入y-x函数 
{
	count[value]++;
} 
int lastStoneWeight(int *stones,int stonesSize)
{
	int count[1001]={0};
	for(int i=0;i<stonesSize;i++)
	{
		count[stones[i]]++;
	}
	int upperBound=1000;
	while(true)
	{
		int y=extracMax(count,upperBound);
		int x=extracMax(count,upperBound);
		if(x==0)
		{
			return y;
		}
		if(x!=y)
		{
			insert(count,y-x);
		}
		upperBound=y; //这样每次不用从1000个开始查找了 
	}
	return 0; 
}



int main()
{
	int arr[]={2,7,4,1,8,1};
	int ret=lastStoneWeight(arr,6);
	printf("%d\n",ret);
	return 0;
	
} 

