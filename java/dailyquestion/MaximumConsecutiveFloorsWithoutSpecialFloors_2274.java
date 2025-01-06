package dailyquestion;

import java.util.Arrays;

/**
 * <a href="https://leetcode.cn/problems/maximum-consecutive-floors-without-special-floors/description/">不含特殊楼层的最大连续楼层数</a>
 *
 * @author sutong
 * @date 2025-01-06 14:32
 */
public class MaximumConsecutiveFloorsWithoutSpecialFloors_2274 {

    public int maxConsecutive(int bottom, int top, int[] special) {
        int res = 0, n = special.length;
        Arrays.sort(special);
        res = Math.max(res, special[0] - bottom);
        for (int i = 1; i < n; i++) {
            res = Math.max(res, special[i] - special[i - 1] - 1);
        }
        return Math.max(res, top - special[n - 1]);
    }

}
