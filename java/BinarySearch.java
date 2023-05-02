package com.sutong.array;

public class BinarySearch {
    public int search(int[] nums, int target) {
        int left = 0;
        int rigth = nums.length - 1; // [left, rigth]
        while(left <= rigth) {
            int mid = left + ((rigth - left) / 2); // 防止溢出
            if (nums[mid] > target) {
                rigth = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    public int search2(int[] nums, int target) {
        int left = 0;
        int rigth = nums.length; // [left, rigth)
        while(left < rigth) {
            int mid = left + ((rigth - left) / 2); // 防止溢出
            if (nums[mid] > target) {
                rigth = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
