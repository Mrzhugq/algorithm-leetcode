#include<stdio.h>

void Swap(int *a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//直接选择排序(这个是优化后的一次选两个)
//几乎最差的排序，因为最好最坏时间复杂度都是O(N^2)
void SelectSort(int *arr,int Size)
{
	int bagin=0;
	int end=Size-1;
	while(bagin < end)
	{
		int mini=bagin,maxi=bagin;
		for(int i=bagin; i<=end; i++)
		{
			if(arr[i] < arr[mini])
			{
				mini=i;
			}
			
			if(arr[i] > arr[maxi])
			{
				maxi=i;
			}
		}
		Swap(&arr[mini],&arr[bagin]);
		//如果bagin和maxi重叠，需要修正一下maxi的位置
		//比如    9 3 5 2 7 8 6 -1 4 0 
		//交换完 -1 3 5 2 7 8 6  9 4 0 
		if(bagin==maxi)
		{
			maxi=mini;
		}
		Swap(&arr[maxi],&arr[end]);
		
		bagin++;
		end--;
	}
}

int main()
{
	int arr[]={9,3,5,2,7,8,6,-1,4,0};
	SelectSort(arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}
