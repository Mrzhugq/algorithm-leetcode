//不含重复数字的数组 nums 
//排列问题需要一个used数组，标记已经选择的元素
//used数组，其实就是记录此时path都有哪些元素使过了，一个排列里一个元素只能使1次。
class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        //排列问题每次都要从头开始搜索，因此不用startIndex
        //used数组，标记已经选择的元素（本题每个数字只能选一次）
        for(int i=0; i<nums.size(); i++)
        {
            if(used[i] == true)  continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
