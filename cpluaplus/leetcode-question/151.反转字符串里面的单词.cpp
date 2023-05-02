//思路：先去冗余空格，整体反转，然后单个反转单词，空间O(1)
//注意，去除冗余空格时不要用erase，使用了时间就是O(N^2)了，因为数组erase就是把后面覆盖到前面的过程
//      可以使用双指针+resize

class Solution 
{
private:
    void reverse(string &s, int start, int end) //反转区间[start, end]
    {
        for(int i=start,j=end; i<j; i++,j--)
        {
            swap(s[i], s[j]);
        }
    }
    void removeExtraSpaces(string &s) //利用双指针去除冗余空格(不用erase)
    {
        int fastIndex = 0;
        int slowIndex = 0;
        while(s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') //去重前面空格
        {
            fastIndex++;
        }
        //去除中间多余空格 和 后面多余的空格（最后面空格去除不完，会留下一个空格）
        for( ; fastIndex < s.size(); fastIndex++)
        {
            if(fastIndex - 1 > 0 && s[fastIndex-1] == s[fastIndex] && s[fastIndex] == ' ')
            {
                continue;
            }
            else
            {
                s[slowIndex] = s[fastIndex];
                ++slowIndex;
            }
        }
        //去除后面一个空格(只需判断一下最后一个字符是否是空格)
        if(slowIndex - 1 > 0 && s[slowIndex - 1] == ' ')
        {
            s.resize(slowIndex - 1);
        }
        else
        {
            s.resize(slowIndex);
        }

    }
public:
    string reverseWords(string s)
    {
        removeExtraSpaces(s);         //去除冗余空格
        reverse(s, 0, s.size() - 1);  //整体反转

        for(int i=0; i<s.size(); i++) //单个单词区间[i,j-1]
        {
            int j = i;
            while(j < s.size() && s[j] != ' ')//查找单词间的空格
            {
                j++;
            }
            reverse(s, i, j - 1);
            i = j;
        }

        // int start = 0, end = 0;       //反转单个单词的起始和结束位置
        // for( ; end < s.size(); end++)
        // {
        //     if(s[end] == ' ')
        //     {
        //         reverse(s, start, end-1);
        //         start = end + 1;
        //     }
        // }
        // reverse(s, start, s.size() - 1); //反转最后一个漏掉的单词
        return s;
    }
};


