#include<stdio.h>
#include<stdlib.h> 

int uniquePaths(int m, int n)
{
    int **dp=(int**)malloc(sizeof(int*)*m);
    for (int i = 0; i < m; i++)
    {
        dp[i]=(int*)malloc(sizeof(int)*n);
    }
    //dp[i][j] ����ʾ�ӣ�0 ��0����������(i, j) ��dp[i][j]����ͬ��·��
    //dp�����ʼ������(0, 0)��λ�õ�(i, 0)��·��ֻ��1������ôdp[0][j]Ҳͬ��
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
