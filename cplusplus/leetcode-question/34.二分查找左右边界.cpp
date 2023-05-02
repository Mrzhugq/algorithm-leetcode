class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result;
        int begin = 0;
        int end = nums.size(); // [0 nums.size()) �ҿ����䣬ע����begin==end�����
        //�����
        while(begin < end)
		{
            int mid = ((end-begin)>>1) + begin;
            if(nums[mid] == target)
			{
                end = mid;
            }
			else if(nums[mid] > target)
			{
                end = mid;
            }
			else if(nums[mid] < target)
			{
                begin = mid + 1;
            }
        }
        
        //����ѭ��begin == end  ���ܵ�ȡֵΪ0��nums.length����  �ҵ��� -> (0-nums.length)
        // target������������,Ҳ����left==nums.length
        if (begin == nums.size()) return {-1,-1};
        // target����������С����ʱbeginΪ0��begin����[0 - nums.length-1]���п��ܵ���target
        if(nums[begin] == target)
		{
            result.push_back(begin);
        }
		else
		{ //��ʱbeginΪ0����target����������С����û���ҵ�Ŀ��ֵ
            return {-1,-1};
        }
        
         //���ұ�
        begin = 0;
        end = nums.size();
        while(begin<end)
		{
            int mid = ((end-begin)>>1) + begin;
            if(nums[mid] == target)
			{
                begin = mid + 1; //������
            }
			else if(nums[mid] > target)
			{
                end = mid;       //������
            }
			else if(nums[mid] < target)
			{
                begin = mid + 1;
            }
        }
        
//        �����������
//        begin == end  //���ܵ�ȡֵΪ0��nums.length����(0-nums.length)
//        if(left == 0) return {-1,-1};
//        if(nums[left-1]==target)
//		{   //left����Ϊ[1-nums.length] left-1����Ϊ[0-nums.length-1]
//            result.push_back(begin-1);
//        }
//		else
//		{
//            return {-1,-1};
//        }
        
        //���������ʱ���Ѿ�ȷ����������target������ֻ��Ҫ���أ�����Ҫ���⴦��
        result.push_back(begin-1);
       return result;
    }
};

