#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int coinChange(int* coins, int coinsSize, int amount)
{
    int *dp=(int*)malloc(sizeof(int)*(amount+1));
    //dp[j]必须初始化为一个最大的数
    //否则就会在min(dp[j - coins[i]] + 1, dp[j])比较的过程中被初始值覆盖。
    for(int i=0; i<amount+1; i++)
    {
        dp[i]=INT_MAX;
    }
    dp[0]=0;

    for(int i=0; i<coinsSize; i++)//物品
    {
        for(int j=coins[i]; j<=amount; j++)//背包
        {
            //最少的硬币个数
            if(dp[j-coins[i]] != INT_MAX)
            {
                dp[j]=fmin(dp[j],dp[j-coins[i]]+1);
            }
        }
    }
    if(dp[amount] == INT_MAX) return -1;
    return dp[amount];
}

int main()
{
	int arr[]={1,2,5};
	printf("%d ",coinChange(arr,3,11));
}