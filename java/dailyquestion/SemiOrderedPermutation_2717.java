package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/semi-ordered-permutation/description/">半有序排列</a>
 *
 * @author sutong
 * @date 2024-12-11 11:21
 */
public class SemiOrderedPermutation_2717 {

    // nums = [2,4,1,3]
    // 输出：3
    public int semiOrderedPermutation(int[] nums) {
        int first = 0, last = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                first = i;
            } else if (nums[i] == n) {
                last = i;
            }
        }
        // 越位需减1
        return first + (n - 1 - last) - (first > last ? 1 : 0);
    }

}
