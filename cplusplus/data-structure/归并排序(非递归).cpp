#include<stdio.h>
#include<stdlib.h>

//归并排序非递归 时间复杂度：O(N*logN)
void MergeSortNonR(int *arr,int Size)
{
	int *temp=(int*)malloc(sizeof(int)*Size);
	int gap=1;//每组数据个数
	
	while(gap < Size)//gap=1,2,4,8,16...
	{
		for(int i=0; i<Size; i=i+2*gap) //每组归并
		{
			//[i, i+gap-1] [i+gap, i+2*gap-1]
			
			//下面的归并方法和递归里面的一样
			int bagin1=i,end1=i+gap-1;
			int bagin2=i+gap,end2=i+2*gap-1;
			//归并过程中右半区间可能就不存在 -> bagin2越界
			if(bagin2 >= Size)
			{
				break;
			}
			//归并过程中右半区间可能算多了,修正一下 -> end2越界
			if(end2 >= Size)
			{
				end2=Size-1;
			}
			
			int index=i;
			while(bagin1<=end1 && bagin2<=end2)
			{
				if(arr[bagin1] < arr[bagin2])
				{
					temp[index++]=arr[bagin1++];
				}
				else
				{
				    temp[index++]=arr[bagin2++];
				}
			}
			//判断哪个区间没结束，就把那个区间直接放到temp中
			while(bagin1 <= end1)
			{
				temp[index++]=arr[bagin1++];
		    }
			while(bagin2 <= end2)
			{
				temp[index++]=arr[bagin2++];
			}
			//拷贝回去，归并一段拷贝回去一段
			for(int j=i; j<=end2; j++)
			{
				arr[j]=temp[j];
			}
	    }

		gap=2*gap;
	}

	free(temp);
	temp=NULL;
}


int main()
{
	int arr[]={5,2,1,4,3,6,9,8,7,0};
    MergeSortNonR(arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}