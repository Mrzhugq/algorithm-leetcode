#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

int weight[]={1,3,4};
int value[]={15,20,30};
int bigweight=4;//背包最大容量

int Knapsack()
{
	int Size=sizeof(weight)/sizeof(weight[0]);//物品个数 
	int dp[3][5]={0};
	//初始化dp数组 后序初始化 
	for(int j=bigweight; j>=weight[0]; j--)
	{
		dp[0][j]=dp[0][j-weight[0]]+value[0];
	}
	//        0  1  2  3  4  -> 背包下标	      
	//1    0  0  15 15 15 15
    //3    1  0  0  0  0  0
    //4    2  0  0  0  0  0
    //     |
	//  物品下标 
    
    
    for(int i=1;i<Size;i++)//遍历物品 
    {
    	for(int j=0;j<=bigweight;j++)//正序遍历背包容量 
    	{
    		if(j<weight[i])
    		{
    			dp[i][j]=dp[i-1][j];
			}
    		else
    		{
    			dp[i][j]=fmax(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
			}
		}
	}
	
	
//	//打印
//	for(int i=0;i<Size;i++)
//    {
//		for(int j=0;j<=bigweight;j++)
//		{
//			printf("%d ",dp[i][j]);
//		}
//		printf("\n");
//	} 
	return dp[Size-1][bigweight]; 
}
	
int main()
{
	printf("%d ",Knapsack());
}
