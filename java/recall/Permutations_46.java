package recall;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 */
public class Permutations_46 {
    List<List<Integer>> res = new ArrayList<>();
    LinkedList<Integer> path = new LinkedList<>();

    public List<List<Integer>> permute(int[] nums) {
        boolean[] used = new boolean[nums.length];
        backtracking(nums, used);
        return res;
    }

    private void backtracking(int[] nums, boolean[] used) {
        if (path.size() == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }

        for (int i = 0; i < nums.length; i++) {  // 排列问题，每次都要从头开始搜索
            if (used[i]) continue;               // path里已经收录的元素，直接跳过
            path.add(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.removeLast();
            used[i] = false;
        }
    }
}
