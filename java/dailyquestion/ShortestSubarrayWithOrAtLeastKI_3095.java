package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-i/description/">或值至少 K 的最短子数组 I</a>
 *
 * @author sutong
 * @date 2025-01-16 15:04
 */
public class ShortestSubarrayWithOrAtLeastKI_3095 {

    // O(N^2)
    public int minimumSubarrayLength(int[] nums, int k) {
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int value = 0;
            for (int j = i; j < nums.length; j++) {
                value |= nums[j];
                if (value >= k) {
                    res = Math.min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }

}
