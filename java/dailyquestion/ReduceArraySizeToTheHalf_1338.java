package dailyquestion;

import java.util.*;

/**
 * <a href="https://leetcode.cn/problems/reduce-array-size-to-the-half/description/">数组大小减半</a>
 *
 * @author sutong
 * @date 2024-12-16 17:41
 */
public class ReduceArraySizeToTheHalf_1338 {

    /**
     * 数组 arr 中有很多重复数字，如果选择删除数字 x，会将所有的 x 全部删除，并视为一次操作。原始数组的长度为 n，
     * 求最少的操作次数，使得数组长度小于等于 n/2。
     */
    public int minSetSize(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int res = 0, n = arr.length;
        for (int num : arr) {
            cnt.put(num, cnt.getOrDefault(num, 0) + 1);
        }

        List<Integer> list = new ArrayList<>(cnt.values());
        Collections.sort(list, Comparator.reverseOrder());
        for (Integer freq : list) {
            n -= freq;
            res++;
            if (n <= arr.length / 2) {
                return res;
            }
        }
        return res;
    }

}
