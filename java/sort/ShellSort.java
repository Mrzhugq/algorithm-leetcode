package sort;

/**
 * 希尔排序  O(logN * N) 不稳定
 * 思想：希尔排序是对直接插入排序的优化
 *      把相隔gap距离的分成一组，首先进行预排序，使数组几乎接近有序
 *      当gap > 1时都是预排序，目的是让数组更接近于有序。当gap == 1时，数组已经接近有序的了，这样就会很快。这样整体而言，可以达到优化的效果。
 */
public class ShellSort {

    public void shellSort(int[] nums) {
        int len = nums.length;
        int gap = len / 2;
        while (gap > 0) {
            for (int i = 0; i < len - gap; i++) {
                int end = i;
                int temp = nums[end + gap];
                while (end >= 0) {
                    if (nums[end] > temp) {
                        nums[end + gap] = nums[end];
                        end -= gap;
                    } else {
                        break;
                    }
                }
                nums[end + gap] = temp;
            }
            gap /= 2;
        }
    }
}
