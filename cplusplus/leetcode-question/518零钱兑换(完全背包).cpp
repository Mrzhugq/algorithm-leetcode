#include<stdio.h>
#include<stdlib.h>

int change(int amount, int* coins, int coinsSize)
{
    int *dp=(int*)calloc(sizeof(int),(amount+1));
    dp[0]=1;
    for(int i=0; i<coinsSize; i++)
    {
        for(int j=coins[i]; j<=amount; j++)
        {
            dp[j]+=dp[j-coins[i]];
        }
        // for(int k=0;k<=amount;k++)
        // {
        //     printf("%d ",dp[k]);
        // }
        // printf("\n");
    }
    return dp[amount];
}

int main()
{
	int arr[]={1,2,5};
	printf("%d ",change(5,arr,3));
}