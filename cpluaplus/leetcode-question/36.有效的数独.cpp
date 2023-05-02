bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int row=boardSize;
    int col=*boardColSize;
    for(int x=0;x<row;x++)
    {
        for(int y=0;y<col;y++)
        {
            if(board[x][y]!='.')
            {
                //查找一列
                for(int j=0;j<col;j++)
                {
                    if(j!=y)
                    if(board[x][j]==board[x][y])
                    return false;
                }
                //查找一行
                for(int i=0;i<row;i++)
                {
                    if(i!=x)
                    if(board[i][y]==board[x][y])
                    return false;
                }
                //查找每个子块
                int sx=x/3*3;
                int sy=y/3*3;
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(sx+i!=x && sy+j!=y && board[sx+i][sy+j]==board[x][y])
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
