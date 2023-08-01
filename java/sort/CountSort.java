package sort;

/**
 * 计数排序 O(MAX(N,范围)) 稳定
 * 思想；统计相同元素出现次数，根据统计的结果将序列回收到原来的序列中 (数组中元素有正有负的情况时不适用计数排序)
 */
public class CountSort {

    public void countSort(int[] nums) {
        int max = nums[0], min = nums[0];
        for (int i = 0; i < nums.length; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[i]);
        }
        int range = max - min + 1;
        int[] hash = new int[range];
        // 统计次数
        for (int i = 0; i < nums.length; i++) {
            hash[nums[i] - min]++;
        }
        int idx = 0;
        for (int i = 0; i < range; i++) {
            while (hash[i] > 0) {
                nums[idx++] = i + min;
                hash[i]--;
            }
        }
    }

}
