#include<stdio.h>
#include<stdlib.h>
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int **dp=(int**)malloc(sizeof(int*)*obstacleGridSize);
    for (int i = 0; i < obstacleGridSize; i++)
    {
        dp[i]=(int*)calloc(sizeof(int),(*obstacleGridColSize));
    }
    //初始化dp数组
    for (int i = 0; i < obstacleGridSize; i++) 
    {
        if(obstacleGrid[i][0]==1)
        break;
        dp[i][0] = 1;
    }
    for (int j = 0; j < *obstacleGridColSize; j++)
    {
        if(obstacleGrid[0][j]==1)
        break;
        dp[0][j] = 1;
    }
    //计算dp数组
    for (int i = 1; i < obstacleGridSize; i++)
    {
        for (int j = 1; j < *obstacleGridColSize; j++)
        {
            if(obstacleGrid[i][j]==1) continue;//遇到障碍保持原状0不变
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        
    }
    return dp[obstacleGridSize-1][*obstacleGridColSize-1];
}
int main()
{
	int **arr=(int**)malloc(sizeof(int*)*3);
    for (int i = 0; i < 3; i++)
    {
        arr[i]=(int*)calloc(sizeof(int),3);
    }
	arr[1][1]=1;
	int col=3;
	printf("%d ",uniquePathsWithObstacles(arr,3,&col));
} 
