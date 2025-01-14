package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/number-of-ways-to-split-array/description/">分割数组的方案数</a>
 *
 * @author sutong
 * @date 2025-01-13 16:21
 */
public class NumberOfWaysToSplitArray_2270 {

    public int waysToSplitArray(int[] nums) {
        int res = 0;
        long leftSum = 0, rightSum = 0;
        for (int num : nums) {
            rightSum += num;
        }
        for (int i = 0; i < nums.length - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            if (leftSum >= rightSum) {
                res++;
            }
        }
        return res;
    }

}
