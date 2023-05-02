/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize=2;
    int *ret=malloc(sizeof(int)*2);
    ret[0]=-1;
    ret[1]=-1;

    //找左边
    int left=0;
    int right=numsSize;
    while(left < right)
    {
        int mid=(right-left)/2+left;
        if(nums[mid]==target)
        {
            right=mid;
        }
        else if(nums[mid]>target)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    if(left==numsSize)//没找到，target比所有数都大，即没有找到目标值
    {
        return ret;
    }
    if(nums[left]==target)
    {
        ret[0]=left;
    }
    else//left==0，且target比所有数都小，即没有找到目标值
    {
        return ret;
    }

    //找右边
    left=0;
    right=numsSize;
    while(left < right)
    {
        int mid=(right-left)/2+left;
        if(nums[mid]==target)
        {
            left=mid+1;
        }
        else if(nums[mid]>target)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    if(left==0)
    {
        return ret;
    }
    if(nums[left-1]==target)
    {
        ret[1]=left-1;
    }
    else
    {
        return ret;
    }
    return ret;
}
