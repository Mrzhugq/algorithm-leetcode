package array;

/**
 * <a href="https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/">删除有序数组中的重复项</a>
 */
class RemoveDuplicatesFromSortedArray_26 {
    public int removeDuplicates(int[] nums) {
        int low = 0;
        for (int fast = 0; fast < nums.length; fast++) {
            if (nums[low] != nums[fast]) {
                low++;
                nums[low] = nums[fast];
            }
        }
        return low + 1;
    }
}