//��������֮�ͣ����ʺϹ�ϣ���ʺ�����˫ָ�뷨
//����֮��������һ��forѭ���̶�nums[i]��Ȼ��ѭ������left��right�±���Ϊ˫ָ�룬�ҵ�nums[i]+nums[left]+nums[right]==0
//��������֮�͵���������forѭ���̶�nums[k] + nums[i]��Ȼ�󡣡���

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //˫ָ����Ҫ����
        for(int k=0; k<nums.size(); k++)
        {
            //������֦�Ǵ���ģ����ﲻ������֮��target�Ǹ��̶���0��������target�ǿɱ��(ע��ϸ��)
            //���target��-11,�����nums[]=[-5,-4,-3,-2,1,3,3,5],��ʱnums[0]>target��return��Ȼ����ȷ�������(-5,-4,-3,1)
            // if(nums[k] > target)//������һ������targetֱ�ӽ���
            // {
            //     return res;
            // }
            if(k > 0 && nums[k-1] == nums[k]) //ע��
            {
                continue;
            }
            for(int i=k+1; i<nums.size(); i++)
            {
                if(i > (k + 1) && nums[i-1] == nums[i]) //ע�� 
                {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;  //nums:[1000000000, 1000000000, 1000000000, 1000000000] target:0
                while(left < right)           //35��39�мӸ�long long��ֹ���
                {
                    if((long long)nums[k] + nums[i] + nums[left] + nums[right] > target) //ע��������target����0��
                    {
                        right--;
                    }
                    else if((long long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back(vector<int> {nums[k], nums[i], nums[left], nums[right]});
                        //˫ָ��ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮��
                        while(left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while(left < right && nums[right - 1] == nums[right])
                        {
                            right--;
                        }
                        //�ҵ��𰸣�˫ָ��ͬʱ����
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
