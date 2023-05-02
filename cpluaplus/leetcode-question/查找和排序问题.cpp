#include<stdio.h>
void quick_sort(int *arr,int L,int R)
{
	int i=L;
	int j=R;
	int x=arr[L];
	if(L<R)
	{
		int i=L,j=R,x=arr[L];
		while(i<j)
		{
			while(i<j && arr[j]>=x)
			{
				j--;
			}
			if(i<j)
			{
				arr[i]=arr[j];
				i++;
			}
			while(i<j && arr[i]<x)
			{
				i++;
			}
			if(i<j)
			{
				arr[j]=arr[i];
				j--;
			}
			arr[i]=x;
	    }
		quick_sort(arr,L,i-1);
		quick_sort(arr,i+1,R);
	}
}
int main()
{
    int arr[10]= {0};
    printf("请输入10个整数\n");
    for(int i=0; i<10; i++)
    {
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,9);
    printf("按照升序排列后为:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",arr[i]);
    }
}

//#include<limits.h>
//#include<stdio.h>
//#include<math.h>
//int main()
//{   int max=INT_MIN;
//    int min=INT_MAX;
//    int sum=0;
//    int arr[10]= {0};
//    printf("请输入10个整数：\n");
//    for(int i=0; i<10; i++)
//    {
//        scanf("%d",&arr[i]);
//        sum=sum+arr[i];
//    }
//    for(int i=0; i<10; i++)
//    {
//        max=fmax(arr[i],max);
//    }
//    for(int i=0; i<10; i++)
//    {
//        min=fmin(arr[i],min);
//    }
//    printf("最大值为：%d\n最小值为：%d\n",max,min);
//    printf("平均值为：%f\n",sum/10.0);
//}


//#include<limits.h>
//#include<stdio.h>
//#include<math.h>
//int main()
//{   int max=0;
//    int min=0;
//    int arr[10]= {0};
//    printf("请输入10个整数：\n");
//    for(int i=0; i<10; i++)
//    {
//        scanf("%d",&arr[i]);
//    }
//    for(int i=1; i<10; i++)
//    {
//        if(arr[i]>arr[max])
//        {
//            max=i;
//        }
//    }
//    for(int i=1; i<10; i++)
//    {
//        if(arr[i]<arr[min])
//        {
//            min=i;
//        }
//    }
//    printf("最大值为：%d\n最小值为：%d\n",arr[max],arr[min]);
//    printf("次序分别为：%d %d",max,min);
//}


