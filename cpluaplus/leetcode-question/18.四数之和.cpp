//类似三数之和，不适合哈希，适合利用双指针法
//三数之和是利用一层for循环固定nums[i]，然后循环内有left和right下标作为双指针，找到nums[i]+nums[left]+nums[right]==0
//所以四数之和的利用两层for循环固定nums[k] + nums[i]，然后。。。

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //双指针需要排序
        for(int k=0; k<nums.size(); k++)
        {
            //这样剪枝是错误的，这里不像三数之和target是个固定的0，而这里target是可变的(注意细节)
            //如果target是-11,排序后nums[]=[-5,-4,-3,-2,1,3,3,5],这时nums[0]>target，return显然不正确，有组合(-5,-4,-3,1)
            // if(nums[k] > target)//排序后第一个大于target直接结束
            // {
            //     return res;
            // }
            if(k > 0 && nums[k-1] == nums[k]) //注意
            {
                continue;
            }
            for(int i=k+1; i<nums.size(); i++)
            {
                if(i > (k + 1) && nums[i-1] == nums[i]) //注意 
                {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;  //nums:[1000000000, 1000000000, 1000000000, 1000000000] target:0
                while(left < right)           //35，39行加个long long防止溢出
                {
                    if((long long)nums[k] + nums[i] + nums[left] + nums[right] > target) //注意这里是target不是0了
                    {
                        right--;
                    }
                    else if((long long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back(vector<int> {nums[k], nums[i], nums[left], nums[right]});
                        //双指针去重逻辑应该放在找到一个四元组之后
                        while(left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while(left < right && nums[right - 1] == nums[right])
                        {
                            right--;
                        }
                        //找到答案，双指针同时收缩
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
