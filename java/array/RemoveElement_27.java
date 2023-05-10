package array;

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