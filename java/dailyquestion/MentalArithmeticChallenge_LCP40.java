package dailyquestion;

import java.util.Arrays;

/**
 * 「力扣挑战赛」心算项目的挑战比赛中，要求选手从 N 张卡牌中选出 cnt 张卡牌，
 * 若这 cnt 张卡牌数字总和为偶数，则选手成绩「有效」且得分为 cnt 张卡牌数字总和。
 * 给定数组 cards 和 cnt，其中 cards[i] 表示第 i 张卡牌上的数字。
 * 请帮参赛选手计算最大的有效得分。若不存在获取有效得分的卡牌方案，则返回 0。
 * <a href="https://leetcode.cn/problems/uOAnQW/description/">心算挑战</a>
 *
 * @author sutong
 * @date 2024-08-01 9:50
 */
public class MentalArithmeticChallenge_LCP40 {

    public int maxmiumScore(int[] cards, int cnt) {
        int len = cards.length;
        if (len < cnt) {
            return 0;
        }
        int res = 0, temp = 0;
        int odd = -1, even = -1;
        Arrays.sort(cards);
        for (int i = len - 1; i >= len - cnt; i--) {
            temp += cards[i];
            if (cards[i] % 2 == 0) {
                even = cards[i];
            } else {
                odd = cards[i];
            }
        }

        // 偶数直接返回
        if (temp % 2 == 0) {
            return temp;
        }

        // 奇数
        //    在数组前面找到一个最大的奇数与后 cnt 个数中最小的偶数进行替换  [1,2,8,9], cnt = 3
        //    在数组前面找到一个最大的偶数与后 cnt 个数中最小的奇数进行替换  [4,5,8,8], cnt = 3
        for (int i = len - cnt - 1; i >= 0; i--) {
            if (cards[i] % 2 == 1 && even != -1) {
                res = Math.max(res, temp - even + cards[i]);
                break;
            }
        }
        for (int i = len - cnt - 1; i >= 0; i--) {
            if (cards[i] % 2 == 0 && odd != -1) {
                res = Math.max(res, temp - odd + cards[i]);
                break;
            }
        }

        return res;
    }
}
