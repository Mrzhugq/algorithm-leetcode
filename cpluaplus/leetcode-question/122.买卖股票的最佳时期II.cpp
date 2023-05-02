
//只有一只股票，要想获得利润至少为两天一个交易单元
//prices[2] - prices[0],其实利润可以分解 -> (prices[2]-prices[1]) + (prices[1]-prices[0])
//其实我们从第二天开始买卖，统计正的利润，和就是最终利润

//贪心，局部最优：收集每天的正利润  全局最优：求得最大利润
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int res = 0;
        //第一天没有利润，至少第二天才能有利润
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
