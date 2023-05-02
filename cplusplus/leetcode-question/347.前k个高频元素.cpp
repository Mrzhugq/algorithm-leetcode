//时间复杂度O(n*logK)

class Solution 
{
public:
    //如果建立大堆，每次弹出最大频率数，再次建n-1个数的堆，而建小堆只需要维护k个数的堆就行了
    //pair比较仿函数，按频率建小堆(这里的小堆是left > right， 而srot里面的从小到大是left < right，正好相反)
    class mycomparison
    {
    public:
        bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        //< 数值, 频率 >
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        //优先队列  priority_queue< type, container, function >   默认是大堆（后两个参数可以省略，本题不可以）
        //type : 数据类型  container : 实现优先队列的底层容器  function : 元素之间的比较方式
        priority_queue< pair<int,int>, vector<pair<int,int>>, mycomparison >  pri_que;
        for(auto it = mp.begin(); it!=mp.end(); it++)
        {
            pri_que.push(*it);
            if(pri_que.size() > k) //保证堆的大小一直是k,维护k个数据就行
            {
                pri_que.pop();
            }
        }

        //因为建的小堆，每次弹出都前k个最高频率里的 最小频率
        vector<int> res(k, 0);
        for(int i=k-1; i>=0; i--)
        {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};
