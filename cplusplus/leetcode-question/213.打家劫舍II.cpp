#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int robRange(int* nums, int numsSize,int start,int end)//198一样思路
{
    if(start==end) return nums[start];

    int* dp=(int*)malloc(sizeof(int)*numsSize);
    dp[start]=nums[start];
    dp[start+1]=fmax(nums[start],nums[start+1]);
    for(int i=start+2; i<=end; i++)
    {
        dp[i]=fmax(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[end];
}


int rob(int* nums, int numsSize)
{
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
    int retsult1=robRange(nums,numsSize,0,numsSize-2);//不考虑房屋numsSize - 1
    int retsult2=robRange(nums,numsSize,1,numsSize-1);//不考虑房屋0

    return fmax(retsult1,retsult2);
}

int main()
{
	int arr[]={1,2,3,1};
	printf("%d ",rob(arr,4));
}