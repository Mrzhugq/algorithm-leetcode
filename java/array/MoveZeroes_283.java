package array;

/**
 * <a href="https://leetcode.cn/problems/move-zeroes/description/">移动零</a>
 */
class MoveZeroes_283 {
    public void moveZeroes(int[] nums) {
        // 把不等于0的移到前面
        int low = 0;
        for (int fast = 0; fast < nums.length; fast++) {
            if (nums[fast] != 0) {
                nums[low] = nums[fast];
                low++;
            }
        }
        // 补0
        for (int i = low; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
}