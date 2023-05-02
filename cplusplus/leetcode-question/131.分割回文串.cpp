/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

char **temp;//存放回文的字串
int tempSize;

char ***ans;
int ansSize;

bool isPalindrome(char *s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

void backtracking(char *s,int len, int *retcolSize, int cur)
{
    if(cur >= len)
    {
        char **ret = (char**)malloc(sizeof(char*) * tempSize);
        for(int i=0; i<tempSize; i++)
        {
            int templen=strlen(temp[i]);
            ret[i] = (char*)malloc(sizeof(char) * (templen+1));
            strcpy(ret[i], temp[i]);
        }
        ans[ansSize] = ret;
        retcolSize[ansSize] = tempSize;
        ansSize++;
        return;
    }

    for(int i=cur; i<len; i++)
    {
        if(isPalindrome(s,cur,i))
        {
            char *sub =(char*)malloc(sizeof(char) * (i - cur + 2));
            //1. 
            memcpy(sub, s+cur, sizeof(char) * (i-cur+1));
            //2.
            //strncpy(sub, s+cur, sizeof(char) * (i-cur+1));
            //3.
            // for(int k=cur; k<=i; k++)
            // {
            //     sub[k-cur] = s[k];
            // }
            sub[i-cur+1] = '\0';
            temp[tempSize++] = sub;
            backtracking(s, len, retcolSize, i+1);
            tempSize--;
        }
        else
        {
            continue;
        }
    }
}

char *** partition(char * s, int* returnSize, int** returnColumnSizes)
{
    tempSize=ansSize=0;
    int len = strlen(s);
	int ansMaxLen = len * (1 << len);//我也不知道为何最大长度是这个
    temp = (char**)malloc(sizeof(char*) * len);
    ans = (char***)malloc(sizeof(char**) * ansMaxLen);
    
    *returnSize=0;
    returnColumnSizes[0] = (int*)malloc(sizeof(int*) * ansMaxLen);

    backtracking(s, len, returnColumnSizes[0], 0);
    *returnSize = ansSize;
    return ans;
}