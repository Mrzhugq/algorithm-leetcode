#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

//1.
int removeElement(int* nums, int numsSize, int val)
{
    int x=0;
    int y=0;
    while(x<numsSize)
    {
        if(nums[x]!=val)
        {
            nums[y]=nums[x];
            y++;
        }
        x++;
    }
    return y;
}

////2.优化     题目中说：「元素的顺序可以改变」 例如[1,2,3,4,5]  val=1; 
////实际上我们可以直接将最后一个元素 5移动到序列开头，取代元素 1，得到序列 [5,2,3,4],同样满足题目要求。
////这个优化在序列中val元素的数量较少时非常有效。避免了需要保留的元素的重复赋值操作
//int removeElement(int* nums, int numsSize, int val) 
//{
//    int left = 0, right = numsSize;
//    while (left < right) 
//	{
//        if (nums[left] == val) 
//		{
//            nums[left] = nums[right-1];
//            right--;
//        } 
//		else 
//		{
//            left++;
//        }
//    }
//    return left;
//}

int main()
{
	int arr[]={1,2,3,4,5};
	int len=removeElement(arr,5,1);
	for(int i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
 } 
