package dailyquestion;

import java.util.Arrays;

public class DeleteGreatestValueInEachRow_2500 {
    public int deleteGreatestValue(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int res = 0;
        for (int i = 0; i < m; i++) {
            Arrays.sort(grid[i]);
        }
        for (int j = 0; j < n; j++) {
            int max = 0;
            for (int i = 0; i < m; i++) {
                max = Math.max(max, grid[i][j]);
            }
            res += max;
        }
        return res;
    }
}
