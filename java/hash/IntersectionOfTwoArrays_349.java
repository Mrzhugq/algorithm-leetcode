package hash;

import java.util.HashSet;
import java.util.Set;

/**
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 */
public class IntersectionOfTwoArrays_349 {
    // 数组作为hash
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> resSet = new HashSet<>();
        int[] count = new int[1005];
        for (int i : nums1) {
            count[i]++;
        }
        for (int i : nums2) {
            if (count[i] != 0) {
                resSet.add(i);
            }
        }
        return resSet.stream().mapToInt(num -> num).toArray();
    }

    // 使用set
    public int[] intersection2(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        Set<Integer> resSet = new HashSet<>();
        for (int i : nums1) {
            set.add(i);
        }
        for (int i : nums2) {
            if (set.contains(i)) {
                resSet.add(i);
            }
        }
        return resSet.stream().mapToInt(num -> num).toArray();
    }
}
