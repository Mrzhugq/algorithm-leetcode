package array;

import java.util.HashMap;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/minimum-size-subarray-sum/description/">长度最小的子数组</a>
 */
public class MinimumSizeSubarraySum_209 {
    public int minSubArrayLen(int target, int[] nums) {
        int res = Integer.MAX_VALUE;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        for (int j = 0; j < nums.length; j++) {  // 滑动窗口结束位置
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= target) {
                int sunLen = j - i + 1; // 滑动窗口的长度
                res = Math.min(res, sunLen);
                sum -= nums[i++];
            }
        }
        return res == Integer.MAX_VALUE ? 0 : res;
    }
}