
class Solution 
{
private:
    vector<string> reault;
    bool IsValid(string &s, int start, int end) //判断s中区间[start,end]是否合法
    {
        if(start > end) return false;
        if(s[start] == '0' && start != end) //第一个为0不合法
        {
            return false;
        }
        int sum = 0;
        for(int i=start; i<=end; i++)
        {
            if(s[i] < '0' || s[i] >'9') //有特殊字符不合法
            {
                return false;
            }
            sum = sum *10 + (s[i] - '0');
            if(sum > 255) //大于255不合法
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(string &s, int startIndex, int pointNum)
    {
        if(pointNum == 3) //有三个点代表切割成四段了，再判断一下最后一段是否合法，合法就加入result
        {
            if(IsValid(s, startIndex, s.size()-1))
            reault.push_back(s);
            return;
        }

        for(int i=startIndex; i<s.size(); i++)
        {
            //[startIndex, i] 就是每次切割的区间，类似131题
            if(IsValid(s, startIndex, i))
            {
                s.insert(i+1, 1, '.'); //再合法区间后面一位插入一个'.'
                //s.insert(s.begin() + i + 1 , '.');
                ++pointNum;   
                backtracking(s, i+2, pointNum);
                //i+2 一方面是因为是因为不能重复选取，另一方面因为插入了'.' , 需要跳过这个点
                s.erase(i+1, 1); //删除这个'.'
                //s.erase(s.begin() + i + 1);
                --pointNum;
            }
            else
            {
                //不符合就直接break，因为已经不合法了，后面就没必要再切割了
                //比如从当前起点startIndex开始切到i已经有两个前导0了，或者已经大于255了，没必要往后切了
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) 
    {
        reault.clear();
        if(s.size() < 4 || s.size() > 12) return reault;
        backtracking(s, 0, 0);
        return reault;
    }
};
