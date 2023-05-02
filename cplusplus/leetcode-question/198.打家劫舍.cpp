#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int rob(int* nums, int numsSize)
{
    if(numsSize<=1) return nums[0];

    int* dp=(int*)malloc(sizeof(int)*numsSize);
    dp[0]=nums[0];
    dp[1]=fmax(nums[0],nums[1]);
    for(int i=2;i<numsSize;i++)
    {
        dp[i]=fmax(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[numsSize-1];
}

int main()
{
	int arr[]={1,2,4,1,7,8,3};
	printf("%d ",rob(arr,7));
} 
