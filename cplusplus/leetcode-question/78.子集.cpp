// �����������ʱ�򣬰����нڵ㶼��¼����������Ҫ����Ӽ�����
// ��ȡ�Ӽ����⣬����Ҫ�κμ�֦����Ϊ�Ӽ�����Ҫ������������

class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex)
    {
        result.push_back(path);//�ռ�?����Ҫ������?��ӵ���?�������©��??
        if(startIndex >= nums.size())//����Ӳ��Ӷ��У���Ϊ��startIndex>=nums/size()����forѭ��Ҳ����ȥ
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

