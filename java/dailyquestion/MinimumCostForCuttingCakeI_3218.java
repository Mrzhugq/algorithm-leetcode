package dailyquestion;

import java.util.ArrayList;
import java.util.List;

/**
 * <a href="https://leetcode.cn/problems/minimum-cost-for-cutting-cake-i/description/">切蛋糕的最小总开销 I</a>
 *
 * @author sutong
 * @date 2024-12-26 14:56
 */
public class MinimumCostForCuttingCakeI_3218 {

    public int minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        List<int[]> list = new ArrayList<>();
        for (int cost : horizontalCut) {
            list.add(new int[]{cost, 0});
        }
        for (int cost : verticalCut) {
            list.add(new int[]{cost, 1});
        }

        // 先切代价大的更优
        list.sort((a, b) -> b[0] - a[0]);
        int hcnt = 1, vcnt = 1, res = 0;
        for (int[] costs : list) {
            int cost = costs[0];
            if (costs[1] == 0) {
                // 横着切，切割完成后水平方向多了一块
                res += vcnt * cost;
                hcnt++;
            } else {
                // 竖着切，切割完成后垂直方向多了一块
                res += hcnt * cost;
                vcnt++;
            }
        }
        return res;
    }

}
