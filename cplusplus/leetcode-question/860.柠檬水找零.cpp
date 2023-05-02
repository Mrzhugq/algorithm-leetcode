
//1.��5Ԫ��ֱ�����¡�����һ��5Ԫ
//2.��10Ԫ������5Ԫ������һ��10Ԫ������һ��5Ԫ
//3.��20Ԫ������15����������һ��10Ԫ��һ����Ԫ�������������������5Ԫ��̰�ģ�

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
                    twenty++; //��ʵ���û�����ˣ�������20��������
                }
                else if(five >= 3)
                {
                    five -= 3;
                    twenty++; //��Ҳû����
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
