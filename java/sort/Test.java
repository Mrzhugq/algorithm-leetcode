package sort;

import java.util.Arrays;
import java.util.Random;

/**
 * 测试类
 * https://blog.csdn.net/Edward_Asia/article/details/121419975
 */
public class Test {

    public static void main(String[] args) {
        int[] nums = new int[10];
        Random random = new Random();
        for (int i = 0; i < 10; i++) {
            nums[i] = random.nextInt(20);
        }
        System.out.println(Arrays.toString(nums));
        //new InsertSort().insertSort(nums);
        //new ShellSort().shellSort(nums);
        //new SelectSort().selectSort(nums);
        //new HeapSort().heapSort(nums);
        //new BubbleSort().bubbleSort(nums);
        //new MergeSort().mergeSort(nums);
        //new CountSort().countSort(nums);
        new QuickSort().quickSort(nums);
        System.out.println(Arrays.toString(nums));
    }

}
