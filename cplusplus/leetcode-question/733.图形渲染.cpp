

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
 /*
[
    [1,1,1]
    [1,1,0]
    [1,0,1]

    [2,2,2]
    [2,2,0]
    [2,0,1]
]
*/
void BFS(int **image,int n,int m,int sr,int sc,int oldColor,int newColor)
{
    if(sr < 0 || sr >= n 
        || sc < 0 ||sc >= m)
    {
        return;
    }

    if(image[sr][sc] == oldColor)
    {
        image[sr][sc] = newColor;
        BFS(image, n, m, sr-1, sc, oldColor, newColor);//ио
        BFS(image, n, m, sr+1, sc, oldColor, newColor);//об
        BFS(image, n, m, sr, sc-1, oldColor, newColor);//вС
        BFS(image, n, m, sr, sc+1, oldColor, newColor);//ср
    }
    return;
} 

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes)
{
    int n = imageSize;
    int m = imageColSize[0];
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for(int i=0; i<n; i++)
    {
        (*returnColumnSizes)[i] = m;
    }
    if(image[sr][sc] != newColor)
    {
        int oldColor = image[sr][sc];
        BFS(image, n, m, sr, sc, oldColor, newColor);
    }
    return image;
}

