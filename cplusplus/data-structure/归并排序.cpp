#include<stdio.h>
#include<stdlib.h>

//归并排序 时间复杂度：O(N*logN)
void Merge_Sort(int *arr,int left,int right,int *temp)
{
	if(left >= right) //left == right 区间只有一个值不需要归并了
	{
		return;
	}
	
	int mid=(left+right)>>1;
	//假设 [left,mid] [mid+1,right]有序，那我们就可以归并了
	Merge_Sort(arr,left,mid,temp);
	Merge_Sort(arr,mid+1,right,temp);
	
	int bagin1=left,end1=mid;//归并
	int bagin2=mid+1,end2=right;
	int index=left;
	while(bagin1<=end1 && bagin2<=end2)
	{
		if(arr[bagin1] < arr[bagin2])
		{
			temp[index]=arr[bagin1];
			index++;
			bagin1++;
		}
		else
		{
		    temp[index]=arr[bagin2];
			index++;
			bagin2++;
		}
	}
	
	//判断哪个区间没结束，就把那个区间直接放到temp中
	while(bagin1 <= end1)
	{
		temp[index]=arr[bagin1];
		index++;
		bagin1++;
    }
	while(bagin2 <= end2)
	{
		temp[index]=arr[bagin2];
		index++;
		bagin2++;
	}
	
	//拷贝回arr
	for(int i=left; i<=right; i++)
	{
		arr[i]=temp[i];
	}
	
}

void MergeSort(int *arr,int Size)
{
	int *temp=(int*)malloc(sizeof(int)*Size);
	
	Merge_Sort(arr,0,Size-1,temp);
	free(temp);
}


int main()
{
	int arr[]={5,2,1,4,3,6,9,8,7,0};
    MergeSort(arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}

