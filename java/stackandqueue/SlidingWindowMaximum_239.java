package stackandqueue;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.PriorityQueue;

/**
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 * 返回 滑动窗口中的最大值 。
 */
@SuppressWarnings("all")
public class SlidingWindowMaximum_239 {

    // 单调队列 O(N)
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] res = new int[nums.length - k + 1];
        ArrayDeque<Integer> deque = new ArrayDeque<>(); // 维护单调递减的一个队列
        for (int i = 0; i < k; i++) {
            // 从后往前比
            while (!deque.isEmpty() && nums[i] >= nums[deque.peekLast()]) {
                deque.pollLast();
            }
            deque.offerLast(i);
        }
        res[0] = nums[deque.peekFirst()];
        for (int i = k; i < nums.length; i++) {
            // 从后往前比
            while ((!deque.isEmpty() && nums[i] >= nums[deque.peekLast()])) {
                deque.pollLast();
            }
            deque.offerLast(i);
            // 是否在滑动窗口内
            while (deque.peekFirst() <= i - k) {
                deque.pollFirst();
            }
            res[i - k + 1] = nums[deque.peekFirst()];
        }
        return res;
    }

    // 优先队列 O(N*logN)
    public int[] maxSlidingWindow2(int[] nums, int k) {
        int[] res = new int[nums.length - k + 1];
        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>((pair1, pair2) -> pair1[0] != pair2[0] ? pair2[0] - pair1[0] : pair2[1] - pair1[0]);
        for (int i = 0; i < k; i++) {
            priorityQueue.offer(new int[]{nums[i], i});
        }
        res[0] = priorityQueue.peek()[0];
        for (int i = k; i < nums.length; i++) {
            priorityQueue.offer(new int[]{nums[i], i});
            while (priorityQueue.peek()[1] <= i - k) {
                priorityQueue.poll();
            }
            res[i - k + 1] = priorityQueue.peek()[0];
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new SlidingWindowMaximum_239().maxSlidingWindow(new int[]{7, 1, 3, -1, -3, 5, 3, 6}, 3)));
    }
}
