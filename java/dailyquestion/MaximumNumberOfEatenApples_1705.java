package dailyquestion;

import java.util.PriorityQueue;

/**
 * <a href="https://leetcode.cn/problems/maximum-number-of-eaten-apples/description/">吃苹果的最大数目</a>
 *
 * @author sutong
 * @date 2024-12-24 14:25
 */
public class MaximumNumberOfEatenApples_1705 {

    public int eatenApples(int[] apples, int[] days) {
        int i = 0, res = 0;
        // 在尚未腐烂的苹果中优先选择腐烂日期最早的苹果
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        // 第一阶段是第 0 天到第 n−1 天，即天数在数组下标范围内
        while (i < apples.length) {
            // 腐烂了
            while (!pq.isEmpty() && pq.peek()[0] <= i) {
                pq.poll();
            }
            if (apples[i] > 0) {
                int rottenDay = i + days[i];
                pq.offer(new int[]{rottenDay, apples[i]});
            }
            if (!pq.isEmpty()) {
                int[] arr = pq.peek();
                arr[1]--;
                if (arr[1] == 0) {
                    pq.poll();
                }
                res++;
            }
            i++;
        }

        // 第二阶段是第 n 天及以后，即天数在数组下标范围外
        while (!pq.isEmpty()) {
            // 腐烂了
            while (!pq.isEmpty() && pq.peek()[0] <= i) {
                pq.poll();
            }
            if (pq.isEmpty()) {
                break;
            }
            // 假设优先队列的队首元素的腐烂日期是 x，数量是 y，其中 x>i，则有 y 个苹果，距离腐烂还有 x−i 天，因此能吃到的苹果数量是 curr=min(x−i,y)。
            int[] arr = pq.poll();
            int curr = Math.min(arr[0] - i, arr[1]);
            res += curr;
            i += curr;
        }
        return res;
    }
}
