#include<stdio.h>
bool canJump(int* nums, int numsSize)
{
    int maxCanReach=0;//用来记录能走到最远右边的下标
    for(int i=0;i<numsSize;i++)
    {
        if(i<=maxCanReach)//能走到i位置
        {
            int CanReach=i+nums[i];//走到i 继续往后走
            if(CanReach>maxCanReach)//更新最大值
            {
                maxCanReach=CanReach;
            }
        }
    }
    return numsSize-1 <= maxCanReach;
}

int main()
{
//	int arr[]={3,2,1,0,4};
    int arr[]={2,3,1,1,4};
	printf("%d ",canJump(arr,5));
} 
