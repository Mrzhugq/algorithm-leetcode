#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

int weight[]={1,3,4};
int value[]={15,20,30};
int bigweight=4;//背包最大容量

int Knapsack()
{
	int Size=sizeof(weight)/sizeof(weight[0]);//物品个数 
	int *dp=(int*)calloc(sizeof(int),(bigweight+1));//创建dp数组并且归零 
	
	for(int i=0;i<Size;i++)
	{
		for(int j=bigweight;j>=weight[i];j--)
		{
			dp[j]=fmax(dp[j],dp[j-weight[i]]+value[i]);
		}
	}
	return dp[bigweight]; 
} 

int main()
{
	printf("%d ",Knapsack());
}
