//左旋转可以后反转整体，而右旋转可以先翻转整体（好像没区别。哈哈）

class Solution 
{
public:
    string reverseLeftWords(string s, int n) 
    {
        
        reverse(s.begin(), s.begin() + n);  //[ )
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

//abcdefg
//ba gfedc
//cdefgab

