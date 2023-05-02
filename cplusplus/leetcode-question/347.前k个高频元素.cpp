//ʱ�临�Ӷ�O(n*logK)

class Solution 
{
public:
    //���������ѣ�ÿ�ε������Ƶ�������ٴν�n-1�����Ķѣ�����С��ֻ��Ҫά��k�����ĶѾ�����
    //pair�ȽϷº�������Ƶ�ʽ�С��(�����С����left > right�� ��srot����Ĵ�С������left < right�������෴)
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
        //< ��ֵ, Ƶ�� >
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        //���ȶ���  priority_queue< type, container, function >   Ĭ���Ǵ�ѣ���������������ʡ�ԣ����ⲻ���ԣ�
        //type : ��������  container : ʵ�����ȶ��еĵײ�����  function : Ԫ��֮��ıȽϷ�ʽ
        priority_queue< pair<int,int>, vector<pair<int,int>>, mycomparison >  pri_que;
        for(auto it = mp.begin(); it!=mp.end(); it++)
        {
            pri_que.push(*it);
            if(pri_que.size() > k) //��֤�ѵĴ�Сһֱ��k,ά��k�����ݾ���
            {
                pri_que.pop();
            }
        }

        //��Ϊ����С�ѣ�ÿ�ε�����ǰk�����Ƶ����� ��СƵ��
        vector<int> res(k, 0);
        for(int i=k-1; i>=0; i--)
        {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};
