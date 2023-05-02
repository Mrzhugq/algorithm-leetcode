class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result;
        int begin = 0;
        int end = nums.size(); // [0 nums.size()) 右开区间，注意检查begin==end的情况
        //找左边
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
        
        //结束循环begin == end  可能的取值为0、nums.length或者  找到了 -> (0-nums.length)
        // target比所有数都大,也就是left==nums.length
        if (begin == nums.size()) return {-1,-1};
        // target比所有数都小，这时begin为0；begin处理[0 - nums.length-1]都有可能等于target
        if(nums[begin] == target)
		{
            result.push_back(begin);
        }
		else
		{ //这时begin为0，且target比所有数都小，即没有找到目标值
            return {-1,-1};
        }
        
         //找右边
        begin = 0;
        end = nums.size();
        while(begin<end)
		{
            int mid = ((end-begin)>>1) + begin;
            if(nums[mid] == target)
			{
                begin = mid + 1; //闭区间
            }
			else if(nums[mid] > target)
			{
                end = mid;       //开区间
            }
			else if(nums[mid] < target)
			{
                begin = mid + 1;
            }
        }
        
//        正常处理左边
//        begin == end  //可能的取值为0、nums.length或者(0-nums.length)
//        if(left == 0) return {-1,-1};
//        if(nums[left-1]==target)
//		{   //left可能为[1-nums.length] left-1可能为[0-nums.length-1]
//            result.push_back(begin-1);
//        }
//		else
//		{
//            return {-1,-1};
//        }
        
        //由于找左边时，已经确保数组中有target，这里只需要返回，不需要特殊处理
        result.push_back(begin-1);
       return result;
    }
};

