
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        int reord[26] = {0}; //26个英文字母（题目说只有小写）
        for(int i=0; i<s.size(); i++)
        {
            reord[s[i] - 'a']++;
        }
        for(int i=0; i<t.size(); i++)
        {
            reord[t[i] - 'a']--;
        }
        //如果数组record数组全为零，则true
        for(int i=0; i<26; i++)
        {
            if(reord[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
