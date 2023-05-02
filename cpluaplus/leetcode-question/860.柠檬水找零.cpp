
//1.是5元，直接收下。增加一个5元
//2.是10元，找零5元。增加一个10元，消耗一个5元
//3.是20元，找零15。优先消耗一个10元和一个五元，如果不够就消耗三个5元（贪心）

class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int bill : bills)
        {
            if(bill == 5)
            {
                five++;
            }
            else if(bill == 10)
            {
                if(five < 0)
                {
                    return false;
                }
                five--;
                ten++;
            }
            else
            {
                if(five > 0 && ten > 0) 
                {
                    five--;
                    ten--;
                    twenty++; //其实这句没意义了，不会用20来找零啦
                }
                else if(five >= 3)
                {
                    five -= 3;
                    twenty++; //这也没意义
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
