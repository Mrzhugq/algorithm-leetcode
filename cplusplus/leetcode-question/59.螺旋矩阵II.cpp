
/*
[
    [1,2,3]
    [8,9,4]
    [7,6,5]
]
*/

class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> res(n, vector<int>(n, 0)); //创建一个n^n二维数组
        int startX = 0, startY = 0; //每圈循环开始的位置，第一圈(0,0) 第二圈(1,1) ...
        int loop = n / 2;           //循环的圈数，n==3,填充一圈，n==5 需要填充两圈
        int mid = n / 2;            //矩阵中间位置，如果n为奇数，中间位置需要最后处理（n=3，中间位置(1,1)）
        int i, j;
        int count = 1;              //1 ~  n^2
        int offset = 1;             //每一圈循环，需要控制每一条边遍历的长度 (左闭右开)

        while(loop--)
        {
            i = startX;
            j = startY;
            //填充上行,从左到右  例如3^3矩阵(0,0) -> (0,2) (左闭右开 0,2这个for循环填不上，下面一样)
            for(; j < startX + n - offset; j++)
            {
                res[i][j] = count++;
            }
            //填充右列,从上到下  (0,2) -> (2,2)
            for(; i < startY + n - offset; i++)
            {
                res[i][j] = count++;
            }
            //填充下行,从右到左  (2,2) -> (2,0)
            for(; j > startY; j--)
            {
                res[i][j] = count++;
            }
            //填充左列,从下到上  (2,0) -> (0,0)
            for(; i > startX; i--)
            {
                res[i][j] = count++;
            }

            //第二圈起始位置都要加一，例如5^5矩阵第一圈开始(0, 0) ->  第二圈开始(1, 1)
            startX++;
            startY++;
            //offset 控制每一圈里每一条边遍历的长度, 因为要左闭右开所以加2
            //例如5^5矩阵上行x坐标区间, 第一圈 [0,4) ,第二圈 [1,2)
            offset += 2;
        }
        if(n % 2 == 1)
        {
            res[mid][mid] = count;
        }
        return res;
    }
};
