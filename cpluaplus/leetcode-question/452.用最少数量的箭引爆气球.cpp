//̰��
//�ֲ����ţ��������ص�ʱ��һ���䣬���ù������� ȫ�����ţ����������������䱬���ù�������

//�������򾡿����������ظ�����ʼ������ʼλ�û�����ֹλ�������У�ֻ�Ǳ���˳��ͬ
//��������ظ��ˣ��ص��������ұ߽߱����Сֵ֮���������Ҫһ������
class Solution 
{
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.size() == 0)  return 0;
        sort(points.begin(), points.end(), cmp); 
        //������ʼλ�����򣬾������������ظ�
        
        int res = 1; //����1
        for (int i = 1; i < points.size(); i++)
        {
            if(points[i - 1][1] < points[i][0]) //����i-1��i������ ,ע����< ,����<=
            {
                res++;
            }
            else //������
            {
                points[i][1] = min(points[i - 1][1], points[i][1]); 
                //�����������С�ұ߽�
            }
        }
        return res;
    }
};



/*
[[10,16],[2,8],[1,6],[7,12]]
���������ͼ��
   1-------6
      2--------8
              7---------12
                     10--------16    
*/



