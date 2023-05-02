//统计 arr中的数字+1，是不是还在arr中 
// arr    [1,1,1,3,3,3,4]
//number   1 2 3 1 2 3 1
//count    0 0 0 0 0 0 3
#include<stdio.h> 
#include<stdlib.h>
//int cmp_int(void *e1,void *e2)
//{
//	return (*(int *)e1-*(int *)e2);
//}
//int countElements(int *arr,int arrSize)
//{
//	qsort(arr,arrSize,sizeof(int),cmp_int);
//	int count=0;
//	int number=0;
//	for(int i=1;i<arrSize;i++)
//	{
//		if(arr[i]!=arr[i-1])
//		{
//			if(arr[i]==arr[i-1]+1)
//			{
//			    count=count+number;
//			}
//			number=1;
//		}
//		else
//		{
//			number++;
//		}
//	}
//	return count;
//} 

int countElements(int *arr,int arrSize)
{
	int count=0;
	for(int i=0;i<arrSize;i++)
	{
		int xPlus=arr[i]+1;
		
		int isfound=0;
		for(int j=0;j<arrSize;j++)
		{
		    if(arr[j]==xPlus)
			{
			    isfound=1;    //count++;
				break;
			}
	    }
	    if(isfound)
	    {
	    	count++;
		}
	}
	return count;
}
int main()
{
	int arr1[]={1,3,4,1,3,1,3};
	int ret=countElements(arr1,7);
	printf("%d\n",ret);
	return 0;
}




