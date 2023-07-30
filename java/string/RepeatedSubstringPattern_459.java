package string;

/**
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 */
public class RepeatedSubstringPattern_459 {

    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        int[] next = new int[n];
        getNext(next, s);
        // 数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。
        if (next[n - 1] != 0 && n % (n - (next[n - 1])) == 0) {
            return true;
        }
        return false;
    }


    public void getNext(int[] next, String s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.length(); i++) {
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = next[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                j++;
            }
            next[i] = j;
        }
    }


    public boolean repeatedSubstringPattern2(String s) {
        // 字符串s是否由重复子串组成，只要两个s拼接在一起，里面还出现一个s的话，就说明是由重复子串组成。
        String str = s + s;
        // 要刨除 s + s 的首字符和尾字符，这样避免在s+s中搜索出原来的s，我们要搜索的是中间拼接出来的s
        str = str.substring(1, str.length() - 1);
        return str.contains(s);
    }
}
