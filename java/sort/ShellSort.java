package sort;

/**
 * 希尔排序
 * 思想：把相隔gap距离的分成一组，首先进行预排序，使数组几乎接近有序，这样就可以使插入排序效率大大提高
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
