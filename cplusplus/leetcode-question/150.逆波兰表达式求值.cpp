//�沨�����ʽ���ƶ������еĺ������

class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(num2 + num1); //ע����(num2 + num1) ����(num1 + num2)
                if(tokens[i] == "-") st.push(num2 - num1);
                if(tokens[i] == "/") st.push(num2 / num1);
                if(tokens[i] == "*") st.push(num2 * num1);
            }
            else
            {
                //atoi �����ǰ�const char* �����ַ���ת��Ϊ���Σ�����������α���string���Ͳ�����
                //stoi �����ǰ�string�����ַ���ת��Ϊ���Σ�����������β��ᱨ�����INT_MAX
                st.push( stoi(tokens[i]) );
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};
