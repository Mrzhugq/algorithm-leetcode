package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/available-captures-for-rook/description/">可以被一步捕获的棋子数</a>
 *
 * @author sutong
 * @date 2024-12-09 17:26
 */
public class AvailableCapturesForRook_999 {
    public int numRookCaptures(char[][] board) {
        int ri = 0, rj = 0, res = 0;
        int[] dx = {0, 1, 0, -1}; // 方向数组
        int[] dy = {1, 0, -1, 0};

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'R') {
                    ri = i;
                    rj = j;
                    break;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int step = 0; ; step++) {
                int x = ri + step * dx[i];
                int y = rj + step * dy[i];
                if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B') {
                    break;
                }
                if (board[x][y] == 'p') {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}