//�����ߴ���ɿ��������θ�ڣ�����������Сθ�ڣ�����ι����θ��
//�ֲ����� -> �������ţ�̰�ģ�

// s = [1,2,3]  ����
// g = [1,2]    θ��
// 
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        //�Ӻ���ǰ����������ɸ���θ��  ->  ��ʵ��������forѭ�����������鷳��
        int index = s.size() - 1; //�������ߴ�
        int res = 0;
        for(int i = g.size() - 1; i >= 0; i--) //�������θ��
        {
            if(index >= 0 && s[index] >= g[i])
            {
                index--;
                res++;
            }
        }
        return res;
    }
};
