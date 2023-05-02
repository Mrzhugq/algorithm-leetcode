typedef struct pos
{
    int x;
    int y;
}Pos;

int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int n = gridSize;
    int m = *gridColSize;
    int size = n*m;

    Pos* queue = (Pos*)malloc(sizeof(Pos) * size);
    int front = 0;//队列头
    int rear = 0;//队列尾

    for(int i=0; i<n; i++)//把坏橘子入队
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 2)
            {
                queue[front].x = i;
                queue[front].y = j;
                front++;
            }
        }
    }

    int count = 0;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//左，右，下，上
    while(rear < front)
    {
        int temprear = rear;//如果有多个2(坏橘子)应该同时扩散,例如下面的第二个例子
        int tempfront = front;
        for(int time=temprear; time<tempfront; time++)
        {
            Pos p = queue[time];
            for(int i=0; i<4; i++)
            {
                int x = p.x + dirs[i][0];//四个方向
                int y = p.y + dirs[i][1];
                if(x>=0 && x<n && y>=0 && y<m)//不越界执行下面
                {
                    if(grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        queue[front].x = x;
                        queue[front].y = y;
                        front++;
                    }
                }  
            }
        }
        rear = tempfront;
        count++;
    }

    //看下是否还有好橘子
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 1)
            return -1;
        }
    }

    return count > 0 ? count-1 : 0;
}


/*

//1.
[
    [2,1,1]
    [1,1,0]
    [0,1,1]
]

//2.
[
    [2,1,1]
    [1,1,0]
    [0,2,1]
]

//3.
[
    [2,1,1]
    [0,1,1]
    [1,0,1]
]
*/
