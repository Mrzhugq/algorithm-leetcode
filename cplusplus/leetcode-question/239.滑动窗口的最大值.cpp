//单调队列 ->  让队列里面存单调递减数据，队头就是最大值 ( 时间O(N) )

class Solution 
{
private:
    class MyQueue
    {
    public:
        deque<int> que;//模拟单调队列
        //当每次弹出时，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等就弹出
        void pop(int value)
        {
            if(!que.empty() && value == que.front())
            {
                que.pop_front();
            }
        }
        //如果push的数值大于入口元素数值，那么就将队列后端数值弹出，直到push的数值小于等于队列入口元素的数值为止
        void push(int value)
        {
            while(!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front()
        {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        MyQueue que;
        vector<int> res;

        for(int i=0; i<k; i++) 
        {
            que.push(nums[i]);
        }
        res.push_back( que.front() ); //先记录前三个的最大值

        for(int i=k; i<nums.size(); i++)
        {
            que.pop(nums[i - k]); //滑动窗口移除最前面元素
            que.push(nums[i]);    //滑动窗口加入最后的元素
            res.push_back( que.front() );
        }
        return res;
    }
};
