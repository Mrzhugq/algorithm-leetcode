//本题用哈希不合适，去重细节很多，不好处理
//适合用双指针

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //双指针需要排序
        
        //a + b + c == 0  ->  nums[i] + nums[left] + nums[right] == 0
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0)  return res; //排序后第一个数大于0，后面就不可找出三数之和为0
            if(i > 0 && nums[i-1] == nums[i]) //对a进行去重，这里去重不能这样写nums[i] == nums[i+1]会漏情况
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    res.push_back(vector<int> {nums[i], nums[left], nums[right]} ); //找到一组
                    //双指针去重逻辑应该放在找到一个三元组以后
                    while(left < right && nums[left] == nums[left+1]) //对b进行去重
                    {
                        left++;
                    }
                    while(left < right && nums[right-1] == nums[right]) //对c进行去重
                    {
                        right--;
                    }
                    left++; //找到答案，双指针同时收缩
                    right--;
                }
            }
        }
        return res;
    }
};
