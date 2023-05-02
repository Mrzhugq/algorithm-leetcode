/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int* temp;
int tempSize;

int** ans;
int ansSize;

//求和函数
int tempsum(int *arr,int Size)
{
    int sum=0;
    for(int i=0; i<Size; i++)
    {
        sum=sum+arr[i];
    }
    return sum;
}

void backtracking(int targetsum,int k,int cur)
{
    //剪枝
    if (tempSize + (9 - cur + 1) < k || tempSize > k)
	{
		return;
	}
    //满足条件
    if(tempSize == k && tempsum(temp,tempSize) == targetsum)
    {
        int *ret=malloc(sizeof(int) * k);
        for(int i=0; i<k; i++)
        {
            ret[i]=temp[i];
        }
        ans[ansSize++]=ret;
        return;
    }
    //递归回溯
    for(int i=cur; i<=9; i++)
    {
        temp[tempSize++]=i;
        backtracking(targetsum,k,i+1);
        tempSize--;
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes)
{
    temp=(int*)malloc(sizeof(int) * 2001);
    ans=(int**)malloc(sizeof(int*) * 2001);
    ansSize=tempSize=0;
    //虽然全局变量会默认为0，但测试时会多次调用这个函数，所以每次调用都要重新归零

    backtracking(n,k,1);

    //分配返回数组的行和列
    *returnSize=ansSize;
    returnColumnSizes[0]=(int*)malloc(sizeof(int) * ansSize);
    for(int i=0; i<ansSize; i++)
    {
        returnColumnSizes[0][i]=k;
    }
    return ans;
}
