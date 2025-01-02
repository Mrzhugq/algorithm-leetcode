package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/convert-date-to-binary/description/">将日期转换为二进制表示</a>
 *
 * @author sutong
 * @date 2025-01-02 15:32
 */
public class ConvertDateToBinary_3280 {

    public String convertDateToBinary(String date) {
        String[] dates = date.split("-");
        StringBuilder sb = new StringBuilder();
        for (String s : dates) {
            sb.append(toBinary(Integer.parseInt(s)));
            sb.append("-");
        }
        return sb.substring(0, sb.length() - 1);
    }

    private String toBinary(int x) {
        StringBuilder s = new StringBuilder();
        while (x > 0) {
            s.append(x % 2);
            x = x / 2;
        }
        return s.reverse().toString();
    }

    // 位运算
    private String binary(int x) {
        StringBuilder s = new StringBuilder();
        while (x > 0) {
            s.append(x & 1);
            x >>= 1;
        }
        return s.reverse().toString();
    }
}
