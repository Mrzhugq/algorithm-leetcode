#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int DP(int *arr,int Size,int target)//1代表能拼出target, 0代表不能 
{
	//例如 Size=6;
	//     target=9; 
	
//数组   0 1 2 3 4 5 6 7 8 9
//3   0  1 0 0 1 0 0 0 0 0 0        
//34  1  1                    
//4   2  1                      
//12  3  1                         
//5   4  1                        
//2   5  1                 1 
	int **dp=(int**)malloc(sizeof(int*)*(Size));
	for(int i=0;i<Size;i++)
	{
		dp[i]=(int*)malloc(sizeof(int)*(target+1));
	}
	//初始化
	for(int j=0;j<=target;j++)//第一行 
	{
		if(j==arr[0])
		{
		    dp[0][j]=1; 
		} 
		else
		{
			dp[0][j]=0;
		} 
	}
	for(int i=0;i<Size;i++)//第一列 
	{
		dp[i][0]=1;
	}
	//计算数组中间的 
	for(int i=1;i<Size;i++)
	{
		for(int j=1;j<=target;j++)
		{
			if(arr[i] > j)
			{
				dp[i][j] = dp[i-1][j];
			}
		    else
		    {
		    	dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
				//这里是找和为target的数是否存在,所以有一个满足就可以 
			}
		}
	}
//	for(int i=1;i<Size;i++)
//	{
//		for(int j=1;j<=target;j++)
//		{
//			printf("%d ",dp[i][j]);
//		}
//		printf("\n");
//	}
	return dp[Size-1][target];
}

int main()
{
	int arr[6]={3,34,4,12,5,2};
	int target=9;
	printf("结果：%d ",DP(arr,6,target));
}
                    


//递推公式
//if(arr[i] > j)   ->   (第i个不能选) dp[i][j]=dp[i-1][j];
//else                                dp[i][j]=( dp[i-1][j], dp[i-1][j-arr[i]] );
