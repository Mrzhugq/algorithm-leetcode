package array;

/**
 * <a href="https://leetcode.cn/problems/binary-search/">二分查找</a>
 */
public class BinarySearch_704 {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1; // [left, right]
        while(left <= right) {
            int mid = left + ((right - left) / 2); // 防止溢出
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    public int search2(int[] nums, int target) {
        int left = 0;
        int right = nums.length; // [left, right)
        while(left < right) {
            int mid = left + ((right - left) / 2); // 防止溢出
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
