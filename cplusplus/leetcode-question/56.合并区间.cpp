//贪心
//局部最优：排序后，每次合并都取最大的右边界，这样就可以合并更多的区间了
//整体最优：合并所有重叠区间(其实贪心就是常识，都知道取最大右边界)

class Solution 
{
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;
        if(intervals.size() == 0) return res;
        
        sort(intervals.begin(), intervals.end(), cmp); //按区间左边界排生序（其实按左右边界排序都行）
        int size = intervals.size();
        bool flag = false; //标记最后一个区间有没有合并 
        for(int i = 1; i < size; i++)
        {
            int start = intervals[i-1][0]; //初始化为i-1区间的左右边界
            int end = intervals[i -1][1];
            while(i < size && end >= intervals[i][0]) //合并区间，注意是while不是if，因为可能合并多个区间
            {
                end = max(end, intervals[i][1]); //要取最大值，可能一个区间包含另一个区间的情况
                if(i == size - 1) 
                {
                    flag = true;
                }
                i++; //记得i++，合并下一个区间
            }
            res.push_back( {start, end} );
        }
        if(flag == false) //最后一个区间如果没被合并特殊处理
        {
            res.push_back( {intervals[size - 1][0], intervals[size - 1][1]} );
        }
        return res;
    }
};
