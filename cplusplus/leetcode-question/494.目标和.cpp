#include<stdio.h>
#include<stdlib.h>

int findTargetSumWays(int* nums, int numsSize, int target)
{
    //���Խ�dp[i][j]����Ϊ������nums�� 0 - i ��Ԫ�ؽ��мӼ����Եõ� j �ķ�������
    //�����Ĺؼ�����nums[i]��ѡ�벻ѡ������nums[i]�Ǽӻ��Ǽ�
    int sum=0;
    for(int i=0;i<numsSize;i++)
    {
        sum+=nums[i];
    }
    if(abs(target) > sum) return 0;//����ֵ��Χ������sum�ľ���ֵ��Χ���޷��õ�
    //dp[numsSize][2*sum+1]  ���������±귶Χ[-sum,sum]�±겻��Ϊ��������+sum -> [0,2*sum]
    int **dp=(int**)malloc(sizeof(int*)*(numsSize));
    for(int i=0;i<numsSize;i++)
    {
        dp[i]=(int*)calloc(sizeof(int),(2*sum+1));
    }
    //��ʼ�� ��nums[0]==0ʱ -> dp[0][0]==2
    dp[0][-nums[0] + sum]++;
    dp[0][nums[0] + sum]++;

    for(int i=1; i<numsSize; i++)
    {
        for(int j=-sum; j<=sum; j++)
        {
            if(j+nums[i] > sum)
            {
                //���ϵ�ǰ��������sum����������ֻ�ܼ�ȥ��ǰ����
                dp[i][j+sum] = dp[i-1][j-nums[i]+sum]+0;
            }
            else if(j-nums[i] < -sum)
            {
                //��ȥ��ǰ��С��-sum����������ֻ�ܼ��ϵ�ǰ����
                dp[i][j+sum] = dp[i-1][j+nums[i]+sum]+0;
            }
            else
            {
                //�Ӽ�����
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
