//ע�������֮�ͣ�����֮�Ͳ�һ����������һ�����飨���ʺ��ù�ϣ������������4��������򵥵�

class Solution 
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        //key��a+b��value��a+b���ֵĴ���
        unordered_map<int, int> mp;
        for(int a : nums1)
        {
            for(int b : nums2)
            {
                mp[a+b]++;
            }
        }

        int count = 0; //��¼a+b+c+d=0���ֵĴ���
        for(int c : nums3)
        {
            for(int d : nums4)
            {
                if(mp.find(0 - (c + d)) != mp.end())
                {
                    count += mp[0 - (c + d)];
                }
            }
        }
        return count;
    }
};
