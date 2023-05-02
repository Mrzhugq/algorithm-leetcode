#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


/* 
���������ҵ���������ʹ�����ǵĺ͵���Ŀ��ֵ���������ȹ̶���һ������Ȼ��Ѱ�ҵڶ��������ڶ���������Ŀ��ֵ��ȥ��һ�����Ĳ����������������ʣ�����ͨ�����ֲ��ҵķ���Ѱ�ҵڶ�������Ϊ�˱����ظ�Ѱ�ң���Ѱ�ҵڶ�����ʱ��ֻ�ڵ�һ�������Ҳ�Ѱ��
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
