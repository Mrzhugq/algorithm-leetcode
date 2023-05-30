package array;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 */
public class Permutations_46 {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }
        backtrack(list, res, 0);
        return res;
    }

    private void backtrack(List<Integer> list, List<List<Integer>> res, int k) {
        if (k == list.size()) {
            res.add(new ArrayList<>(list));
        }
        for (int i = k; i < list.size(); i++) {
            Collections.swap(list, i, k);
            backtrack(list, res, k + 1);
            Collections.swap(list, i, k);
        }
    }

    public static void main(String[] args) {
        System.out.println(new Permutations_46().permute(new int[]{1, 2, 3}));
    }
}
