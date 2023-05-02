#include<stdio.h>
void Swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void AdjustDown(int *arr,int Size,int root)
{
	int parent=root;
	int child=parent*2+1;//×ó

	while(child < Size)
	{
		if(child+1<Size && arr[child+1] > arr[child])
		{
			child=child+1;
		}
		
		if(arr[child] > arr[parent])
		{
			Swap(&arr[child],&arr[parent]);
			
			parent=child;
			child=parent*2+1; 
		}
		else
		{
			break;
		}
	} 
}

void HeapSort(int *arr,int Size)
{
	for(int i=(Size-1-1)/2; i>=0; i--)
	{
		AdjustDown(arr,Size,i);
	}
	
	int tail=Size-1;
	while(tail > 0)
	{
	    Swap(&arr[0],&arr[tail]);
	    AdjustDown(arr,tail,0);
	    tail--;
	}
	
}

int main()
{
	int arr[]={3,5,2,7,8,6,1,9,4,0};
	HeapSort(arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}

