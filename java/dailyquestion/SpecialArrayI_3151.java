package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/special-array-i/description/">特殊数组 I</a>
 * @author sutong
 * @date 2024-08-13 9:29
 */
public class SpecialArrayI_3151 {

    public boolean isArraySpecial(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                return false;
            }
        }
        return true;
    }

}
