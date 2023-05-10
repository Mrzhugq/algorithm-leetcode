package array;

class Sqrtx_69 {
    // 右边界
    public int mySqrt(int x) {
        int left = 0;
        int right = x;
        int res = -1;
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if ((long) mid * mid > x) {
                right = mid - 1;
            } else if (mid * mid <= x) {
                left = mid + 1;
                res = left;
            }
        }
        return res - 1;
    }
}