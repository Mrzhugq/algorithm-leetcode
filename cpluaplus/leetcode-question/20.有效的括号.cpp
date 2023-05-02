class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(')');
            }
            else if(s[i] == '[')
            {
                st.push(']');
            }
            else if(s[i] == '{')
            {
                st.push('}');
            }
            //st.empty() 代表栈为空还没遍历完字符串（即右括号多了）
            //st.top != s[i] 代表有一组匹配不上,直接返回false
            else if(st.empty() || st.top() != s[i])
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        return st.empty(); //遍历完字符串，如果栈为空就是完全匹配了
    }
};
