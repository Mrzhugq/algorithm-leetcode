#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


/* 
在数组中找到两个数，使得它们的和等于目标值，可以首先固定第一个数，然后寻找第二个数，第二个数等于目标值减去第一个数的差。利用数组的有序性质，可以通过二分查找的方法寻找第二个数。为了避免重复寻找，在寻找第二个数时，只在第一个数的右侧寻找
*/


int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int *res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    for(int i=0; i<numbersSize; i++)
    {
        int ret = numbers[i];
        int left = i + 1;
        int right = numbersSize - 1;
        int falg = 0;
        while(left <= right)
        {
            int mid = (right - left)/2 + left;
            if(ret + numbers[mid] == target)
            {
                res[0] = i + 1;
                res[1] = mid + 1;
                falg = 1;
                break;
            }
            else if(ret + numbers[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if(falg)
        {
            break;
        }
    }
    return res;
}

int main()
{
	int arr[] = {2,7,11,15};
	int returnSize = 0;
	int *ret = twoSum(arr, 4, 9, &returnSize);
	for(int i=0; i<returnSize; i++)
	{
		printf("%d ", ret[i]);
	}
 } 
