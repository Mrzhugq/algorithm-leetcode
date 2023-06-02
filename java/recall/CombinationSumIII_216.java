package recall;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 * 只使用数字1到9
 * 每个数字 最多使用一次 
 * 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 */
public class CombinationSumIII_216 {
    List<List<Integer>> res = new ArrayList<>();
    LinkedList<Integer> path = new LinkedList<>();

    public List<List<Integer>> combinationSum3(int k, int n) {
        backtracking(n, k, 1, 0);
        return res;
    }

    private void backtracking(int targetSum, int k, int startIndex, int sum) {
        // 剪枝：已选元素总和如果已经大于targetSum了，那么往后遍历就没有意义了
        if (sum > targetSum) {
            return;
        }
        if (path.size() == k && sum == targetSum) {
            res.add(new ArrayList<>(path));
            return;
        }

        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) { // 剪枝
            path.add(i);
            sum += i;
            backtracking(targetSum, k, i + 1, sum);
            path.removeLast();
            sum -= i;
        }
    }
}
