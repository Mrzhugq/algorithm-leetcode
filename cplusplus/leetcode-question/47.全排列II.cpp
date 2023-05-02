//可包含重复数字的序列 nums
//可排序去重
// used[i - 1] == true，说明同?树?nums[i - 1]使?过
// used[i - 1] == false，说明同?树层nums[i - 1]使?过
// 本题如果同?树层nums[i - 1]使?过则直接跳过

class Solution 
{
private:
    vector<vector<int>> reault;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            reault.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==false) //去重（去答案重复）
            {
                continue;
            }
            if(used[i] == true) //path?已经收录的元素，直接跳过
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        reault.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return reault;
    }
};

