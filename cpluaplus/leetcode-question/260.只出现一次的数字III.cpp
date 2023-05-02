class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        //例如：[1,2,1,3,2,5]
        int ret = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        //ret = 3 ^ 5;  ==   0110
        int Index = -1;
        for(int i = 0; i < 32; i++) //找出ret从左往右/从右往左二进制位第一个出现1的位置
        {
            if( ((ret >> i) & 1) == 1)
            {
                Index = i;
                break;
            }
        }
        //根据异或的结果进行分类(即根据ret第一次出现1的位置分类),该位置出现1位一类,该位出现0为一类
        //这样就会把出现一次的两个数字分到不同的类中，最后在对两个类进行异或，就是最后结果了
        vector<int> vec1;  //2，2，3
        vector<int> vec2;  //1，1，5
        for(int i = 0; i < nums.size(); i++)
        {
            if( ((nums[i] >> Index) & 1) == 1)
            {
                vec1.push_back(nums[i]);
            }
            else
            {
                vec2.push_back(nums[i]);
            }
        }
        //最后对两个类进行异或，每个类中会有个出现一次数字
        int res1 = 0;
        for(int i = 0; i < vec1.size(); i++)
        {
            res1 ^= vec1[i];
        }
        int res2 = 0;
        for(int i = 0; i < vec2.size(); i++)
        {
            res2 ^= vec2[i];
        }
        return {res1, res2};
    }
};



