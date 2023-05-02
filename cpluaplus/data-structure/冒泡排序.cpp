#include<stdio.h>

void Swap(int *a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//冒泡排序
//时间复杂度 O(N^2)
//      最好 O(N)
//相对于直接插入排序，不如直接插入排序
void BubbleSort(int *arr,int Size)
{
	for(int i=0; i<Size; i++)
	{
		int exchange=0;
		for(int j=1; j<Size-i; j++)
		{
			if(arr[j-1] > arr[j])
			{
				Swap(&arr[j-1],&arr[j]);
				exchange=1;
			}
		}
		
		if(exchange==0)//如果第一趟一个都没有交换代表已经有序了，直接break
		{
			break;
		}
	}
}

int main()
{
	int arr[]={9,3,5,2,7,8,6,-1,4,0};
	BubbleSort(arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}
