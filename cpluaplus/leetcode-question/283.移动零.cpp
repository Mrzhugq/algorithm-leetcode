void moveZeroes(int* nums, int numsSize)
{
    
    int left=0;
    int right=0;
    while(right<numsSize)
    {
        if(right<numsSize && nums[right]!=0)
        {
            nums[left]=nums[right];
            left++;
        }
        right++;
    }
    for(int i=left;i<numsSize;i++)
    {
        nums[i]=0;
    }
}
