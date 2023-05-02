#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<math.h>

int findMaxForm(char ** strs, int strsSize, int m, int n)
{
    //可以看成一个二维背包
    //dp[i][j]：最多有i个0和j个1的strs的最??集的??为dp[i][j]
    int **dp=(int**)malloc(sizeof(int*)*(m+1));
    for(int i=0;i<=m;i++)
    {
        dp[i]=(int*)calloc(sizeof(int),(n+1));
    }

    //遍历strs[p]，统计 0 1 个数
    for(int p=0; p<strsSize; p++)
    {
        int Zerosum=0;
        int Oncsum=0;
        for(int q=0; q<strlen(strs[p]); q++)
        {
            if(strs[p][q]=='0')
            {
                Zerosum++;
            }
            else
            {
                Oncsum++;
            }
        }
        //计算dp数组,需要倒序遍历二维背包
        for(int i=m; i>=Zerosum; i--)
        {
            for(int j=n; j>=Oncsum; j--)
            {
                dp[i][j]=fmax(dp[i][j],dp[i-Zerosum][j-Oncsum]+1);
            }
        }
    }
    return dp[m][n];
}

int main()
{
	char **arr=(char**)malloc(sizeof(char*)*6);
	arr[0]="10";
	arr[1]="0001";
	arr[2]="11101";
	arr[3]="1";
	arr[4]="0";
	
	printf("%d ",findMaxForm(arr,5,3,3)); 
	return 0;
}

