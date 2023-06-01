package hash;

import java.util.ArrayList;

/**
 * 给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
 * 返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
 */
public class IntersectionOfTwoArraysII_350 {
    public int[] intersect(int[] nums1, int[] nums2) {
        ArrayList<Integer> res = new ArrayList<>();
        int[] count = new int[1005];
        for (int i : nums1) {
            count[i]++;
        }
        for (int i : nums2) {
            if (count[i] > 0) {
                res.add(i);
                count[i]--;
            }
        }
        return res.stream().mapToInt(num -> num).toArray();
    }
}
