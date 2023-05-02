
class Solution 
{
private:
    vector<vector<string>> result;

    //判断该位置是否合法（该位置的横行、纵行或斜线不能有皇后）
    bool IsValid(int row, int col, vector<string>& chessboard, int n)
    {
        //不用检查行因为每次递归row都会加1，所有每次都是新的一层，不会有皇后
        //（每一层递归，只会选for循环（也就是同一行）里的一个元素，所以不用去重）
        for(int i=row-1; i>=0; i--) //检查列方向
        {
            if(chessboard[i][col] == 'Q')
            {
                return false;
            }
        }
        for(int i=row-1, j=col-1; (i>=0 && j>=0); i--, j--) //135度方向上
        {
            if(chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        for(int i=row-1, j=col+1; (i>=0 && j<n); i--, j++) //45度方向上
        {
            if(chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(int n, int row, vector<string>& chessboard)//用row记录递归到那一层了
    {
        if(n == row)
        {
            result.push_back(chessboard);
            return;
        }
        for(int col=0; col < n; col++)
        {
            if(IsValid(row, col, chessboard, n))
            {
                chessboard[row][col] = 'Q';
                backtracking(n, row+1, chessboard); //row+1 递归下一层
                chessboard[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        result.clear();
        vector<string> chessboard(n, string(n,'.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

