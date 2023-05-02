
/*
两次贪心：
1.局部最优：只要右边评分比左边多，右边就多一个糖果。
  全局最优：相邻的孩子中，评分高的右孩子获得获得比左孩子更多的糖果
2.局部最优：取candyVec[i],candyVec[i+1]+1最大的糖果数量,保证第i个小孩的糖果数量即大于左边也大于右边的
  全局最优：相邻的孩子中，评分高的孩子获得更多的糖果
*/

class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        vector<int> candyVec(ratings.size(), 1);
        
        //先确定右评分大于左评分的情况（从前往后后遍历）
        for (int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i - 1] < ratings[i])
            {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }

        //再确定左评分大于右评分的情况（这时需要从后往前遍历）
        //因为如果从前往后就没法利用上一次的比较结果了
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
            {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
                //取最大值才能保证第i个得到糖果比左边和右边都多
            }
        }

        int res = 0;
        for (int num : candyVec)
        {
            res += num;
        }
        return res;
    }
};
