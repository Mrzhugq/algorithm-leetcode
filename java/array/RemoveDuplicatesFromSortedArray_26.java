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

    public int removeDuplicates2(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int slow = 1, fast = 1;
        while (fast < nums.length) {
            if (nums[fast- 1] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
}