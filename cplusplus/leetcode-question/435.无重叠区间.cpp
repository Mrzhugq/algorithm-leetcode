
//���������Ҷ˵����򣬴������Ҽ�¼�ǽ�������ĸ�����
//����������������ǽ�������ĸ���������Ҫ�Ƴ�����ĸ����ˡ�

//̰�� 
//�ֲ����ţ�����ѡ�ұ߽���С�����䣬���Դ������ұ�����������һ������Ŀռ��һ�㣬�Ӷ��������⽻��
//ȫ�����ţ�ѡȡ���ķǽ�������

class Solution 
{
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp); //���������Ҷ˵��������ظ���Ŀ��ұ�
        
        int count = 1;                 //��¼�ǽ�������ĸ���
        int end = intervals[0][1];     //����������С���ұ߽�(��¼����ָ��)
        for(int i = 1; i < intervals.size(); i++)
        {
            if(end <= intervals[i][0]) //ͳ�Ʒ��ظ�����������
            {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};
