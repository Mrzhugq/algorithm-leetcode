/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


//��Ŀ�����˶��1��Ҫ�ҳ�ÿ��1��0����������پ��롣����1��0�ľ����0��1�ľ���һ���ģ�
//������ʵ���ǿ��Ի���˼ά���ҳ�ÿ��0��1�ľ��롣
//��ˣ���Ŀ���Գ���ɣ������ʼ���BFS����ϲ���Ѿ������һ�����⡣
//�����滹������

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
    *returnSize = n;//������������
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);//������������
    for(int i=0; i<n; i++)
    {
        (*returnColumnSizes)[i] = m; 
    }

    Pos* queue = (Pos*)malloc(sizeof(Pos) * MAX_SIZE);//����
    int front = 0;//����ͷ
    int rear = 0;//����β

    int **result = (int**)malloc(sizeof(int*) * n);//���صĶ�ά����
    //��ʼ��result��ά����
    for(int i=0; i<n; i++)
    {
        result[i] = (int*)calloc(sizeof(int) , m);
        for(int j=0; j<m; j++)
        {
            if(mat[i][j] != 0)
            {
                result[i][j] = INT_MAX;
            }
            else//����0���������
            {
                queue[front].x = i;
                queue[front].y = j;
                front++;
            }
        }
    }
    // �����������
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//���ң��£���
    while(rear < front)
    {
        Pos p = queue[rear];
        rear++;
        for(int i=0; i<4; i++)
        {
            int x = p.x + dirs[i][0];//�ĸ�����
            int y = p.y + dirs[i][1];
            if(x>=0 && x<n && y>=0 && y<m)//��Խ��ִ������
            {
                if(result[x][y] > result[p.x][p.y] + 1)//ȡС�Ĳ����µ��ĸ��������
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
//ǰ
mat��   _����1
_ _ _ _
_ 0 _ _
_ _ 0 _
_ _ _ _

//��ʼ����
queue:
(1,1)  (2,2)
 rear         front

result�� M����INT_MAX
M M M M
M 0 M M
M M 0 M
M M M M

*/
