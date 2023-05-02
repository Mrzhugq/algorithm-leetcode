#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int lastStoneWeightII(int* stones, int stonesSize)
{
    int sum=0;
    for(int i=0;i<stonesSize;i++)
    {
        sum+=stones[i];
    }
    int target=sum/2;//target为背包容量，stones[i]是重量和价值
    int *dp=(int*)calloc(sizeof(int),(target+1));
    for(int i=0;i<stonesSize;i++)
    {
        for(int j=target;j>=stones[i];j--)
        {
            dp[j]=fmax(dp[j],dp[j-stones[i]]+stones[i]);
        }
    }
    //在计算target的时候，target = sum / 2 因为是向下取整
    //所以sum - dp[target] 一定是大于等于dp[target]的。
    return (sum-dp[target]) - dp[target];
}

int main()
{
	int arr[]={2,7,4,1,8,1};
	printf("%d ",lastStoneWeightII(arr,6));
} 
