package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-i/">K 次乘运算后的最终数组 I</a>
 *
 * @author sutong
 * @date 2024-12-13 10:28
 */
public class FinalArrayStateAfterKMultiplicationOperationsI_3264 {

    public int[] getFinalState(int[] nums, int k, int multiplier) {
        for (int i = 0; i < k; i++) {
            int min = nums[0], minIdx = 0;
            for (int j = 1; j < nums.length; j++) {
                if (nums[j] < min) {
                    min = nums[j];
                    minIdx = j;
                }
            }
            nums[minIdx] = multiplier * min;
        }
        return nums;
    }
}
