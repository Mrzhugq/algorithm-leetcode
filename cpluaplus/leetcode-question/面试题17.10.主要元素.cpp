#include<stdio.h>

int majorityElement(int* nums, int numsSize)
{
    int candidate = -1;
    int count = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(count == 0)
        {
            candidate = nums[i];//count==0时，任何人都能当选候选人，更新candidate
        }

        if(candidate == nums[i])
        {
            count++;//如果第i个，和当前候选人一样，票数加1
        }
        else
        {
            count--;//如果第i个，和当前候选人不一样，票数就要抵消掉
        }
    }

    //再遍历一遍看 最终候选人 是否出现了大于numSize/2次
    int sum = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == candidate)
        {
            sum++;
        }
    }

    return sum*2 > numsSize ? candidate : -1;
}

int main()
{
	int arr[] = {1,2,5,9,5,9,5,5,5};
	printf("%d ",majorityElement(arr,9));
}