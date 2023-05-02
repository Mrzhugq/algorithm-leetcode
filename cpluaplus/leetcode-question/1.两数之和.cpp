//--------------------------------------------------------------------------------
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]==target-nums[j])
            {
                int* ret=(int*)malloc(sizeof(int)*2);
                ret[0]=i;
                ret[1]=j;
                *returnSize=2;
                return ret;
            }
        }
    }
    *returnSize=0;
    return NULL;
} 



//--------------------------------------------------------------------------------- 
//key不要求有序，而且不仅要数值还要下标，所以用unordered_map

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //<数值，下标>
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            auto iter = mp.find(target - nums[i]);
            if(iter != mp.end())
            {
                return {iter->second, i};
            }
            mp.insert( pair<int, int>(nums[i], i) );
        }  
        return {};
    }
};
