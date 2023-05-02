
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
        vector<vector<int>> res(n, vector<int>(n, 0)); //����һ��n^n��ά����
        int startX = 0, startY = 0; //ÿȦѭ����ʼ��λ�ã���һȦ(0,0) �ڶ�Ȧ(1,1) ...
        int loop = n / 2;           //ѭ����Ȧ����n==3,���һȦ��n==5 ��Ҫ�����Ȧ
        int mid = n / 2;            //�����м�λ�ã����nΪ�������м�λ����Ҫ�����n=3���м�λ��(1,1)��
        int i, j;
        int count = 1;              //1 ~  n^2
        int offset = 1;             //ÿһȦѭ������Ҫ����ÿһ���߱����ĳ��� (����ҿ�)

        while(loop--)
        {
            i = startX;
            j = startY;
            //�������,������  ����3^3����(0,0) -> (0,2) (����ҿ� 0,2���forѭ����ϣ�����һ��)
            for(; j < startX + n - offset; j++)
            {
                res[i][j] = count++;
            }
            //�������,���ϵ���  (0,2) -> (2,2)
            for(; i < startY + n - offset; i++)
            {
                res[i][j] = count++;
            }
            //�������,���ҵ���  (2,2) -> (2,0)
            for(; j > startY; j--)
            {
                res[i][j] = count++;
            }
            //�������,���µ���  (2,0) -> (0,0)
            for(; i > startX; i--)
            {
                res[i][j] = count++;
            }

            //�ڶ�Ȧ��ʼλ�ö�Ҫ��һ������5^5�����һȦ��ʼ(0, 0) ->  �ڶ�Ȧ��ʼ(1, 1)
            startX++;
            startY++;
            //offset ����ÿһȦ��ÿһ���߱����ĳ���, ��ΪҪ����ҿ����Լ�2
            //����5^5��������x��������, ��һȦ [0,4) ,�ڶ�Ȧ [1,2)
            offset += 2;
        }
        if(n % 2 == 1)
        {
            res[mid][mid] = count;
        }
        return res;
    }
};
