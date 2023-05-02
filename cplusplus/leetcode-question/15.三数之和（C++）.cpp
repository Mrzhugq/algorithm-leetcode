//�����ù�ϣ�����ʣ�ȥ��ϸ�ںܶ࣬���ô���
//�ʺ���˫ָ��

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //˫ָ����Ҫ����
        
        //a + b + c == 0  ->  nums[i] + nums[left] + nums[right] == 0
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0)  return res; //������һ��������0������Ͳ����ҳ�����֮��Ϊ0
            if(i > 0 && nums[i-1] == nums[i]) //��a����ȥ�أ�����ȥ�ز�������дnums[i] == nums[i+1]��©���
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    res.push_back(vector<int> {nums[i], nums[left], nums[right]} ); //�ҵ�һ��
                    //˫ָ��ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ���Ժ�
                    while(left < right && nums[left] == nums[left+1]) //��b����ȥ��
                    {
                        left++;
                    }
                    while(left < right && nums[right-1] == nums[right]) //��c����ȥ��
                    {
                        right--;
                    }
                    left++; //�ҵ��𰸣�˫ָ��ͬʱ����
                    right--;
                }
            }
        }
        return res;
    }
};
