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

////2.�Ż�     ��Ŀ��˵����Ԫ�ص�˳����Ըı䡹 ����[1,2,3,4,5]  val=1; 
////ʵ�������ǿ���ֱ�ӽ����һ��Ԫ�� 5�ƶ������п�ͷ��ȡ��Ԫ�� 1���õ����� [5,2,3,4],ͬ��������ĿҪ��
////����Ż���������valԪ�ص���������ʱ�ǳ���Ч����������Ҫ������Ԫ�ص��ظ���ֵ����
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
