package dailyquestion;

import java.util.HashMap;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/find-occurrences-of-an-element-in-an-array/description/">查询数组中元素的出现位置</a>
 *
 * @author sutong
 * @date 2024-12-27 13:33
 */
public class FindOccurrencesOfAnElementInAnArray_3159 {

    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        int[] res = new int[queries.length];
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == x) {
                count++;
                map.put(count, i);
            }
        }
        for (int i = 0; i < queries.length; i++) {
            res[i] = map.getOrDefault(queries[i], -1);
        }
        return res;
    }

}
