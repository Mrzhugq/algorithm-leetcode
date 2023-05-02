class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> res_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end()); //set自动去重

        for(int i=0; i<nums2.size(); i++)
        {
            if(nums_set.find(nums2[i]) != nums_set.end())
            {
                res_set.insert(nums2[i]);
            }
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};
