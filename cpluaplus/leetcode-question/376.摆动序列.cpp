//局部最优：删除单调坡上的节点不包括单调坡两端的节点，那么这个坡度就可以有两个局部峰值
//其实不用删除，因为题目返回长度，不是数组，只统计峰值数量就可以啦
class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if(nums.size() <= 1)  return nums.size();
        int preDiff = 0, curDiff = 0;
        int result = 1; //初始化为1，默认右边有个峰值，要不[2,5]就会返回1，其实是2

        for(int i=1; i<nums.size(); i++)
        {
            curDiff = nums[i] - nums[i - 1];
            //出现峰值
            if((preDiff <=0 && curDiff > 0) || (preDiff >=0 && curDiff < 0))
            {
                result++;
                preDiff = curDiff; //这个放要到if内,防止[5,10,10,15]这种中间右平的而多统计
            }
            
        }
        return result;
    }
};
