#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=0;
	printf("������һ��10����������\n");
	scanf("%d",&n);
	while(1)
	{
		if(n%2==1 && n>1 && n<=10)
		{
			break;
		}
		else
		{
			printf("��������д����������룺\n");
			scanf("%d",&n);
		}
	}
	int **arr=(int **)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
	{
		arr[i]=(int*)calloc(sizeof(int),n);
		arr[i][i]=1;
	}
	printf("��������Ϊ��\n"); 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	free(arr);
	for(int i=0;i<n;i++)
	{
		free(arr[i]);
	}
	
} 
