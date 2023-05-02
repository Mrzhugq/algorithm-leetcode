//�������� ->  �ö�������浥���ݼ����ݣ���ͷ�������ֵ ( ʱ��O(N) )

class Solution 
{
private:
    class MyQueue
    {
    public:
        deque<int> que;//ģ�ⵥ������
        //��ÿ�ε���ʱ���Ƚϵ�ǰҪ��������ֵ�Ƿ���ڶ��г���Ԫ�ص���ֵ�������Ⱦ͵���
        void pop(int value)
        {
            if(!que.empty() && value == que.front())
            {
                que.pop_front();
            }
        }
        //���push����ֵ�������Ԫ����ֵ����ô�ͽ����к����ֵ������ֱ��push����ֵС�ڵ��ڶ������Ԫ�ص���ֵΪֹ
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
        res.push_back( que.front() ); //�ȼ�¼ǰ���������ֵ

        for(int i=k; i<nums.size(); i++)
        {
            que.pop(nums[i - k]); //���������Ƴ���ǰ��Ԫ��
            que.push(nums[i]);    //�������ڼ�������Ԫ��
            res.push_back( que.front() );
        }
        return res;
    }
};
