class Solution 
{
public:
    string removeDuplicates(string s) 
    {
        stack<char> st; 
        for(int i=0; i<s.size(); i++)
        {
            if(st.empty() || st.top() != s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }

        //最后把栈里面的字符串取出来（因为栈是先进后出，取出字符串后还要反转一下字符串）
        string res = "";  //初始化为空，防止栈为空
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
