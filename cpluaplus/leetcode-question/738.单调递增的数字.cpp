//贪心-
//局部最优：遇到strNum[i-1] > strNum[i]的情况（非单调递增），
//          首先让strNum[i-2]--，然后strNum[i]=9,可以保证变成最大单调递增整数
//全局最优：得到小于等于N的最大单调递增的整数

//还有个问题，从后往前遍历每位还是从前往后呢？ 从后往前
//例如332，如果此前往后遍历的话就改成329了，而结果是299

class Solution 
{
public:
    int monotoneIncreasingDigits(int n) 
    {
        string strNum = to_string(n);
        int flag = strNum.size();

        for(int i = strNum.size() - 1; i > 0; i--)
        {
            if(strNum[i - 1] > strNum[i])
            {
                strNum[i - 1]--;
                //strNum[i] = '9';  //不能这样100这个用例过不去，要用flag标记从哪里开始填9

                flag = i;
            }
        }
        for(int i = flag; i < strNum.size(); i++) //填9
        {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
