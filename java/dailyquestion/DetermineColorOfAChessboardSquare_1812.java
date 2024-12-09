package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/determine-color-of-a-chessboard-square/description/">判断国际象棋棋盘中一个格子的颜色</a>
 *
 * @author sutong
 * @date 2024-12-09 17:03
 */
public class DetermineColorOfAChessboardSquare_1812 {
    // h3
    public boolean squareIsWhite(String coordinates) {
        int sum = (coordinates.charAt(0) - 'a')  + (coordinates.charAt(1) - '1');
        return sum % 2 == 1;
    }
}
