
/*
[
 [0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]
 ]
*/

int DBS(int** grid, int n, int m, int cur_i, int cur_j)
{
    if(cur_i < 0 || cur_i >= n 
        || cur_j < 0 || cur_j >=m)
    {
            return 0;
    }

    grid[cur_i][cur_j] = 0;//把走过的都标记为0
    int count = 1;
    if(cur_i-1 >= 0 && grid[cur_i-1][cur_j] == 1)
    {
        count += DBS(grid, n, m, cur_i-1, cur_j);//上
    }
    if(cur_i+1 < n && grid[cur_i+1][cur_j] == 1)
    {
        count += DBS(grid, n, m, cur_i+1, cur_j);//下
    }
    if(cur_j-1 >= 0 && grid[cur_i][cur_j-1] == 1)
    {
        count += DBS(grid, n, m, cur_i, cur_j-1);//左
    }
    if(cur_j+1 < m && grid[cur_i][cur_j+1] == 1)
    {
        count += DBS(grid, n, m, cur_i, cur_j+1);//右
    }
    return count;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int n = gridSize;
    int m = *gridColSize;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 1)
            {
                ans = fmax(ans, DBS(grid, n, m, i, j));
            }
        }
    }
    return ans;
}
