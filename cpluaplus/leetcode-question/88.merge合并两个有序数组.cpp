#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //�Ӻ���ǰ�ã����ķź��棬Ȼ��ڶ����...
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
        //���end1û�е��㣬����Ҫ������Ϊ������nums1��
    }
        while(end2>=0)//end2û�е�������
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
	//nums1Size,nums2Sizeû���ȴ���0 
	merge(arr1,0,m,arr2,0,n);
	for(int i=0;i<6;i++)
	{
		printf("%d ",arr1[i]);
	}
}
