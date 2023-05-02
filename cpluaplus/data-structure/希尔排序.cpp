#include<stdio.h>

//直接插入排序的优化 -> 希尔排序
//1.先进行预排序(分组排,每间隔gap一组)，让数组接近有序(这样可以让直接插入排序效率更高) 
//2.直接插入排序 -> O(N) 
//时间复杂度O(log3N * N) 或者 O(logN * N)
void SheelSort(int *arr,int Size)
{
	int gap=Size;
	
	while(gap > 1)
	{
		//gap >1 时都是预排序          ->接近有序 
		//gap==1 时就是直接插入排序    ->完全有序 
		//或者gap=gap/3 + 1; 
		gap=gap/2; //除2可以保证最后一次gap==1 -> 变成完全有序 
		for(int i=0; i<Size-gap; i++)//把间隔为gap的多组数据同时排，最后i == Size-gap-1 
		{
			int end=i;
			int temp=arr[end+gap];
			while(end >= 0)
			{
				if(arr[end] > temp)
				{
					arr[end+gap]=arr[end];
					end=end-gap;
				}
				else
				{
					break;
				}
			}
			arr[end+gap]=temp;
		}
	}
}


int main()
{
	int arr[]={5,2,1,4,3};
	SheelSort(arr,5);
	for(int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}
