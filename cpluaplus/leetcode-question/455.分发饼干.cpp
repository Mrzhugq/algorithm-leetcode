//如果大尺寸饼干可以满足大胃口，还可以满足小胃口，优先喂饱大胃口
//局部最优 -> 整体最优（贪心）

// s = [1,2,3]  饼干
// g = [1,2]    胃口
// 
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        //从后往前遍历，大饼干给大胃口  ->  其实不用两层for循环，那样是麻烦了
        int index = s.size() - 1; //饼干最大尺寸
        int res = 0;
        for(int i = g.size() - 1; i >= 0; i--) //倒序遍历胃口
        {
            if(index >= 0 && s[index] >= g[i])
            {
                index--;
                res++;
            }
        }
        return res;
    }
};
