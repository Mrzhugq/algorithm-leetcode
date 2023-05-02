class MyQueue 
{
public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() 
    {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        stIn.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        //本题pop要求是返回栈顶元素并且删除栈顶元素

        //如果stOut为空，就从stIn中导入进来数据，然后删除stOut栈顶元素就行了
        //如果都为空，说明模拟的队列为空
        if(stOut.empty())
        {
            while(!stIn.empty())
            {
                int temp = stIn.top();
                stOut.push(temp);
                stIn.pop();
            }
        }
        //stOut不为空中间删除stOut栈顶元素就行
        int res = stOut.top();
        stOut.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() 
    {
        //peek要求是返回栈顶元素，但不删除栈顶元素
        int res = this->pop();
        stOut.push(res); //复用pop并把删除是元素再次加入
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
