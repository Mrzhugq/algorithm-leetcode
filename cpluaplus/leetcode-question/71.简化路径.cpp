class Solution 
{
public:
    string simplifyPath(string path) 
    {
        path += '/';         //    "/a/b/.." ��Щ·��������/��β����β��һ��/����֤���һ������if(path[i] == '/')
        stack<string> st;
        string dir;
        for(int i=0; i<path.size(); i++)
        {
            if(path[i] == '/')
            {
                //��һ��·��
                if(dir == ".." && !st.empty())
                {
                    st.pop();
                }
                //��һ�� '/' �� ��һ�� '/'
                else if(dir != ".." && dir != "." && !dir.empty())
                {
                    st.push(dir);
                }
                dir.clear();  
            }
            else
            {
                dir += path[i];
            }
        }
        //����ջ
        string res;
        while(!st.empty())
        {
            string s = st.top();
            st.pop();
            res = "/" + s + res; //����
        }
        if(res.empty())
        {
            res = "/";
        }
        return res;
    }
};



