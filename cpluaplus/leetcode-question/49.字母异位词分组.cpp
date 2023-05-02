

//------------------------------------------------------------------------------------1.
//排序，按照排序后的字符串作为key值 （排序后异位词一定相同）
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for(string& str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }

        for(auto& it : mp)
        {
            res.emplace_back(it.second);
        }
        // for(auto it = mp.begin(); it != mp.end(); it++)
        // {
        //     res.emplace_back(it->second);
        // }
        return res;
    }
};

//-----------------------------------------------------------------------------2.
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
        vector<vector<string>> res;
        unordered_map <double,vector<string>> m;
        double a[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        for(string& s : strs)
        {
            double t = 1;
            for(char c : s)
                t *= a[c - 'a'];
            m[t].push_back(s);          //t为单词对应的质数乘积，m[t]则为该单词的异位词构成的vector
        }
        for(auto& n : m)                //n为键和值组成的pair
            res.push_back(n.second);
        return res;
    }
};
