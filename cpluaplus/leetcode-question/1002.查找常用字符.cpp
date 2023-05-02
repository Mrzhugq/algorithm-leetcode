//统计出搜索字符串里26个字符的出现的频率，然后取每个字符频率的最小值，最后转成输出格式就可以

class Solution 
{
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<string> res;
        int hash[26] = {0};
        for(int j=0; j<words[0].size(); j++)// 先用第一个字符串初始化hash
        {
            hash[words[0][j] - 'a']++;
        }

        int hashOtherStr[26] = {0};
        for(int i=1; i<words.size(); i++)
        {
            memset(hashOtherStr, 0, 26*sizeof(int)); //hashOtherStr每次都归零
            for(int j=0; j<words[i].size(); j++)
            {
                hashOtherStr[words[i][j] - 'a']++;
            }
            for(int k=0; k<26; k++)
            {
                hash[k] = min(hash[k], hashOtherStr[k]);
            }
        }
        //将频率转换为字符串
        for(int i=0; i<26; i++)
        {
            while(hash[i] != 0) //注意这里是while，可能有重复字符
            {
                string str(1, (char)i+'a');
                res.push_back(str);
                hash[i]--;
            }
        }
        return res;
    }
};
