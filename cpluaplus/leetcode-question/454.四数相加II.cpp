//注意和三数之和，四数之和不一样，它们是一个数组（不适合用哈希），而本题是4个数组更简单点

class Solution 
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        //key是a+b，value是a+b出现的次数
        unordered_map<int, int> mp;
        for(int a : nums1)
        {
            for(int b : nums2)
            {
                mp[a+b]++;
            }
        }

        int count = 0; //记录a+b+c+d=0出现的次数
        for(int c : nums3)
        {
            for(int d : nums4)
            {
                if(mp.find(0 - (c + d)) != mp.end())
                {
                    count += mp[0 - (c + d)];
                }
            }
        }
        return count;
    }
};
