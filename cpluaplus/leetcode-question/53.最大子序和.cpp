//̰��
//�ֲ����ţ�
//��������Ϊ������ʱ����������������һ��Ԫ�����¼��㡰�����͡�����Ϊ����������һ��Ԫ�غ�ֻ��Խ��Խ��

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int count = 0;
        int result = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            count += nums[i];
            if(count > result) //���½��
            {
                result = count;
            }
            if(count < 0) //���ϵ�ǰ����Ϊ�����ˣ��͹��㣬����һ�������ۼ�(Ҫ�������������������ۼ�)
            {
                count = 0;
            }
        }
        return result;
    }
};

//----------------------------------------------------------------------------
int maxSubArray(int* nums, int numsSize)
{
    //dp[i]�������±�i֮ǰ��������������к�Ϊdp[i]��
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    int ret = dp[0];
    for(int i=1; i<numsSize; i++)
    {
        dp[i] = fmax(nums[i],dp[i-1]+nums[i]);
        if(dp[i] > ret)
        {
            ret = dp[i]; 
        }
    }
    return ret; //ע�ⲻ�Ƿ���dp[numSize-1]
}

