/*
//对数组中所有二进制位求和，例如： [2,2,3,2]       
    0010
    0010
    0010
    0011
和：0041  ->  如果二进制位求和 % 3 != 0，说明出现一次的数字该位上是1 
*/

class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            int total = 0;
            for(int j = 0; j < nums.size(); j++) //每个数字二进制的i位和
            {
                //或者total += ((num[j] >> i) & 1);
                if( ((nums[j] >> i) & 1) == 1)
                {
                    total++;
                }
            }
            if(total % 3 != 0)
            {
                res |= (1 << i); //这句很妙！
            }
        }
        return res;
    }
};


