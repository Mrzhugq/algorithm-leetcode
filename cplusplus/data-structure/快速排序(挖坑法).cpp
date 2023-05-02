#include<stdio.h>

//快速排序(挖坑法)  O(N*logN) 
//当数组内有序的时候效率最坏 -> O(N^2)  -> 改进(三数取中法)
//一般 ：void QuickSort(int *arr,int Size)
void QuickSort(int *arr,int left,int right)//闭区间
{
	if(left >= right)//当区间没有值或者只有一个的时候就不用排啦
	{
		return;
	}
	
	int bagin=left,end=right;
	int pivot=bagin;//坑
	int key=arr[bagin]; //关键字
	
	while(bagin < end)
	{
		//1.右边找小的放到左边
		while(bagin < end && arr[end] >= key)//arr[end] >= key 注意这里要>=否则会死循环
		{
			end--;
		}
		//小的放到左边的坑里
		arr[pivot]=arr[end];
		pivot=end;
		//2.左边找大的放到右边
		while(bagin < end && arr[bagin] <= key)
		{
			bagin++;
		}
		//大的放到右边的新坑里
		arr[pivot]=arr[bagin];
		pivot=bagin;
	}
	pivot=bagin;//pivot=end;
	arr[pivot]=key;
	
	//[left,right]
	//[left,pivot-1] pivot [pivot+1,right]
	//如果左 右子区间有序整体就有序了 -> 分治递归
	QuickSort(arr,left,pivot-1);
	QuickSort(arr,pivot+1,right);
}


int main()
{
	int arr[]={5,2,1,4,3,6,9,8,7,0};
    QuickSort(arr,0,10-1);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}
