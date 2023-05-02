#include<stdio.h>

//ֱ�Ӳ���������Ż� -> ϣ������
//1.�Ƚ���Ԥ����(������,ÿ���gapһ��)��������ӽ�����(����������ֱ�Ӳ�������Ч�ʸ���) 
//2.ֱ�Ӳ������� -> O(N) 
//ʱ�临�Ӷ�O(log3N * N) ���� O(logN * N)
void SheelSort(int *arr,int Size)
{
	int gap=Size;
	
	while(gap > 1)
	{
		//gap >1 ʱ����Ԥ����          ->�ӽ����� 
		//gap==1 ʱ����ֱ�Ӳ�������    ->��ȫ���� 
		//����gap=gap/3 + 1; 
		gap=gap/2; //��2���Ա�֤���һ��gap==1 -> �����ȫ���� 
		for(int i=0; i<Size-gap; i++)//�Ѽ��Ϊgap�Ķ�������ͬʱ�ţ����i == Size-gap-1 
		{
			int end=i;
			int temp=arr[end+gap];
			while(end >= 0)
			{
				if(arr[end] > temp)
				{
					arr[end+gap]=arr[end];
					end=end-gap;
				}
				else
				{
					break;
				}
			}
			arr[end+gap]=temp;
		}
	}
}


int main()
{
	int arr[]={5,2,1,4,3};
	SheelSort(arr,5);
	for(int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}
