/*
//�����������ж�����λ��ͣ����磺 [2,2,3,2]       
    0010
    0010
    0010
    0011
�ͣ�0041  ->  ���������λ��� % 3 != 0��˵������һ�ε����ָ�λ����1 
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
            for(int j = 0; j < nums.size(); j++) //ÿ�����ֶ����Ƶ�iλ��
            {
                //����total += ((num[j] >> i) & 1);
                if( ((nums[j] >> i) & 1) == 1)
                {
                    total++;
                }
            }
            if(total % 3 != 0)
            {
                res |= (1 << i); //�����
            }
        }
        return res;
    }
};


