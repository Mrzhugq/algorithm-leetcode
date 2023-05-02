// 遍历这个树的时候，把所有节点都记录下来，就是要求的子集集合
// 求取子集问题，不需要任何剪枝！因为子集就是要遍历整棵树。

class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex)
    {
        result.push_back(path);//收集?集，要放在终?添加的上?，否则会漏掉??
        if(startIndex >= nums.size())//这个加不加都行，因为当startIndex>=nums/size()下面for循环也进不去
        {
            return;
        }
        for(int i = startIndex; i<nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

