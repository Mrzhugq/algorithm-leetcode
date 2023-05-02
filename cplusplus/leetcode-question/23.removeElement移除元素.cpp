#include<stdio.h> 

int removeElement(int* nums, int numsSize, int val)
{
    int x=0;
    int y=0;
    while(x<numsSize)
    {
        if(nums[x]==val)
        {
            x++;
        }
        else
        {
            nums[y]=nums[x];
            y++;
            x++;
        }
    }
    return y;
}

int main()
{
	int arr[]={3,2,2,3};
	int val=3;
	int ret=removeElement(arr,4,val);
	for(int i=0;i<ret;i++)
	{
		printf("%d ",arr[i]);
	}
} 
