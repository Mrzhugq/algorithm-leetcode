#include<stdio.h>
bool canJump(int* nums, int numsSize)
{
    int maxCanReach=0;//������¼���ߵ���Զ�ұߵ��±�
    for(int i=0;i<numsSize;i++)
    {
        if(i<=maxCanReach)//���ߵ�iλ��
        {
            int CanReach=i+nums[i];//�ߵ�i ����������
            if(CanReach>maxCanReach)//�������ֵ
            {
                maxCanReach=CanReach;
            }
        }
    }
    return numsSize-1 <= maxCanReach;
}

int main()
{
//	int arr[]={3,2,1,0,4};
    int arr[]={2,3,1,1,4};
	printf("%d ",canJump(arr,5));
} 
