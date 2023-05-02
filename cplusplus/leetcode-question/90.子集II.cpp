
class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool> &used)
    {
        result.push_back(path);
        if(startIndex >= nums.size())//�Ӳ��Ӷ���
        {
            return;
        }
        for(int i=startIndex; i<nums.size(); i++)
        {
            // used[i - 1] == true��˵��ͬһ��֧nums[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����nums[i - 1]ʹ�ù�
            //����Ҫ��ͬһ����ʹ�ù���Ԫ�ؽ�������
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
        sort(nums.begin(), nums.end()); //ȥ����Ҫ����
        backtracking(nums, 0, used);
        return result;
    }
};
