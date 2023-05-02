
class Solution 
{
private:
    bool IsValid(int row, int col, char k, vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)  //��
        {
            if(board[i][col] == k)
            {
                return false;
            }
        }
        for(int j=0; j<9; j++) //��
        {
            if(board[row][j] == k)
            {
                return false;
            }
        }
        int StartRow = (row / 3 ) * 3;  //��3*3�ķ�ΧҪע��ע��
        int StartCol = (col / 3 ) * 3;
        for(int i=StartRow; i<StartRow+3; i++)
        {
            for(int j=StartCol; j<StartCol+3; j++)////3*3����
            {
                if(board[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }
    //?ά�ݹ飬�����Ǹ�N�ʺ�һ�����Ǹ�ÿ�з�һ�������У��������ÿ����Ҫ�Ŷ������ֱ������
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
                        if(backtracking(board))  return true; //�ҵ�һ������������
                        board[i][j] = '.';
                    }
                }
                return false; //9������������ͷ��أ���ֹ��ѭ��
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

