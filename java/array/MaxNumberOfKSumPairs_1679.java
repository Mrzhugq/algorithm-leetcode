package array;

import java.util.HashMap;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/max-number-of-k-sum-pairs/description/">K 和数对的最大数目</a>
 *
 * @author sutong
 * @date 2024-12-19 16:00
 */
public class MaxNumberOfKSumPairs_1679 {

    // [3,1,3,4,3]
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int res = 0;
        for (int num : nums) {
            Integer count = cnt.getOrDefault(k - num, 0);
            if (count > 0) {
                res++;
                cnt.put(k - num, count - 1);
            } else {
                cnt.put(num, cnt.getOrDefault(num, 0) + 1);
            }
        }
        return res;
    }

}
