
class Solution 
{
private:
    bool IsValid(int row, int col, char k, vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)  //列
        {
            if(board[i][col] == k)
            {
                return false;
            }
        }
        for(int j=0; j<9; j++) //行
        {
            if(board[row][j] == k)
            {
                return false;
            }
        }
        int StartRow = (row / 3 ) * 3;  //这3*3的范围要注意注意
        int StartCol = (col / 3 ) * 3;
        for(int i=StartRow; i<StartRow+3; i++)
        {
            for(int j=StartCol; j<StartCol+3; j++)////3*3宫内
            {
                if(board[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }
    //?维递归，不想那个N皇后一样，那个每行放一个数就行，而这个题每行需要放多个数，直到填满
    bool backtracking(vector<vector<char>>& board)
    {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] != '.') continue;
                for(char k = '1'; k<='9'; k++)
                {
                    if(IsValid(i, j, k, board))
                    {
                        board[i][j] = k;
                        if(backtracking(board))  return true; //找到一个数独就行了
                        board[i][j] = '.';
                    }
                }
                return false; //9个数都不满足就返回，防止死循环
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        backtracking(board);
    }
};}

