#include<stdio.h>
#include<stdlib.h>
//1.≈≈–Ú∑® 
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int missingNumber(int* nums, int numsSize)
{
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]!=i)
        {
            return i;
        }
    }
    return numsSize;
}

////2.“ÏªÚ∑®
//int missingNumber(int* nums, int numsSize)
//{
//
//    //0 1 2  ...  n 
//    //0 1    ...  n   (»± ß2)
//    
//    int ret=numsSize;
//    for(int i=0;i<numsSize;i++)
//    {
//        ret^=nums[i]^i;
//    }
//    return ret;
//} 

int main()
{
	int arr[]={0,3,1};
	int ret=missingNumber(arr,3);
	printf("%d ",ret);
}
