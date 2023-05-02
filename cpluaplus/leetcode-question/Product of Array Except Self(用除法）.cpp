#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *productExceptSelf(int *nums,int numsSize,int *returnSize)
{
	*returnSize=numsSize;
	int *retsult=(int*)malloc(sizeof(int)*numsSize);
	
	int zeros=0;//统计0的个数 
	for(int i=0;i<numsSize;i++)
	{
		if(nums[i]==0)
		{
			zeros++;
		}
	}
	
	if(zeros==1)//数组中有一个零的情况 
	{
		int total=1;
		for(int i=0;i<numsSize;i++)
		{
			if(nums[i]!=0)
			{
				total=total*nums[i];
			}
		}
		
		for(int i=0;i<numsSize;i++)
		{
			if(nums[i]!=0)
			{
				retsult[i]=0;
			}
			else
			{
				retsult[i]=total;
			}
		}
	} 
	else if(zeros>=2)//两个以上零 
	{
		for(int i=0;i<numsSize;i++)
		{
			retsult[i]=0;
		} 
	}
	else//没有零的情况 
	{
		int total=1;
		for(int j=0;j<numsSize;j++)
		{
			total*=nums[j];
		}
		for(int i=0;i<numsSize;i++)
		{
			retsult[i]=total/nums[i];
		}
	}
	return retsult;
}
int main()
{
	int arr[]={1,2,3,0,4};
	int returnSize=0;
	int *ret=productExceptSelf(arr,5,&returnSize);
	for(int i=0;i<returnSize;i++)
	{
		printf("%d ",ret[i]);
	}
} 
