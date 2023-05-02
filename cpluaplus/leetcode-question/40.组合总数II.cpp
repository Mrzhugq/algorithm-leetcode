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

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}


void backtracking(int *candidates,int candidatesSize,int target,int cur, int *used)
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
        // used[i - 1] == true，说明同⼀树⽀candidates[i - 1]使⽤过
        // used[i - 1] == false，说明同⼀树层candidates[i - 1]使⽤过
        // 而要去重的是 “同⼀树层上的使⽤过”
        if(i>0 && candidates[i]==candidates[i-1] && used[i-1]==false)
        {
            continue;
        }
        temp[tempSize++]=candidates[i];
        used[i] = true;
        backtracking(candidates,candidatesSize,target,i+1,used);
        //每个数字在每个组合中只能使用一次，所以用i+1
        tempSize--;
        used[i] = false;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    //candidates里面可有重复的数字，但答案不能重复 -> 组合不能相等，组合里面的数能有相等的 
    //used数组用来标记是否用过
    tempSize=ansSize=0;
    int *used = (int*)calloc(sizeof(int) , 2001);//先都设定为false
    temp=(int*)malloc(sizeof(int) * 2001);
    ansColumnSize=(int*)malloc(sizeof(int) * 2001);
    ans=(int**)malloc(sizeof(int*) * 2001);

    qsort(candidates, candidatesSize, sizeof(int), cmp);
    //⾸先把给candidates排序，让其相同的元素都挨在一起。
    backtracking(candidates,candidatesSize,target,0,used);

    *returnSize=ansSize;
    returnColumnSizes[0]=ansColumnSize;
    return ans;
}


