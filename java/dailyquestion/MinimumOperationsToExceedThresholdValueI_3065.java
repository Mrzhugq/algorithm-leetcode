package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-i/description/">超过阈值的最少操作数 I</a>
 *
 * @author sutong
 * @date 2025-01-14 13:37
 */
public class MinimumOperationsToExceedThresholdValueI_3065 {

    public int minOperations(int[] nums, int k) {
        int res = 0;
        for (int num : nums) {
            if (num < k) {
                res++;
            }
        }
        return res;
    }

}
