//�ɰ����ظ����ֵ����� nums
//������ȥ��
// used[i - 1] == true��˵��ͬ?��?nums[i - 1]ʹ?��
// used[i - 1] == false��˵��ͬ?����nums[i - 1]ʹ?��
// �������ͬ?����nums[i - 1]ʹ?����ֱ������

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
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==false) //ȥ�أ�ȥ���ظ���
            {
                continue;
            }
            if(used[i] == true) //path?�Ѿ���¼��Ԫ�أ�ֱ������
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

