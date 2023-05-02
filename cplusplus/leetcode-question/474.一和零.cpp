#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<math.h>

int findMaxForm(char ** strs, int strsSize, int m, int n)
{
    //���Կ���һ����ά����
    //dp[i][j]�������i��0��j��1��strs����??����??Ϊdp[i][j]
    int **dp=(int**)malloc(sizeof(int*)*(m+1));
    for(int i=0;i<=m;i++)
    {
        dp[i]=(int*)calloc(sizeof(int),(n+1));
    }

    //����strs[p]��ͳ�� 0 1 ����
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
        //����dp����,��Ҫ���������ά����
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

