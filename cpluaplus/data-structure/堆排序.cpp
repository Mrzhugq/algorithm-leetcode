#include<stdio.h>

//堆排序 时间复杂度:O(N*logN)
void Swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//向下调整算法(使用前提:左右子树必须已经是大堆或者小堆)
void AjustDown(int *arr,int Size,int root)//这里用建大堆做例子
{
	int parent=root;
	int child=2*parent+1; //先默认左孩子大
	while(child < Size)
	{
		if(child+1 < Size && arr[child+1] > arr[child])//child+1 < Size防止只有一个孩子越界
		{
			child=child+1;
		}
		//选孩子中大的和父亲交换
		if(arr[child] > arr[parent])
		{
			Swap(&arr[child],&arr[parent]);
			parent=child;
			child=2*parent+1;
		}
		else//如果父亲已经比两个孩子都大已经满足条件了
		{
			break;
		}
	}
}

void HeapSort(int *arr,int Size)
{
	//建堆时间复杂度O(N)
	//因为向下调整算法前提，所以我们需要从后向前调整，即从最后一棵非叶子节点开始调(叶子不需要调)
	for(int i=(Size-1-1)/2; i>=0; i--)//最后一棵非叶子节点 -> 最后一个节点的父亲
	{
		AjustDown(arr,Size,i);
	}
	//升序需要建大堆 ! ! !
	//如果建小堆的话，每次取第一个为最小值，然后第一个不变，从第二个开始重新建堆
	//这样堆的原始结构都被改变了，建小堆不是不行，是没有了效率优势
	int end=Size-1;
	while(end > 0)
	{
		Swap(&arr[0],&arr[end]);
		AjustDown(arr,end,0);
		end--;
	}
}

int main()
{
	int arr[]={5,2,1,4,3,6,9,8,7,0};
    HeapSort(arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}






////建小堆
//void AjustDown(int *arr,int Size,int root)
//{
//	int parent=root;
//	int child=2*parent+1;
//	while(child < Size)
//	{
//		if(child+1 < Size && arr[child+1] < arr[child])
//		{
//			child=child+1;
//		}
//		if(arr[child] < arr[parent])
//		{
//			Swap(&arr[child],&arr[parent]);
//			parent=child;
//			child=2*parent+1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}