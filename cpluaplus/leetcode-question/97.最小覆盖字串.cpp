//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"


class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        string res;
        int cnt = 0;
        int i = 0;
        unordered_map<char, int> hs,ht; 

        for(int k=0; k<t.size(); k++)
        {
            ht[ t[k] ]++;
        }
        for(int j=0; j<s.size(); j++)
        {
            hs[ s[j] ]++;
            if( hs[ s[j] ] <= ht[ s[j] ] )  //如果第一次加入ABC，cnt就加一 （例一为例子）
            {
                cnt++;
            }
            while( hs[ s[i] ] > ht[ s[i] ] ) //缩小左边界
            {
                hs[ s[i] ]--;
                i++;
            }
            if(cnt == t.size())
            {
                if(res.empty() || j-i+1 < res.size()) //窗口[i, j]
                {
                    res = s.substr(i, j-i+1);
                    //cout << res << endl;
                }
            }
        }
        return res;    
    }
};
