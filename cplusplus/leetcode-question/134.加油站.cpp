//如果总油量减去总消耗大于等于0那么一定能跑完一圈，说明各个站点的加油站剩油量rest[i]相加是大于等于0的
//i从0开始累加rest[i],和记为curSum，一旦curSum小于0，
//说明[0,i]区间都不能作为起始位置，起始位置从i+1算起，再从0计算curSum

//rest[i] = gas[i] - cost[i]
//贪心，局部最优：当前rest[j]的curSum一旦小于0，起始位置至少要是j+1，因为从j开始一定不行
//      全局最优：找到可以跑一圈的起始位置

class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;

        for(int  i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i]; 
            totalSum += gas[i] - cost[i]; 
            if(curSum < 0)
            {
                start = i + 1; //起始位置更新为i+1
                curSum = 0;    //curSum从0开始
            }
        }
        if(totalSum < 0)  return -1; //说明怎么也不可能跑一圈
        return start;
    }
};




/*
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

       [-2, -2, -2, 3, 3]
*/
