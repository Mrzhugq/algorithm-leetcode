package dailyquestion;

import java.util.ArrayList;
import java.util.List;

/**
 * <a href="https://leetcode.cn/problems/kids-with-the-greatest-number-of-candies/description/">拥有最多糖果的孩子</a>
 *
 * @author sutong
 * @date 2024-12-18 13:41
 */
public class KidsWithTheGreatestNumberOfCandies_1431 {

    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> res = new ArrayList<>(candies.length);
        int max = candies[0];
        for (int candy : candies) {
            max = Math.max(max, candy);
        }
        for (int candy : candies) {
            res.add(candy + extraCandies >= max);
        }
        return res;
    }

}
