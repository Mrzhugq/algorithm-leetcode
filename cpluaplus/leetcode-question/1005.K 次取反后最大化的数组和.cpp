
//贪心，局部最优：让绝对值大的负数变为正数，当前数值达到最大
//      整体最优：整个数组和达到最大
//时间 :O(NlogN)
class Solution 
{
public:
    static bool cmp(int a, int b) //注意按绝对值排降序！！
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), cmp);
        //注意： 按绝对值的大小排降 ->  这样可以优先把绝对值大的负数变为正数

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0 && k > 0) //把num里负数变为正数(k个)
            {
                nums[i] *= -1;
                k--;
            }
        }

        //如果走到这里k不为零，那么nums这时里面都是正数。
        //如果k为奇数就把最小的正数变为负数就行了，如果k为偶数nums不用变(两个负号就是正了)
        if(k % 2 != 0)
        {
            nums[nums.size() - 1] *= -1;
        }
        //求和
        int res = 0;
        for(int num : nums)
        {
            res += num;
        }
        return res;
    }
};
