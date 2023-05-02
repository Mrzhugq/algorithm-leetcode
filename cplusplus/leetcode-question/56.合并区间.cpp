//̰��
//�ֲ����ţ������ÿ�κϲ���ȡ�����ұ߽磬�����Ϳ��Ժϲ������������
//�������ţ��ϲ������ص�����(��ʵ̰�ľ��ǳ�ʶ����֪��ȡ����ұ߽�)

class Solution 
{
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;
        if(intervals.size() == 0) return res;
        
        sort(intervals.begin(), intervals.end(), cmp); //��������߽���������ʵ�����ұ߽������У�
        int size = intervals.size();
        bool flag = false; //������һ��������û�кϲ� 
        for(int i = 1; i < size; i++)
        {
            int start = intervals[i-1][0]; //��ʼ��Ϊi-1��������ұ߽�
            int end = intervals[i -1][1];
            while(i < size && end >= intervals[i][0]) //�ϲ����䣬ע����while����if����Ϊ���ܺϲ��������
            {
                end = max(end, intervals[i][1]); //Ҫȡ���ֵ������һ�����������һ����������
                if(i == size - 1) 
                {
                    flag = true;
                }
                i++; //�ǵ�i++���ϲ���һ������
            }
            res.push_back( {start, end} );
        }
        if(flag == false) //���һ���������û���ϲ����⴦��
        {
            res.push_back( {intervals[size - 1][0], intervals[size - 1][1]} );
        }
        return res;
    }
};
