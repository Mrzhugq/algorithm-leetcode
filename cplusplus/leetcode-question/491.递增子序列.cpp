
//1.����ȥ�أ����ַ�ΧС���������� 
//-------------------------------------------------------------------------------- 
//��������������У��ǲ��ܶ�ԭ�����������ģ�����������鶼�ǵ�����������(������ʹ���ԭ�ȵ�˳����)
//���Բ���ʹ����ǰ��ȥ���߼�

class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex)
    {
        if(path.size() >= 2) //�����еĳ��������� 2
        {
            result.push_back(path); //ע����?��Ҫ��return����ΪҪȡ���ϵ����нڵ�
        }
        if(startIndex >= nums.size()) //�Ӳ��Ӷ���
        {
            return;
        }

        int used[201] = {0}; //�����е�������Χ�� [-100,100] ��ÿ�㶼�����´���һ��used
        for(int i=startIndex; i<nums.size(); i++)
        {
            //used[nums[i]+100] == 1  ����nums[i]�ڱ�����ֹ�
            if( (!path.empty() && nums[i]<path.back()) || used[nums[i]+100] == 1)
            {
                continue;
            }
            used[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i+1); //�����ظ�ѡȡ -> i+1
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);  //nums����������ȥ��(ͬ��ȥ��)
        return result;
    }
};

//2.unordered_set ȥ�� 
//---------------------------------------------------------------------------- 

//������?��?���У��ǲ��ܶ�ԭ���龭?����ģ�����������鶼��?��?������(������ʹ���ԭ�ȵ�˳����)
//���Բ���ʹ����ǰ��ȥ���߼�(used)

//unordered_set<int> uset; �Ǽ�¼����Ԫ���Ƿ��ظ�ʹ?���µ�?��
//uset�������¶��壨��գ�������Ҫ֪��usetֻ���𱾲㣡
class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex)
    {
        if(path.size() >= 2) //�����еĳ��������� 2
        {
            result.push_back(path); //ע����?��Ҫ��return����ΪҪȡ���ϵ����нڵ�
        }
        if(startIndex >= nums.size()) //�Ӳ��Ӷ���
        {
            return;
        }

        unordered_set<int> uset; //ͬ��ȥ��
        for(int i=startIndex; i<nums.size(); i++)
        {
            //uset.find(nums[i])==uset.end() , nums[i] �ڱ���û�г��ֹ�
            //nums[i]<path.back() ����ÿ��ѡ������Ҫ�ȵ�ǰpath�����һ�����ִ���ߵ��� -> ����
            if( (!path.empty() && nums[i]<path.back()) || uset.find(nums[i])!=uset.end())
            {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i+1); //�����ظ�ѡȡ -> i+1
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);  //nums����������ȥ��(ͬ��ȥ��)
        return result;
    }
};
