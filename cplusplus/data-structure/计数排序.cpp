#include<stdio.h>
#include<stdlib.h>

//计数排序 （非比较排序）
//时间复杂度O(N+range) -> 说明它只适用于范围集中一组整形数据排序（局限性）
//空间复杂度O(range)
void CountSort(int *arr,int Size)
{
	int max=arr[0],min=arr[0];
	for(int i=1; i<Size; i++)
	{
		if(arr[i] > max)
		{
			max=arr[i];
		}
		if(arr[i] < min)
		{
			min=arr[i];
		}
	}
	
	int range=max-min+1;//减少空间浪费
	int *count=(int*)calloc(sizeof(int),range);//用来统计arr中数组数字出现的次数
	for(int i=0; i<Size; i++)
	{
		count[ arr[i]-min ]++;//统计次数（相对映射）
	}
	
	int j=0;
	for(int i=0; i<range; i++)//写数字，出现几次就写几次这个数字
	{
		while(count[i]--)
		{
			arr[j++]=i + min;//映射加min变回原来的数字
		}
	}
	
	free(count);
	count=NULL;
} 

int main()
{
	int arr[]={5,2,1,4,3,6,9,8,7,0};
    CountSort(arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}



//还有一个非比较排序 -> 基数排序（桶排序）
//就是依次分别取它们的个位，十位，百位...比较
//但它只适用于一组整形数据排序 -> 实际中用的比较少,校招也不怎么考
