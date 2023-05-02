#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char ** fizzBuzz(int n, int* returnSize)
{
    char **ret = (char **)malloc(sizeof(char *) * n);
    for (int i = 1; i <=n; i++) 
    {
        ret[i-1] = (char *)malloc(sizeof(char) * 9);
        if ((i % 3 == 0) && (i % 5 == 0)) 
        {
            strcpy(ret[i-1], "FizzBuzz");
        } 
        else if (i % 3 == 0) 
        {
            strcpy(ret[i-1], "Fizz");
        } 
        else if (i % 5 == 0) 
        {
            strcpy(ret[i-1], "Buzz");
        } 
        else 
        {
            sprintf(ret[i-1], "%d", i);
        }
    }
    *returnSize = n;
    return ret;
}


int main()
{
	int n=9;
	int returnSize=0;
	char **ret=fizzBuzz(n,&returnSize);
	for(int i=0;i<returnSize;i++)
	{
		printf("%s\n",ret[i]);
	}
} 
