package sort;

/**
 * 直接插入排序 ： O(N^2) 稳定
 * 思想就是：[0, end] 已经有序，把 end+1 位置的值插入前面，使得 [0,end+1]有序
 */
public class InsertSort {

    public void insertSort(int[] nums) {
        int len = nums.length;
        for (int i = 0; i < len - 1; i++) {
            int end = i;
            int temp = nums[end + 1];
            while (end >= 0) {
                if (nums[end] > temp) {
                    // 只要插入的值要比前一个小，前一个就往后挪一位
                    nums[end + 1] = nums[end];
                    end--;
                } else {
                    break;
                }
            }
            //如果 1.break到这里就是找到比temp小的了 2.while循环走完结束到这里end == -1了
            nums[end + 1] = temp;
        }
    }

}
