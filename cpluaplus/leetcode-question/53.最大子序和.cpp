//贪心
//局部最优：
//当连续和为负数的时候立即放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素和只会越来越少

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int count = 0;
        int result = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            count += nums[i];
            if(count > result) //更新结果
            {
                result = count;
            }
            if(count < 0) //加上当前数和为负数了，就归零，从下一个重新累加(要求是连续的所以重新累加)
            {
                count = 0;
            }
        }
        return result;
    }
};

//----------------------------------------------------------------------------
int maxSubArray(int* nums, int numsSize)
{
    //dp[i]：包括下标i之前的最大连续子序列和为dp[i]。
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    int ret = dp[0];
    for(int i=1; i<numsSize; i++)
    {
        dp[i] = fmax(nums[i],dp[i-1]+nums[i]);
        if(dp[i] > ret)
        {
            ret = dp[i]; 
        }
    }
    return ret; //注意不是返回dp[numSize-1]
}

