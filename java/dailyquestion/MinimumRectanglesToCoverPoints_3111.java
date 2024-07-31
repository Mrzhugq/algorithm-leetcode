package dailyquestion;

import java.util.Arrays;
import java.util.Comparator;

/**
 * 给你一个二维整数数组 point ，其中 points[i] = [xi, yi] 表示二维平面内的一个点。同时给你一个整数 w 。你需要用矩形 覆盖所有 点。
 * 每个矩形的左下角在某个点 (x1, 0) 处，且右上角在某个点 (x2, y2) 处，其中 x1 <= x2 且 y2 >= 0 ，同时对于每个矩形都 必须 满足 x2 - x1 <= w 。
 * 如果一个点在矩形内或者在边上，我们说这个点被矩形覆盖了。
 * 请你在确保每个点都 至少 被一个矩形覆盖的前提下，最少 需要多少个矩形。
 * 注意：一个点可以被多个矩形覆盖。
 * <a href="https://leetcode.cn/problems/minimum-rectangles-to-cover-points/description/">覆盖所有点的最少矩形数目</a>
 *
 * @author sutong
 * @date 2024-07-31 10:10
 */
public class MinimumRectanglesToCoverPoints_3111 {

    // 1
    // 1 1 1 2  3 4
    public int minRectanglesToCoverPoints(int[][] points, int w) {
        Arrays.sort(points, Comparator.comparingInt(p -> p[0]));
        int res = 1;
        int left = 0;
        for (int i = 0; i < points.length; i++) {
            int pointX = points[i][0];
            if (pointX - points[left][0] > w) {
                res++;
                left = i;
            }
        }
        return res;
    }

    // 力扣官方题解
    public int minRectanglesToCoverPoints2(int[][] points, int w) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        int res = 0;
        int bound = -1;
        for (int[] p : points) {
            if (p[0] > bound) {
                bound = p[0] + w;
                res++;
            }
        }
        return res;
    }

}
