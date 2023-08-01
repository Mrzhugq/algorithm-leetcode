package sort;

/**
 * 归并排序：O(N*logN)，稳定，需要O(N)的空间复杂度
 * 思想：将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序
 * 更多的是解决在磁盘中的外排序问题
 */
public class MergeSort {

    public void mergeSort(int[] nums) {
        int[] tempArr = new int[nums.length];
        doMergeSort(nums, 0, nums.length - 1, tempArr);
    }

    private void doMergeSort(int[] nums, int left, int right, int[] tempArr) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        doMergeSort(nums, left, mid, tempArr);
        doMergeSort(nums, mid + 1, right, tempArr);

        int idx = left;
        int begin1 = left, end1 = mid;
        int begin2 = mid + 1, end2 = right;
        while (begin1 <= end1 && begin2 <= end2) {
            if (nums[begin1] > nums[begin2]) {
                tempArr[idx++] = nums[begin2++];
            } else {
                tempArr[idx++] = nums[begin1++];
            }
        }

        // [begin1, end1] [begin2, end2] 不一定一样长
        while (begin1 <= end1) {
            tempArr[idx++] = nums[begin1++];
        }
        while (begin2 <= end2) {
            tempArr[idx++] = nums[begin2++];
        }
        // 拷贝回nums
        for (int i = left; i <= right; i++) {
            nums[i] = tempArr[i];
        }
    }

}
