#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

int weight[]={1,3,4};
int value[]={15,20,30};
int bigweight=4;//�����������

int Knapsack()
{
	int Size=sizeof(weight)/sizeof(weight[0]);//��Ʒ���� 
	int *dp=(int*)calloc(sizeof(int),(bigweight+1));//����dp���鲢�ҹ��� 
	
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
