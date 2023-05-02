#include<stdio.h>
#include<stdlib.h>

int combinationSum4(int* nums, int numsSize, int target)
{
    int *dp=(int*)calloc(sizeof(int),(target+1));
    dp[0]=1;
    //求组合数先遍历物品后遍历背包
    //求排列数恰恰相反，先遍历背包后遍历物品

    //本题完全背包要正序遍历背包
    for(int i=1; i<=target; i++)
    {
        for(int j=0; j<numsSize; j++)
        {
            if(i-nums[j] >= 0 && dp[i] < INT_MAX-dp[i-nums[j]])
            {
                dp[i]+=dp[i-nums[j]];
            }
        }
    }
    return dp[target];
}

//测试用例有超过两个树相加超过int的数据，所以需要在if后加上dp[i] < INT_MAX - dp[i - num]。
//一般不用加这个

int main()
{
	int arr[]={1,2,3};
	printf("%d ",combinationSum4(arr,3,4));
}