package dailyquestion;

import java.util.HashMap;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/description/">有序数组中出现次数超过25%的元素</a>
 *
 * @author sutong
 * @date 2025-02-17 13:44
 */
public class ElementAppearingMoreThan25InSortedArray_1287 {

    public int findSpecialInteger(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            cnt.put(arr[i], cnt.getOrDefault(arr[i], 0) + 1);
            if (cnt.get(arr[i]) > arr.length / 4) {
                return arr[i];
            }
        }
        return -1;
    }


    public int findSpecialInteger2(int[] arr) {
        int cur = arr[0], cnt = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == cur) {
                cnt++;
                if (cnt > arr.length / 4) {
                    return cur;
                }
            } else {
                cur = arr[i];
                cnt = 1;
            }
        }
        return -1;
    }
}
