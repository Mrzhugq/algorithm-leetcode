

class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int record[26] = {0};
        for(int i=0; i<magazine.size(); i++)
        {
            record[magazine[i] - 'a']++;
        }
        for(int i=0; i<ransomNote.size(); i++)
        {
            if(record[ransomNote[i] - 'a'] < 1) //< 1代表信中需要的字符杂志中一次也没出现，直接false
            {
                return false;
            }
            record[ransomNote[i] - 'a']--; //相当于用过了，次数减一
        }
        return true;
    }
};
