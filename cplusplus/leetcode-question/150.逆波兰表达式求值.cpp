//逆波兰表达式类似二叉树中的后序遍历

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
                if(tokens[i] == "+") st.push(num2 + num1); //注意是(num2 + num1) 不是(num1 + num2)
                if(tokens[i] == "-") st.push(num2 - num1);
                if(tokens[i] == "/") st.push(num2 / num1);
                if(tokens[i] == "*") st.push(num2 * num1);
            }
            else
            {
                //atoi 函数是把const char* 类型字符串转化为整形，如果超过整形报错，string类型不能用
                //stoi 函数是把string类型字符串转化为整形，如果超出整形不会报错，输出INT_MAX
                st.push( stoi(tokens[i]) );
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};
