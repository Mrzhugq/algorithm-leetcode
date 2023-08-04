package sort;

/**
 * 快速排序 O(N*logN) 不稳定
 * 思想：任取待排序元素序列中的某元素作为基准值，将集合分割成两子序列，左子序列中所有元素均小于基准值，右子序列中所有元素均大于基准值，然后最左右子序列重复该过程，直到所有元素都排列在相应位置上为止。
 */
public class QuickSort {

    public void quickSort(int[] nums) {
        doQuickSortPointer(nums, 0, nums.length - 1);
    }

    // 挖坑法 [left, right]
    private void doQuickSortPotholing(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int begin = left, end = right;
        int pivot = begin;
        int key = nums[begin];
        while (begin < end) {
            // 右边找小的放到左边
            while (begin < end && nums[end] >= key) {
                end--;
            }
            nums[pivot] = nums[end];
            pivot = end;
            // 左边找大的放到右边
            while (begin < end && nums[begin] <= key) {
                begin++;
            }
            nums[pivot] = nums[begin];
            pivot = begin;
        }
        pivot = begin; // begin == end
        nums[pivot] = key;

        // [left, pivot - 1]  pivot  [pivot + 1, right]
        doQuickSortPotholing(nums, left, pivot - 1);
        doQuickSortPotholing(nums, pivot + 1, right);
    }


    // 前后指针法 [left, right]
    private void doQuickSortPointer(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int keyIdx = left;
        int prev = left, cur = left + 1;
        while (cur <= right) {
            if (nums[cur] < nums[keyIdx]) {
                prev++;
                swap(nums, prev, cur);
            }
            cur++;
        }
        swap(nums, keyIdx, prev);

        // [left, prev - 1]  prev  [prev + 1, right]
        doQuickSortPointer(nums, left, prev - 1);
        doQuickSortPointer(nums, prev + 1, right);
    }


    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
