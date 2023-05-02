int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize==0)
    return 0;
    int left=1;
    int right=1;
    while(right<numsSize)
    {
        if(right<numsSize && nums[right]!=nums[right-1])
        {
            nums[left]=nums[right];
            left++;
        }
        right++;
    }
    return left;
}
