/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


//题目给出了多个1，要找出每个1到0的最近曼哈顿距离。由于1到0的距离和0到1的距离一样的，
//所以其实我们可以换个思维：找出每个0到1的距离。
//因此，题目可以抽象成：多个起始点的BFS。恭喜你已经解决了一半问题。
//最下面还有例子

#define MAX_SIZE 10240
#define Min(a, b) (a < b ? a : b)
typedef struct pos
{
    int x;
    int y;
}Pos;

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes)
{
    int n = matSize;
    int m = *matColSize;
    *returnSize = n;//返回数组行数
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);//返回数组列数
    for(int i=0; i<n; i++)
    {
        (*returnColumnSizes)[i] = m; 
    }

    Pos* queue = (Pos*)malloc(sizeof(Pos) * MAX_SIZE);//队列
    int front = 0;//队列头
    int rear = 0;//队列尾

    int **result = (int**)malloc(sizeof(int*) * n);//返回的二维数组
    //初始化result二维数组
    for(int i=0; i<n; i++)
    {
        result[i] = (int*)calloc(sizeof(int) , m);
        for(int j=0; j<m; j++)
        {
            if(mat[i][j] != 0)
            {
                result[i][j] = INT_MAX;
            }
            else//把是0的坐标入队
            {
                queue[front].x = i;
                queue[front].y = j;
                front++;
            }
        }
    }
    // 广度优先搜索
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//左，右，下，上
    while(rear < front)
    {
        Pos p = queue[rear];
        rear++;
        for(int i=0; i<4; i++)
        {
            int x = p.x + dirs[i][0];//四个方向
            int y = p.y + dirs[i][1];
            if(x>=0 && x<n && y>=0 && y<m)//不越界执行下面
            {
                if(result[x][y] > result[p.x][p.y] + 1)//取小的并把新的四个方向入队
                {
                    result[x][y] = result[p.x][p.y] + 1;
                    queue[front].x = x;
                    queue[front].y = y;
                    front++;
                }
            }  
        }
    }
    return result;
}


/* 
//前
mat：   _代表1
_ _ _ _
_ 0 _ _
_ _ 0 _
_ _ _ _

//初始化后
queue:
(1,1)  (2,2)
 rear         front

result： M代表INT_MAX
M M M M
M 0 M M
M M 0 M
M M M M

*/
