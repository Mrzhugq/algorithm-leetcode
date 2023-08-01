package sort;

/**
 * 堆排序 ：O(N*logN) 不稳定
 * 思路：利用大顶堆，每次把堆顶最大的交换到末尾，然后进行一次向下调整算法，重复这样即可
 * 升序：大顶堆
 * 降序：小顶堆
 * <p>
 * 堆就是一颗完全二叉树，可以利用数组来实现：
 * leftChild = parent * 2 + 1
 * rightChild = parent * 2 + 2
 * parent = (child - 1) / 2
 */
public class HeapSort {

    public void heapSort(int[] nums) {
        // 最后一棵非叶子节点开始建立大顶堆 -> 最后一个节点的父亲
        for (int i = (nums.length - 1 - 1) / 2; i >= 0; i--) {
            adjustDown(nums, nums.length, i);
        }
        for (int end = nums.length - 1; end > 0; end--) {
            // 将堆顶的最大值和最后一位交换
            swap(nums, 0, end);
            // 只需要调整一下根节点即可
            adjustDown(nums, end, 0);
        }
    }


    // 向下调整算法，前提:左右子树必须已经是大顶堆
    private void adjustDown(int[] nums, int size, int root) {
        int parent = root;
        int child = parent * 2 + 1;
        while (child < size) {
            // 比较左右孩子
            if (child + 1 < size && nums[child] < nums[child + 1]) {
                child = child + 1;
            }
            // 让较大的孩子和父亲交换
            if (nums[child] > nums[parent]) {
                swap(nums, child, parent);
                parent = child;
                child = parent * 2 + 1;
            } else {
                break;
            }
        }
    }


    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

}
