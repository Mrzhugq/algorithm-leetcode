package stackandqueue;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
 * 实现 MyStack 类：
 * <p>
 * void push(int x) 将元素 x 压入栈顶。
 * int pop() 移除并返回栈顶元素。
 * int top() 返回栈顶元素。
 * boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 */
public class ImplementStackUsingQueues_225 {

}


class MyStack {
    private Deque<Integer> queue1;  // 和栈中保持一样元素的队列
    private Deque<Integer> queue2;  // 辅助队列

    public MyStack() {
        queue1 = new ArrayDeque<>();
        queue2 = new ArrayDeque<>();
    }

    public void push(int x) {
        queue2.offer(x);
        while (!queue1.isEmpty()) {
            queue2.offer(queue1.poll());
        }
        // 最后交换queue1和queue2，将元素都放到queue1中
        Deque<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }

    public int pop() {
        return queue1.poll();
    }

    public int top() {
        return queue1.peek();
    }

    public boolean empty() {
        return queue1.isEmpty();
    }
}


class MyStack1 {
    private Deque<Integer> queue;

    public MyStack1() {
        queue = new ArrayDeque<>();
    }

    // 把前n-1个重新入队即可
    public void push(int x) {
        queue.offer(x);
        int size = queue.size();
        while (size-- > 1) {
            queue.offer(queue.poll());
        }
    }

    public int pop() {
        return queue.poll();
    }

    public int top() {
        return queue.peek();
    }

    public boolean empty() {
        return queue.isEmpty();
    }
}