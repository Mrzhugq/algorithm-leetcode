#include<stdio.h>
 
//ֱ�Ӳ������� O(N^2)
//� ������ 1+2+3+...+n-1 
//��� ��˳�� O(N) 
void InsertSort(int *arr,int Size)
{
	for(int i=0; i<Size-1; i++)
	{
		//����±�[0,end]���򣬰� end+1 ����� [0,end+1] ����
		//i<Size-1   ��end���һ��λ����Size-2 -> �����ڶ���λ�ã������������һ��λ�ã�end+1��Խ�� 
		int end=i;
		int temp=arr[end+1];
		while(end >= 0)//�������ڵ�һ��λ�� 
		{
			if(arr[end] > temp)//ֻҪ�����ֵҪ��ǰһ��С��ǰһ��������Ųһλ
			{
				arr[end+1]=arr[end];
				end--; 
			}
			else
			{
				break;
			}
		}
		//��� 1.break����������ҵ���tempС���� 2.whileѭ���������������end == -1��
		arr[end+1]=temp; 
	} 

}

int main()
{
	int arr[]={5,2,1,4,3};
	InsertSort(arr,5);
	for(int i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}
