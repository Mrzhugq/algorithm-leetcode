//时间复杂度O(N) ( 本题也可以暴力两个for循环，当然O(N^2) )


class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int result = INT32_MAX; //存最小的子序列长度
        int sum = 0; //窗口数字总和
        int i = 0;   //滑动窗口起始位置
        int subLength = 0;
        for(int j=0; j<nums.size(); j++) //滑动窗口结束位置  (窗口[i, j])
        {
            sum += nums[j];
            while(sum >= target) //每次满足条件都缩小左区间，看有没有更小的区间
            {
                subLength = j - i + 1; //每次子序列长度
                result = result < subLength ? result : subLength;
                sum -= nums[i];
                i++;
            }
        }
        //如果result没有被赋值，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};
