#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//                                                         i
// lefts[i]    := (nums[0] * nums[1] * ...* nums[i-1])
// rights[i]   := (nums[i+1] * nums[i+2] *...* nums[numsSize-1]) 

// retsult[i]  := lefts[i] * rights[i]

int *productExceptSelf(int *nums,int numsSize,int *returnSize)
{
	*returnSize=numsSize;
	int *retsult=(int*)malloc(sizeof(int)*numsSize);
	
	retsult[numsSize-1]=1;
	for(int i=numsSize-2;i>=0;i--)//sumSize-2开始，防止i+1越界 （从后面数开始防止除法 ） 
	{
		retsult[i]=retsult[i+1] * nums[i+1];
	}
	
	int left=1;
	for(int i=0;i<numsSize;i++)
	{
		retsult[i]=left * retsult[i];
		left=left * nums[i];
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
