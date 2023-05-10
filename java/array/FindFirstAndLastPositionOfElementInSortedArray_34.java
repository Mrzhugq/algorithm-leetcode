package array;

class FindFirstAndLastPositionOfElementInSortedArray_34 {
    public int[] searchRange(int[] nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rigthBorder = getRightBorder(nums, target);
        if (leftBorder == -2 || rigthBorder == -2) return new int[]{-1, -1};
        if (rigthBorder - leftBorder > 1) return new int[]{leftBorder + 1, rigthBorder - 1};
        return new int[]{-1, -1};
    }

    // 右边界
    private int getRightBorder(int[] nums, int target) {
        int left = 0;
        int rigth = nums.length - 1; // [left, right]
        int rightBorder = -2;
        while (left <= rigth) {
            int mid = left + ((rigth - left) / 2);
            if (nums[mid] > target) {
                rigth = mid - 1;       
            } else {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }

    // 左边界
    private int getLeftBorder(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1; // [left, right]
        int leftBorder = -2;
        while (left <= right) {  
            int mid = left + ((right - left) / 2);
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
                leftBorder = right;
            }
        }
        return leftBorder;
    }
}