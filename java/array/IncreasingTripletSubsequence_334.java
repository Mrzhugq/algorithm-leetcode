package array;

import java.util.Arrays;

/**
 * <a href="https://leetcode.cn/problems/increasing-triplet-subsequence/description/">递增的三元子序列</a>
 *
 * @author sutong
 * @date 2024-12-19 14:48
 */
public class IncreasingTripletSubsequence_334 {

    // 贪心
    public boolean increasingTriplet(int[] nums) {
        if (nums.length < 3) {
            return false;
        }

        int first = nums[0], second = Integer.MAX_VALUE;
        for (int i = 1; i < nums.length; i++) {
            int num = nums[i];
            if (second < num) {
                // first < second < num
                return true;
            } else if (first < num) {
                // first < num < second
                second = num;
            } else {
                // num < first < second
                first = num;
            }
        }
        return false;
    }

    // 动态规划 O(n^2)，类似300题
    public boolean increasingTriplet2(int[] nums) {
        if (nums.length < 3) {
            return false;
        }

        // dp[i] :表示i之前包括i的最长上升子序列长度为dp[i]
        int[] dp = new int[nums.length];
        // 初始化，起始大小至少都是1
        Arrays.fill(dp, 1);
        int res = 0;
        for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // 位置i的最长升序子序列 = j从0~i-1各个位置的最长相等子序列+1的最大值！
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > res) res = dp[i];
        }
        return res >= 3;
    }
}
