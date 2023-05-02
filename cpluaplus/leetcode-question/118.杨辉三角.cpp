//118. 
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int **dummy=(int **)malloc(sizeof(int *)*numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for(int i=0;i<numRows;i++)
    {
        dummy[i] = malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        dummy[i][0] = dummy[i][i] = 1;
        for(int j=1;j<i;j++)
        {
            dummy[i][j]=dummy[i-1][j-1]+dummy[i-1][j];
        }
     }
    return dummy;
}
