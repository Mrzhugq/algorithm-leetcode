
//按照区间右端点排序，从左向右记录非交叉区间的个数，
//最后用区间总数减非交叉区间的个数就是需要移除区间的个数了。

//贪心 
//局部最优：优先选右边界最小的区间，所以从左向右遍历，留给下一个区间的空间大一点，从而尽量避免交叉
//全局最优：选取最多的非交叉区间

class Solution 
{
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp); //按照区间右端点排序，让重复多的靠右边
        
        int count = 1;                 //记录非交叉区间的个数
        int end = intervals[0][1];     //所有区间最小的右边界(记录区间分割点)
        for(int i = 1; i < intervals.size(); i++)
        {
            if(end <= intervals[i][0]) //统计非重复的区间数，
            {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};
