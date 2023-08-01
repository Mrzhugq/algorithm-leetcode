package sort;

/**
 * 冒泡排序： O(N^2) 稳定
 * 思想：两两元素相比，前一个比后一个大就交换，直到将最大的元素交换到末尾位置，重复n-1次
 */
public class BubbleSort  {

    public void bubbleSort(int[] nums) {
        boolean isSorted = true;
        // n-1趟
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = 0; j < nums.length - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums, j, j + 1);
                    isSorted = false;
                }
            }
            // 若某一趟排序中没有元素交换则说明所有元素已经有序，说明已经整体有序了，不需要再排序
            if (isSorted) {
                break;
            }

        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

}
