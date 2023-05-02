#include<stdio.h>

void Swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


//挖坑法(变形) —> 左右指针法(思路一样)
void QuickSort(int *arr,int left,int right)//闭区间
{
	if(left >= right)
	{
		return;
	}
//	//这里先不用三数取中优化
//	int index=GetMidIndex(arr,left,right);
//	Swap(&arr[left],&arr[index]);
	
	int bagin=left,end=right;//左右指针
	int keyi=bagin;
	
	while(bagin < end)
	{
		while(bagin < end && arr[end] >= arr[keyi])//找小的
		{
			end--;
		}
		
		while(bagin < end && arr[bagin] <= arr[keyi])//找大的
		{
			bagin++;
		}
		
		Swap(&arr[bagin],&arr[end]);
	}
	Swap(&arr[bagin],&arr[keyi]);//这时bagin和end相等而且它们都指向中间 —> Swap(&arr[end],&arr[keyi]);
	
	//[left,bagin-1] [bagin] [bagin+1,right]
	QuickSort(arr,left,bagin-1);
	QuickSort(arr,bagin+1,right);
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







////挖坑法，单趟排序
//int PartSort1(int *arr,int left,int right)
//{
//	int index=GetMidIndex(arr,left,right);
//	Swap(&arr[left],&arr[index]);//交换一下，防止key取到最小值或者最大值
//	
//	//下面逻辑不变，和挖坑法的一样
//	int bagin=left,end=right;
//	int pivot=bagin;//坑
//	int key=arr[bagin]; //关键字
//	
//	while(bagin < end)
//	{
//		//1.右边找小的放到左边
//		while(bagin < end && arr[end] >= key)
//		{
//			end--;
//		}
//		//小的放到左边的坑里
//		arr[pivot]=arr[end];
//		pivot=end;
//		//2.左边找大的放到右边
//		while(bagin < end && arr[bagin] <= key)
//		{
//			bagin++;
//		}
//		//大的放到右边的新坑里
//		arr[pivot]=arr[bagin];
//		pivot=bagin;
//	}
//	pivot=bagin;//pivot=end;
//	arr[pivot]=key;
//	
//	return pivot;
//}
