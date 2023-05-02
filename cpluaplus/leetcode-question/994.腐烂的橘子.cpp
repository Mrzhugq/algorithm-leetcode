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
    int front = 0;//����ͷ
    int rear = 0;//����β

    for(int i=0; i<n; i++)//�ѻ��������
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
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//���ң��£���
    while(rear < front)
    {
        int temprear = rear;//����ж��2(������)Ӧ��ͬʱ��ɢ,��������ĵڶ�������
        int tempfront = front;
        for(int time=temprear; time<tempfront; time++)
        {
            Pos p = queue[time];
            for(int i=0; i<4; i++)
            {
                int x = p.x + dirs[i][0];//�ĸ�����
                int y = p.y + dirs[i][1];
                if(x>=0 && x<n && y>=0 && y<m)//��Խ��ִ������
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

    //�����Ƿ��к�����
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
