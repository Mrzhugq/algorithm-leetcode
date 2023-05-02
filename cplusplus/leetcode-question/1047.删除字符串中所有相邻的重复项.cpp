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

        //����ջ������ַ���ȡ��������Ϊջ���Ƚ������ȡ���ַ�����Ҫ��תһ���ַ�����
        string res = "";  //��ʼ��Ϊ�գ���ֹջΪ��
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
