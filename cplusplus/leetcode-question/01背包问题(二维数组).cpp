#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

int weight[]={1,3,4};
int value[]={15,20,30};
int bigweight=4;//�����������

int Knapsack()
{
	int Size=sizeof(weight)/sizeof(weight[0]);//��Ʒ���� 
	int dp[3][5]={0};
	//��ʼ��dp���� �����ʼ�� 
	for(int j=bigweight; j>=weight[0]; j--)
	{
		dp[0][j]=dp[0][j-weight[0]]+value[0];
	}
	//        0  1  2  3  4  -> �����±�	      
	//1    0  0  15 15 15 15
    //3    1  0  0  0  0  0
    //4    2  0  0  0  0  0
    //     |
	//  ��Ʒ�±� 
    
    
    for(int i=1;i<Size;i++)//������Ʒ 
    {
    	for(int j=0;j<=bigweight;j++)//��������������� 
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
	
	
//	//��ӡ
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
