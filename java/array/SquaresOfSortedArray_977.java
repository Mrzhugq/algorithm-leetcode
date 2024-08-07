package array;

/**
 * <a href="https://leetcode.cn/problems/squares-of-a-sorted-array/description/">有序数组的平方</a>
 */
class SquaresOfSortedArray_977 {
    public int[] sortedSquares(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        int idx = nums.length - 1;
        int[] res = new int[nums.length];
        while (left <= right) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                res[idx--] = nums[left] * nums[left];
                left++;
            } else {
                res[idx--] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
}