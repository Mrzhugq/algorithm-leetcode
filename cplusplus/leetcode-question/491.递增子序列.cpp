
//1.数组去重，数字范围小尽量用数组 
//-------------------------------------------------------------------------------- 
//本题求递增子序列，是不能对原数组进行排序的，排完序的数组都是递增子序列了(排完序就打乱原先的顺序了)
//所以不能使用以前的去重逻辑

class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex)
    {
        if(path.size() >= 2) //子序列的长度至少是 2
        {
            result.push_back(path); //注意这?不要加return，因为要取树上的所有节点
        }
        if(startIndex >= nums.size()) //加不加都行
        {
            return;
        }

        int used[201] = {0}; //数组中的整数范围是 [-100,100] ，每层都会重新创建一个used
        for(int i=startIndex; i<nums.size(); i++)
        {
            //used[nums[i]+100] == 1  代表nums[i]在本层出现过
            if( (!path.empty() && nums[i]<path.back()) || used[nums[i]+100] == 1)
            {
                continue;
            }
            used[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i+1); //不能重复选取 -> i+1
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);  //nums不能排序来去重(同层去重)
        return result;
    }
};

//2.unordered_set 去重 
//---------------------------------------------------------------------------- 

//本题求?增?序列，是不能对原数组经?排序的，排完序的数组都是?增?序列了(排完序就打乱原先的顺序了)
//所以不能使用以前的去重逻辑(used)

//unordered_set<int> uset; 是记录本层元素是否重复使?，新的?层
//uset都会重新定义（清空），所以要知道uset只负责本层！
class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex)
    {
        if(path.size() >= 2) //子序列的长度至少是 2
        {
            result.push_back(path); //注意这?不要加return，因为要取树上的所有节点
        }
        if(startIndex >= nums.size()) //加不加都行
        {
            return;
        }

        unordered_set<int> uset; //同层去重
        for(int i=startIndex; i<nums.size(); i++)
        {
            //uset.find(nums[i])==uset.end() , nums[i] 在本层没有出现过
            //nums[i]<path.back() 代表每次选的数字要比当前path的最后一个数字大或者等于 -> 递增
            if( (!path.empty() && nums[i]<path.back()) || uset.find(nums[i])!=uset.end())
            {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i+1); //不能重复选取 -> i+1
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);  //nums不能排序来去重(同层去重)
        return result;
    }
};
