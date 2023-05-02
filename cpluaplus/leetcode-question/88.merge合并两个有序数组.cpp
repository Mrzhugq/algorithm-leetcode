#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //从后往前拿，最大的放后面，然后第二大的...
    int end1=m-1;
    int end2=n-1;
    int end=m+n-1;
    while(end1>=0 && end2>=0)
    {
        if(nums1[end1]>nums2[end2])
        {
            nums1[end]=nums1[end1];
            end1--;
            end--;
        }
        else
        {
            nums1[end]=nums2[end2];
            end--;
            end2--;
        }
        //如果end1没有到零，不需要处理，因为就是在nums1中
    }
        while(end2>=0)//end2没有到零的情况
        {
            nums1[end]=nums2[end2];
            end--;
            end2--; 
        }
}

int main()
{
	int arr1[6]={1,2,3,0,0,0};
	int arr2[3]={2,5,6};
	int m=3;
	int n=3;
	//nums1Size,nums2Size没用先传个0 
	merge(arr1,0,m,arr2,0,n);
	for(int i=0;i<6;i++)
	{
		printf("%d ",arr1[i]);
	}
}
