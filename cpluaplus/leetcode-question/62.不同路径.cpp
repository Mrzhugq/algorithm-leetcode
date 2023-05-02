#include<stdio.h>
#include<stdlib.h> 

int uniquePaths(int m, int n)
{
    int **dp=(int**)malloc(sizeof(int*)*m);
    for (int i = 0; i < m; i++)
    {
        dp[i]=(int*)malloc(sizeof(int)*n);
    }
    //dp[i][j] ：表示从（0 ，0）出发，到(i, j) 有dp[i][j]条不同的路径
    //dp数组初始化，从(0, 0)的位置到(i, 0)的路径只有1条，那么dp[0][j]也同理
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
	printf("%d ",uniquePaths(3,7));
}
