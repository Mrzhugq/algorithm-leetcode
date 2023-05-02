
class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool> &used)
    {
        result.push_back(path);
        if(startIndex >= nums.size())//加不加都行
        {
            return;
        }
        for(int i=startIndex; i<nums.size(); i++)
        {
            // used[i - 1] == true，说明同一树支nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            //我们要对同一树层使用过的元素进行跳过
            if(i>0 && nums[i] == nums[i-1] && used[i-1] == false)
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i+1, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); //去重需要排序
        backtracking(nums, 0, used);
        return result;
    }
};
