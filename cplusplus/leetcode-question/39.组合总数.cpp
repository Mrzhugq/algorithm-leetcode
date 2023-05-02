/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int *temp;
int tempSize;

int **ans;
int *ansColumnSize;
int ansSize;

int Sum(int *arr, int Size)
{
    int sum=0;
    for(int i=0; i<Size; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

void backtracking(int *candidates,int candidatesSize,int target,int cur)
{
    if(Sum(temp,tempSize) > target)
    {
        return;
    }
    if(Sum(temp,tempSize) == target)
    {
        int *ret=(int*)malloc(sizeof(int) * (tempSize));
        for(int i=0; i<tempSize; i++)
        {
            ret[i]=temp[i];
        }
        ans[ansSize]=ret;
        ansColumnSize[ansSize]=tempSize;
        ansSize++;
        return;
    }

    for(int i=cur; i<candidatesSize; i++)
    {
        temp[tempSize++]=candidates[i];
        backtracking(candidates,candidatesSize,target,i);
        //不用i+1了，表示可以重复读取当前的数
        tempSize--;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    tempSize=ansSize=0;
    temp=(int*)malloc(sizeof(int) * 2001);
    ansColumnSize=(int*)malloc(sizeof(int) * 1001);
    ans=(int**)malloc(sizeof(int*) * 1001);

    backtracking(candidates,candidatesSize,target,0);

    *returnSize=ansSize;
    returnColumnSizes[0]=ansColumnSize;
    return ans;
}


