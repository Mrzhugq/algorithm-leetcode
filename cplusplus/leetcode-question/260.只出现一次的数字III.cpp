class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        //���磺[1,2,1,3,2,5]
        int ret = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        //ret = 3 ^ 5;  ==   0110
        int Index = -1;
        for(int i = 0; i < 32; i++) //�ҳ�ret��������/�������������λ��һ������1��λ��
        {
            if( ((ret >> i) & 1) == 1)
            {
                Index = i;
                break;
            }
        }
        //�������Ľ�����з���(������ret��һ�γ���1��λ�÷���),��λ�ó���1λһ��,��λ����0Ϊһ��
        //�����ͻ�ѳ���һ�ε��������ֵַ���ͬ�����У�����ڶ������������򣬾����������
        vector<int> vec1;  //2��2��3
        vector<int> vec2;  //1��1��5
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
        //����������������ÿ�����л��и�����һ������
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



