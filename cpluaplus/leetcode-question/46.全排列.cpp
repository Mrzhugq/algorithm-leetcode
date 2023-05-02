//�����ظ����ֵ����� nums 
//����������Ҫһ��used���飬����Ѿ�ѡ���Ԫ��
//used���飬��ʵ���Ǽ�¼��ʱpath������ЩԪ��ʹ���ˣ�һ��������һ��Ԫ��ֻ��ʹ1�Ρ�
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
        //��������ÿ�ζ�Ҫ��ͷ��ʼ��������˲���startIndex
        //used���飬����Ѿ�ѡ���Ԫ�أ�����ÿ������ֻ��ѡһ�Σ�
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
