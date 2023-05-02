#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int lastStoneWeightII(int* stones, int stonesSize)
{
    int sum=0;
    for(int i=0;i<stonesSize;i++)
    {
        sum+=stones[i];
    }
    int target=sum/2;//targetΪ����������stones[i]�������ͼ�ֵ
    int *dp=(int*)calloc(sizeof(int),(target+1));
    for(int i=0;i<stonesSize;i++)
    {
        for(int j=target;j>=stones[i];j--)
        {
            dp[j]=fmax(dp[j],dp[j-stones[i]]+stones[i]);
        }
    }
    //�ڼ���target��ʱ��target = sum / 2 ��Ϊ������ȡ��
    //����sum - dp[target] һ���Ǵ��ڵ���dp[target]�ġ�
    return (sum-dp[target]) - dp[target];
}

int main()
{
	int arr[]={2,7,4,1,8,1};
	printf("%d ",lastStoneWeightII(arr,6));
} 
