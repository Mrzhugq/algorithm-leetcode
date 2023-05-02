#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n)
{
    int *dp=(int*)calloc(sizeof(int),(n+1));
    dp[0]=1;
    //求完全背包求排列数
    for(int i=1; i<=n; i++)//背包
    {
        for(int j=1; j<=2; j++)//商品 —> 最多可以爬2个台阶
        {
            if(i >= j)
            dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}

int main()
{
	printf("%d ",climbStairs(3));
}