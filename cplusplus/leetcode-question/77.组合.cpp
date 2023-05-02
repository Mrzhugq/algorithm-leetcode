
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int* temp;
int tempSize;

int** ans;
int ansSize;

void backtracking(int n,int k,int cur)
{
	// 剪枝：temp 长度加上区间 [cur, n] 的长度小于k，不可能构造出长度为k的temp
	if (tempSize + (n - cur + 1) < k)
	{
		return;
	}
    //满足条件
    if(tempSize == k)
    {
        int *ret=(int*)malloc(sizeof(int) * k);
        for(int i=0; i<k; i++)
        {
            ret[i]=temp[i];
        }
        ans[ansSize++]=ret;
        return;
    }
    //递归回溯
    for(int i=cur; i<=n; i++)
    {
        temp[tempSize++]=i;
        backtracking(n,k,i+1);
        tempSize--;
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    temp=(int*)malloc(sizeof(int) * k);
    ans=(int**)malloc(sizeof(int*) * 10001);
    tempSize=ansSize=0;
    
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