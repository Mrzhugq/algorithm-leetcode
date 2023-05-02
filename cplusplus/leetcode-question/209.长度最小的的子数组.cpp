//ʱ�临�Ӷ�O(N) ( ����Ҳ���Ա�������forѭ������ȻO(N^2) )


class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int result = INT32_MAX; //����С�������г���
        int sum = 0; //���������ܺ�
        int i = 0;   //����������ʼλ��
        int subLength = 0;
        for(int j=0; j<nums.size(); j++) //�������ڽ���λ��  (����[i, j])
        {
            sum += nums[j];
            while(sum >= target) //ÿ��������������С�����䣬����û�и�С������
            {
                subLength = j - i + 1; //ÿ�������г���
                result = result < subLength ? result : subLength;
                sum -= nums[i];
                i++;
            }
        }
        //���resultû�б���ֵ���ͷ���0��˵��û�з���������������
        return result == INT32_MAX ? 0 : result;
    }
};
