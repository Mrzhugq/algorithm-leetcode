class Solution 
{
public:
    string simplifyPath(string path) 
    {
        path += '/';         //    "/a/b/.." 有些路径不是以/结尾，结尾加一个/，保证最后一定触发if(path[i] == '/')
        stack<string> st;
        string dir;
        for(int i=0; i<path.size(); i++)
        {
            if(path[i] == '/')
            {
                //上一级路径
                if(dir == ".." && !st.empty())
                {
                    st.pop();
                }
                //上一个 '/' 到 下一个 '/'
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
        //遍历栈
        string res;
        while(!st.empty())
        {
            string s = st.top();
            st.pop();
            res = "/" + s + res; //这句妙啊
        }
        if(res.empty())
        {
            res = "/";
        }
        return res;
    }
};



