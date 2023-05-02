#include<stdio.h>

void Swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


//挖坑法(变形) —> 前后指针法
void QuickSort(int *arr,int left,int right)//闭区间
{
	if(left >= right)
	{
		return;
	}
//	//这里先不用三数取中优化
//	int index=GetMidIndex(arr,left,right);
//	Swap(&arr[left],&arr[index]);

    int keyi=left; 
    
    int prev=left;//cur找小，每次遇到比keyi小的值就停下来，prev++，交换prev和cur位置的值
    int cur=left+1; 
    
    while(cur <= right)//闭区间
    {
    	if(arr[cur] < arr[keyi] && (++prev)!=cur)//这样加个判断可以防止prev和cur相等时交换，自己和自己交换没意义
    	{
    		Swap(&arr[prev],&arr[cur]);
		}
//		if(arr[cur] < arr[keyi])//这样写也行
//    	{
//    		prev++;
//    		Swap(&arr[prev],&arr[cur]);
//		}
		cur++;
    }
    Swap(&arr[keyi],&arr[prev]);
    
    //[left,prev-1] [prev] [prev+1]
	QuickSort(arr,left,prev-1);
	QuickSort(arr,prev+1,right);
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
