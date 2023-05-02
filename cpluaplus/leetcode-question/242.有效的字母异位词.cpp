
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        int reord[26] = {0}; //26��Ӣ����ĸ����Ŀ˵ֻ��Сд��
        for(int i=0; i<s.size(); i++)
        {
            reord[s[i] - 'a']++;
        }
        for(int i=0; i<t.size(); i++)
        {
            reord[t[i] - 'a']--;
        }
        //�������record����ȫΪ�㣬��true
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
