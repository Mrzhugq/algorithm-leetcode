//当需要固定规律一段一段去处理字符串的时候，要想想在for循环的表达式上做做文章

class Solution 
{
public:
    string reverseStr(string s, int k) 
    {
        for(int i=0; i<s.size(); i += (2 * k)) //i每次一定2*k就可以找到每次要反转开始的区间了
        {
            if(i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k); // [ 区间 )
            }
            else //剩余字符少于k个，则将剩余字符全部反转
            {
                reverse(s.begin() + i, s.begin() + s.size());
                //reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
