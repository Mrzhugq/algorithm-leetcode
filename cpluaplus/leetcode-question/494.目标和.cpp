#include<stdio.h>
#include<stdlib.h>

int findTargetSumWays(int* nums, int numsSize, int target)
{
    //可以将dp[i][j]定义为从数组nums中 0 - i 的元素进行加减可以得到 j 的方法数量
    //这道题的关键不是nums[i]的选与不选，而是nums[i]是加还是减
    int sum=0;
    for(int i=0;i<numsSize;i++)
    {
        sum+=nums[i];
    }
    if(abs(target) > sum) return 0;//绝对值范围超过了sum的绝对值范围则无法得到
    //dp[numsSize][2*sum+1]  数组列数下标范围[-sum,sum]下标不能为负数所以+sum -> [0,2*sum]
    int **dp=(int**)malloc(sizeof(int*)*(numsSize));
    for(int i=0;i<numsSize;i++)
    {
        dp[i]=(int*)calloc(sizeof(int),(2*sum+1));
    }
    //初始化 当nums[0]==0时 -> dp[0][0]==2
    dp[0][-nums[0] + sum]++;
    dp[0][nums[0] + sum]++;

    for(int i=1; i<numsSize; i++)
    {
        for(int j=-sum; j<=sum; j++)
        {
            if(j+nums[i] > sum)
            {
                //加上当前数大于了sum，不成立，只能减去当前的数
                dp[i][j+sum] = dp[i-1][j-nums[i]+sum]+0;
            }
            else if(j-nums[i] < -sum)
            {
                //减去当前数小于-sum，不成立，只能加上当前的数
                dp[i][j+sum] = dp[i-1][j+nums[i]+sum]+0;
            }
            else
            {
                //加减都行
                dp[i][j+sum] = dp[i-1][j-nums[i]+sum] + dp[i-1][j+nums[i]+sum];
            }
        }
    }
    return dp[numsSize-1][target+sum];
}


int main()
{
	int arr[]={1,1,1,1,1};
	printf("%d ",findTargetSumWays(arr,5,3));
	return 0;
}
