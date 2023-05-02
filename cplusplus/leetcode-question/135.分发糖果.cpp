
/*
����̰�ģ�
1.�ֲ����ţ�ֻҪ�ұ����ֱ���߶࣬�ұ߾Ͷ�һ���ǹ���
  ȫ�����ţ����ڵĺ����У����ָߵ��Һ��ӻ�û�ñ����Ӹ�����ǹ�
2.�ֲ����ţ�ȡcandyVec[i],candyVec[i+1]+1�����ǹ�����,��֤��i��С�����ǹ��������������Ҳ�����ұߵ�
  ȫ�����ţ����ڵĺ����У����ָߵĺ��ӻ�ø�����ǹ�
*/

class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        vector<int> candyVec(ratings.size(), 1);
        
        //��ȷ�������ִ��������ֵ��������ǰ����������
        for (int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i - 1] < ratings[i])
            {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }

        //��ȷ�������ִ��������ֵ��������ʱ��Ҫ�Ӻ���ǰ������
        //��Ϊ�����ǰ�����û��������һ�εıȽϽ����
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
            {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
                //ȡ���ֵ���ܱ�֤��i���õ��ǹ�����ߺ��ұ߶���
            }
        }

        int res = 0;
        for (int num : candyVec)
        {
            res += num;
        }
        return res;
    }
};
