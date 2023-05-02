
class Solution 
{
private:
    vector<vector<string>> result;

    //�жϸ�λ���Ƿ�Ϸ�����λ�õĺ��С����л�б�߲����лʺ�
    bool IsValid(int row, int col, vector<string>& chessboard, int n)
    {
        //���ü������Ϊÿ�εݹ�row�����1������ÿ�ζ����µ�һ�㣬�����лʺ�
        //��ÿһ��ݹ飬ֻ��ѡforѭ����Ҳ����ͬһ�У����һ��Ԫ�أ����Բ���ȥ�أ�
        for(int i=row-1; i>=0; i--) //����з���
        {
            if(chessboard[i][col] == 'Q')
            {
                return false;
            }
        }
        for(int i=row-1, j=col-1; (i>=0 && j>=0); i--, j--) //135�ȷ�����
        {
            if(chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        for(int i=row-1, j=col+1; (i>=0 && j<n); i--, j++) //45�ȷ�����
        {
            if(chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(int n, int row, vector<string>& chessboard)//��row��¼�ݹ鵽��һ����
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
                backtracking(n, row+1, chessboard); //row+1 �ݹ���һ��
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

