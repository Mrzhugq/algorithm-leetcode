#include<stdio.h>
 
//直接插入排序 O(N^2)
//最坏 ？逆序 1+2+3+...+n-1 
//最好 ？顺序 O(N) 
void InsertSort(int *arr,int Size)
{
	for(int i=0; i<Size-1; i++)
	{
		//如果下标[0,end]有序，把 end+1 插入后 [0,end+1] 有序
		//i<Size-1   即end最后一个位置是Size-2 -> 倒数第二个位置，如果到倒数第一个位置，end+1会越界 
		int end=i;
		int temp=arr[end+1];
		while(end >= 0)//最多插入在第一个位置 
		{
			if(arr[end] > temp)//只要插入的值要比前一个小，前一个就往后挪一位
			{
				arr[end+1]=arr[end];
				end--; 
			}
			else
			{
				break;
			}
		}
		//如果 1.break到这里就是找到比temp小的了 2.while循环走完结束到这里end == -1了
		arr[end+1]=temp; 
	} 

}

int main()
{
	int arr[]={5,2,1,4,3};
	InsertSort(arr,5);
	for(int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}
