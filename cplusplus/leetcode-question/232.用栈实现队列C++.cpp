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
        //����popҪ���Ƿ���ջ��Ԫ�ز���ɾ��ջ��Ԫ��

        //���stOutΪ�գ��ʹ�stIn�е���������ݣ�Ȼ��ɾ��stOutջ��Ԫ�ؾ�����
        //�����Ϊ�գ�˵��ģ��Ķ���Ϊ��
        if(stOut.empty())
        {
            while(!stIn.empty())
            {
                int temp = stIn.top();
                stOut.push(temp);
                stIn.pop();
            }
        }
        //stOut��Ϊ���м�ɾ��stOutջ��Ԫ�ؾ���
        int res = stOut.top();
        stOut.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() 
    {
        //peekҪ���Ƿ���ջ��Ԫ�أ�����ɾ��ջ��Ԫ��
        int res = this->pop();
        stOut.push(res); //����pop����ɾ����Ԫ���ٴμ���
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
