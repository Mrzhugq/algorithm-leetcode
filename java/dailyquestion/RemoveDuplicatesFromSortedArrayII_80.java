package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/">删除有序数组中的重复项 II</a>
 *
 * @author sutong
 * @date 2025-02-11 14:36
 */
public class RemoveDuplicatesFromSortedArrayII_80 {

    public int removeDuplicates(int[] nums) {
        if (nums.length <= 2) {
            return nums.length;
        }

        int slow = 2, fast = 2;
        while (fast < nums.length) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }

}
