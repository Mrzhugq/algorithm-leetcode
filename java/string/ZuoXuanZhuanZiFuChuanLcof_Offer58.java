package string;

/**
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
 * 请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
 */
public class ZuoXuanZhuanZiFuChuanLcof_Offer58 {
    public String reverseLeftWords(String s, int n) {
        char[] res = s.toCharArray();
        reverseString(res, 0, res.length - 1);
        reverseString(res, 0, res.length - n - 1);
        reverseString(res, res.length - n, res.length - 1);
        return new String(res);
    }

    public void reverseString(char[] s, int left, int right) {
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
}
