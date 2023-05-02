//最长连续子序列（只能有两种数字）

class Solution 
{
public:
    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int, int> veg2cnt;
        int res = 0; 
        int i = 0; //滑动窗口左边界
        for(int j=0; j<fruits.size(); j++) //滑动窗口右边界
        {
            veg2cnt[ fruits[j] ]++;
            while(veg2cnt.size() > 2)
            {
                int cur = fruits[i];
                veg2cnt[cur]--;
                if(veg2cnt[cur] == 0)
                {
                    veg2cnt.erase(cur);
                }
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};
