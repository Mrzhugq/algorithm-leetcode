
//ֻ��һֻ��Ʊ��Ҫ������������Ϊ����һ�����׵�Ԫ
//prices[2] - prices[0],��ʵ������Էֽ� -> (prices[2]-prices[1]) + (prices[1]-prices[0])
//��ʵ���Ǵӵڶ��쿪ʼ������ͳ���������󣬺;�����������

//̰�ģ��ֲ����ţ��ռ�ÿ���������  ȫ�����ţ�����������
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int res = 0;
        //��һ��û���������ٵڶ������������
        for(int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - prices[i - 1];
            if(profit > 0)
            {
                res += profit;
            }
        }
        return res;
    }
};
