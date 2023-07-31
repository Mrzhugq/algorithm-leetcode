package sort;

import java.util.Arrays;
import java.util.Random;

/**
 * 测试类
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
        new ShellSort().shellSort(nums);
        System.out.println(Arrays.toString(nums));
    }

}
