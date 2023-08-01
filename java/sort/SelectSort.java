package sort;

/**
 * 直接选择排序 O(N^2) 不稳定
 * 思路：每次选择最大的放到后面 / 取最小的放到前面
 */
public class SelectSort {

    public void selectSort(int[] nums) {
        int begin = 0, end = nums.length - 1;
        while (begin < end) {
            int minIdx = begin, maxIdx = begin;
            for (int i = begin; i <= end; i++) {
                if (nums[i] > nums[maxIdx]) {
                    maxIdx = i;
                }
                if (nums[i] < nums[minIdx]) {
                    minIdx = i;
                }
            }
            swap(nums, begin, minIdx);
            // 如果begin和maxIdx重叠，需要修正一下maxIdx的位
            if (begin == maxIdx) {
                maxIdx = minIdx;
            }
            swap(nums, end, maxIdx);
            begin++;
            end--;
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

}
