package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/time-needed-to-buy-tickets/description/">买票需要的时间</a>
 *
 * @author sutong
 * @date 2024-09-29 14:52
 */
public class TimeNeededToBuyTickets_2073 {
    // tickets = [2,3,2], k = 2

    // tickets = [2,3,2], k = 1
    // 2 5 7
    public int timeRequiredToBuy(int[] tickets, int k) {
        int res = 0;
        for (int i = 0; i < tickets.length; i++) {
            if (i <= k) {
                res += Math.min(tickets[i], tickets[k]);
            } else {
                res += Math.min(tickets[i], tickets[k] - 1);
            }
        }
        return res;
    }

    // 模拟 发票员按顺序依次发票，发到的人需求就减1，遇到0需求的就不发了，一直发到第k个人的需求为0
    public int timeRequiredToBuy2(int[] tickets, int k) {
        int res = 0, i = 0;
        int n = tickets.length;
        while (tickets[k] > 0) {
            if (tickets[i % n] > 0) {
                tickets[i % n]--;
                res++;
            }
            i++;
        }
        return res;
    }
}
