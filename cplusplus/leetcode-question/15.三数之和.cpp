#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void* a, const void* b) 
{
    return *(int*)a - *(int*)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (nums == NULL || numsSize < 3) 
	{
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    //分配返回数组、返回数组的列数
    int** ret = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * numsSize *sizeof(int));

    for (int i = 0; i < numsSize; i++) 
	{
        // 当前数组大于0，表示后续没有三数之和为0，结束遍历
        if (nums[i] > 0) 
		{
            break;
        }
        //当前元素与上一次相等，跳过此次计算，去重
        if (i > 0 && nums[i] == nums[i - 1]) 
		{
            continue;
        }
        int left = i + 1, right = numsSize - 1;
        //开始查找三数之和为0
        while (left < right) 
		{
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) 
			{
                ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[left];
                ret[*returnSize][2] = nums[right];
                //返回数组当前行的列数为3 
                (*returnColumnSizes)[*returnSize] = 3;
                //返回数组的行数自加1
                (*returnSize)++;
                //对左右指针进行去重
                while (left < right && nums[left]  == nums[++left])
                {
                    ;
                }
                while (left < right && nums[right] == nums[--right])
                {
                    ;
                }
            } 
			else if (sum < 0)
			{
                left++;
            } 
			else 
			{
                right--;
            }
        }
    }
    return ret;
}
