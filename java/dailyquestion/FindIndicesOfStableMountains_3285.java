package dailyquestion;

import java.util.ArrayList;
import java.util.List;

/**
 * <a href="https://leetcode.cn/problems/find-indices-of-stable-mountains/description/">找到稳定山的下标</a>
 *
 * @author sutong
 * @date 2024-12-19 14:01
 */
public class FindIndicesOfStableMountains_3285 {

    public List<Integer> stableMountains(int[] height, int threshold) {
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i < height.length; i++) {
            if (height[i - 1] > threshold) {
                res.add(i);
            }
        }
        return res;
    }

}
