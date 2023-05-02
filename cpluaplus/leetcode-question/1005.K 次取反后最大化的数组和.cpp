
//̰�ģ��ֲ����ţ��þ���ֵ��ĸ�����Ϊ��������ǰ��ֵ�ﵽ���
//      �������ţ���������ʹﵽ���
//ʱ�� :O(NlogN)
class Solution 
{
public:
    static bool cmp(int a, int b) //ע�ⰴ����ֵ�Ž��򣡣�
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), cmp);
        //ע�⣺ ������ֵ�Ĵ�С�Ž� ->  �����������ȰѾ���ֵ��ĸ�����Ϊ����

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0 && k > 0) //��num�︺����Ϊ����(k��)
            {
                nums[i] *= -1;
                k--;
            }
        }

        //����ߵ�����k��Ϊ�㣬��ônums��ʱ���涼��������
        //���kΪ�����Ͱ���С��������Ϊ���������ˣ����kΪż��nums���ñ�(�������ž�������)
        if(k % 2 != 0)
        {
            nums[nums.size() - 1] *= -1;
        }
        //���
        int res = 0;
        for(int num : nums)
        {
            res += num;
        }
        return res;
    }
};
