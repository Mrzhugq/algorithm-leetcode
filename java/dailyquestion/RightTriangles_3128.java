package dailyquestion;

import java.util.Arrays;

/**
 * <a href="https://leetcode.cn/problems/right-triangles/">直角三角形</a>
 *
 * @author sutong
 * @date 2024-08-02 9:38
 */
public class RightTriangles_3128 {

    // [[0,1,0],
    //  [0,1,1],
    //  [0,1,0]]

    // [[1,0,1],
    //  [1,0,0],
    //  [1,0,0]]
    public long numberOfRightTriangles(int[][] grid) {

        long res = 0;
        int n = grid.length, m = grid[0].length;
        // [0, 3, 1]
        int[] col = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                col[j] += grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            int row = Arrays.stream(grid[i]).sum();
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    res += (long) (row - 1) * (col[j] - 1);
                }
            }
        }

        return res;
    }
}
