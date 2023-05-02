int removeElement(int* nums, int numsSize, int val)
{
    int left=0;
    int right=0;
    while(right<numsSize)
    {
        if(right<numsSize && nums[right]!=val)
        {
            nums[left]=nums[right];
            left++;
        }
        right++;
    }
    return left;
}
