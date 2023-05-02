//贪心
//局部最优：当出现重叠时，一起射，所用弓箭最少 全局最优：把所有所有气球射爆所用弓箭最少

//可先排序尽可能让气球重复，起始按照起始位置或者终止位置排序都行，只是遍历顺序不同
//如果气球重复了，重叠气球中右边边界的最小值之间的区间需要一个弓箭
class Solution 
{
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.size() == 0)  return 0;
        sort(points.begin(), points.end(), cmp); 
        //按照起始位置排序，尽可能让气球重复
        
        int res = 1; //至少1
        for (int i = 1; i < points.size(); i++)
        {
            if(points[i - 1][1] < points[i][0]) //气球i-1和i不挨着 ,注意是< ,不是<=
            {
                res++;
            }
            else //不挨着
            {
                points[i][1] = min(points[i - 1][1], points[i][1]); 
                //更新气球的最小右边界
            }
        }
        return res;
    }
};



/*
[[10,16],[2,8],[1,6],[7,12]]
排序后如下图：
   1-------6
      2--------8
              7---------12
                     10--------16    
*/



