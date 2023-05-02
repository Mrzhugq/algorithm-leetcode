#include<stdio.h>

void Swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//快速排序 优化 -> (三数取中法)
int GetMidIndex(int *arr,int left,int right)//取中间值下标函数
{
	int mid=(left+right)>>1;//int mid=(left+right)/2;
	if(arr[left] < arr[mid])
	{
		if(arr[mid] < arr[right])// 例如:2(L)  3(mid)   4(R)
		{
			return mid;
		}
		else //arr[mid] > arr[right]  例如:2(L)  4(mid)   3(R)  -> mid已经最大，left right中大的的就是中间值
		{
			if(arr[left] > arr[right])//例如:3(L)  4(mid)   2(R)
			{
				return left;
			}
			else//例如:2(L)  4(mid)   3(R)
			{
				return right;
			}
		}
	}
	else//a[left] > arr[mid]
	{
		if(arr[mid] > arr[right])
		{
			return mid;
		}
		else//arr[mid] < arr[right]  -> mid已经最小，left right中小的的就是中间值
		{
			if(arr[left] < arr[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
	}
}


void QuickSort(int *arr,int left,int right)//闭区间
{
	if(left >= right)
	{
		return;
	}
	
	int index=GetMidIndex(arr,left,right);
	Swap(&arr[left],&arr[index]);//交换一下，防止key取到最小值或者最大值
	
	//下面逻辑不变，和挖坑法的一样
	int bagin=left,end=right;
	int pivot=bagin;//坑
	int key=arr[bagin]; //关键字
	
	while(bagin < end)
	{
		//1.右边找小的放到左边
		while(bagin < end && arr[end] >= key)
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