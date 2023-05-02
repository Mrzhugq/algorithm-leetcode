#include<stdio.h>
#include<stdlib.h>

int numTrees(int n)
{
    int *dp=(int*)calloc(sizeof(int),(n+1));//每个归零，后面加一起有意义
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i]+=dp[j-1]*dp[i-j];
            //自己写一下i=3时，j=1，2，3
            //dp[3] = dp[1-1]*dp[3-1]+dp[2-1]*dp[3-2]+dp[3-1]*dp[3-3];
            //dp[3] = dp[0]*dp[2]+dp[1]*dp[1]+dp[2]*dp[0];
        }
    }
    return dp[n];
}
int main()
{
	printf("%d ",numTrees(3));
} 
