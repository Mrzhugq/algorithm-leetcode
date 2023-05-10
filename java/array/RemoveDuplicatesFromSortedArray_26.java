package array;

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