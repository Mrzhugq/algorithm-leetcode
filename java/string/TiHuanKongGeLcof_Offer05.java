package string;

/**
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */
public class TiHuanKongGeLcof_Offer05 {
    public String replaceSpace(String s) {
        // 数组填充类的问题，都可以先预先给数组扩容带填充后的大小，然后在从后向前进行操作。
        int spaceCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                spaceCount++;
            }
        }
        char[] res = new char[s.length() + 2 * spaceCount];
        int left = s.length() - 1;
        int right = res.length - 1;
        while (left >= 0 && left <= right) {
            if (s.charAt(left) != ' ') {
                res[right] = s.charAt(left);
                right--;
            } else {
                res[right] = '0';
                res[right - 1] = '2';
                res[right - 2] = '%';
                right -= 3;
            }
            left--;
        }
        return new String(res);
    }
}
