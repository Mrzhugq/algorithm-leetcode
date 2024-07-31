package array;

/**
 * <a href="https://leetcode.cn/problems/search-insert-position/description/">搜索插入位置</a>
 */
class SearchInsertPosition_35 {
    // 查找找到第一个 大于等于target的位置
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int rigth = nums.length;
        while (left < rigth) {
            int mid = left + ((rigth - left) / 2);
            if (nums[mid] > target) {
                rigth = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return rigth;
    }
}