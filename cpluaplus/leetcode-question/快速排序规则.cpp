#include<stdio.h>
#include<stdlib.h>
#include<search.h>
int cmp(const void *a,const void *b) //函数里面就是比较规则 
{
	int va=*(int *)a;
	int vb=*(int *)b;
	
	if(va%2==0 && vb%2==0)
	return va-vb;
	if(va%2==1 && vb%2==1)
	return va-vb;
	if(va%2==1 && vb%2==0)
	return -1;
	if(va%2==0 && vb%2==0)
	return 1; 
	
}
//[1,3,5,7,8,2,4,6,8,10]


//int cmp(const void *a,const void *b)
//{
//	return *(int *)a - *(int *)b;
//}

int main()
{
	int arr[]={1,3,2,5,4,7,6,9,8,10};
	qsort(arr,10,sizeof(int),cmp);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
 } 
