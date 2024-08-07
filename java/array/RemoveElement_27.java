package array;

/**
 * <a href="https://leetcode.cn/problems/remove-element/description/">移除元素</a>
 */
class RemoveElement_27 {
    public int removeElement(int[] nums, int val) {
        int low = 0;
        for (int fast = 0; fast < nums.length; fast++) {
            if (nums[fast] != val) {
                nums[low] = nums[fast];
                low++;
            }
        }
        return low;
    }
}