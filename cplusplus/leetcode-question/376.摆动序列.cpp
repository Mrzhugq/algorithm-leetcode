//�ֲ����ţ�ɾ���������ϵĽڵ㲻�������������˵Ľڵ㣬��ô����¶ȾͿ����������ֲ���ֵ
//��ʵ����ɾ������Ϊ��Ŀ���س��ȣ��������飬ֻͳ�Ʒ�ֵ�����Ϳ�����
class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if(nums.size() <= 1)  return nums.size();
        int preDiff = 0, curDiff = 0;
        int result = 1; //��ʼ��Ϊ1��Ĭ���ұ��и���ֵ��Ҫ��[2,5]�ͻ᷵��1����ʵ��2

        for(int i=1; i<nums.size(); i++)
        {
            curDiff = nums[i] - nums[i - 1];
            //���ַ�ֵ
            if((preDiff <=0 && curDiff > 0) || (preDiff >=0 && curDiff < 0))
            {
                result++;
                preDiff = curDiff; //�����Ҫ��if��,��ֹ[5,10,10,15]�����м���ƽ�Ķ���ͳ��
            }
            
        }
        return result;
    }
};
