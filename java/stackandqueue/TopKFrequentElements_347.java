package stackandqueue;

import java.util.HashMap;
import java.util.PriorityQueue;

/**
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 */
@SuppressWarnings("all")
public class TopKFrequentElements_347 {

    public int[] topKFrequent(int[] nums, int k) {
        int[] res = new int[k];
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        // 小顶堆 （每次弹出堆顶最小的，堆内只保存k个最大元素）
        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>((pair1, pair2) -> pair1[1] - pair2[1]);
        for (Integer num : map.keySet()) {
            if (priorityQueue.size() < k) {
                priorityQueue.offer(new int[]{num, map.get(num)}); // 数字，频率
            } else {
                if (map.get(num) > priorityQueue.peek()[1]) {
                    priorityQueue.poll();
                    priorityQueue.offer(new int[]{num, map.get(num)});
                }
            }
        }
        // 倒着，因为是小顶堆，堆顶的频率小的
        for (int i = k - 1; i >= 0; i--) {
            res[i] = priorityQueue.poll()[0];
        }
        return res;
    }

}
