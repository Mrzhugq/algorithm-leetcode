#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int numSquares(int n)
{
    int *dp=(int*)malloc(sizeof(int)*(n+1));
    //dp[j]必须初始化为一个最大的数
    //否则就会在min(dp[j - coins[i]] + 1, dp[j])比较的过程中被初始值覆盖。
    for(int i=0; i<n+1; i++)
    {
        dp[i]=INT_MAX;
    }
    dp[0]=0;

    for(int i=1; i*i<=n; i++)  //1^2 ..i^2 物品
    {
        for(int j=i*i; j<=n; j++)
        {
            if(dp[j-i*i] != INT_MAX)
            dp[j]=fmin(dp[j],dp[j-i*i]+1);
        }
    }
    return dp[n];
}

int main()
{
	printf("%d ",numSquares(13));
}