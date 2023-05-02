#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1.数学方法 
int* getRow(int rowIndex, int* returnSize)
{
    *returnSize=rowIndex+1;
    int *ret=(int*)malloc(sizeof(int)*(*returnSize));
    ret[0]=1;
    for(int i=1;i<=rowIndex;i++)
    {
        ret[i]=(long long)ret[i-1] * (rowIndex-i+1)/i;
    }
    return ret;
}

int main()
{
	int n=3;
	int returnSize=0;
	int *ret=getRow(3,&returnSize);
	for(int i=0;i<returnSize;i++)
	{
		printf("%d ",ret[i]);
	}
} 


