
class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        int hash[27] = {0};
        //先统计每个字符出现的最远下标
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }

        vector<int> res;
        int left = 0, right= 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, hash[s[i] - 'a']); //找字符出现的最远边界
            if(i == right)
            {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};
