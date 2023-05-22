package array;

public class MinimumSizeSubarraySum_209 {
    public int minSubArrayLen(int target, int[] nums) {
        int res = Integer.MAX_VALUE;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int sunLen = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.length; j++) {  // 滑动窗口结束位置
            sum += nums[j];
            while (sum >= target) {
                sunLen = j - i + 1;
                res = Math.min(res, sunLen);
                sum -= nums[i++];
            }
        }
        return res == Integer.MAX_VALUE ? 0 : res;
    }
}