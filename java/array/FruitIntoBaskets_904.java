package array;

import java.util.HashMap;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/fruit-into-baskets/description/">水果成篮</a>
 */
public class FruitIntoBaskets_904 {
    // 求只包含两种元素的最长连续子序列
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int res = 0;
        int i = 0; // 滑动窗口左边界
        for (int j = 0; j < fruits.length; j++) { // 滑动窗口右边界
            cnt.put(fruits[j], cnt.getOrDefault(fruits[j], 0) + 1);
            while (cnt.size() > 2) {
                cnt.put(fruits[i], cnt.get(fruits[i]) - 1);
                if (cnt.get(fruits[i]) == 0) {
                    cnt.remove(fruits[i]);
                }
                i++;
            }
            res = Math.max(res, j - i + 1);
        }
        return res;
    }
}