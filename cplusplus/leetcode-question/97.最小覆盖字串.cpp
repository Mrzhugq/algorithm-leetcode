//���룺s = "ADOBECODEBANC", t = "ABC"
//�����"BANC"


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
            if( hs[ s[j] ] <= ht[ s[j] ] )  //�����һ�μ���ABC��cnt�ͼ�һ ����һΪ���ӣ�
            {
                cnt++;
            }
            while( hs[ s[i] ] > ht[ s[i] ] ) //��С��߽�
            {
                hs[ s[i] ]--;
                i++;
            }
            if(cnt == t.size())
            {
                if(res.empty() || j-i+1 < res.size()) //����[i, j]
                {
                    res = s.substr(i, j-i+1);
                    //cout << res << endl;
                }
            }
        }
        return res;    
    }
};
