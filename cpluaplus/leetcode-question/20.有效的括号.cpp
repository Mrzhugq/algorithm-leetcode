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
            //st.empty() ����ջΪ�ջ�û�������ַ������������Ŷ��ˣ�
            //st.top != s[i] ������һ��ƥ�䲻��,ֱ�ӷ���false
            else if(st.empty() || st.top() != s[i])
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        return st.empty(); //�������ַ��������ջΪ�վ�����ȫƥ����
    }
};
