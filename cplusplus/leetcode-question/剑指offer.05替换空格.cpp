//�ܶ��������������⣬��������Ԥ�ȸ��������ݣ�Ȼ���ڴӺ���ǰ���в���

//�Ӻ���ǰ���O(N)�ĺô���1.���������µ����� 
//                      2.�����˴�ǰ�������Ԫ��O(N^2)Ҫ����ÿ�����Ԫ�ض�Ҫ�����Ԫ��֮�������Ԫ�ض���������

class Solution 
{
public:
    string replaceSpace(string s) 
    {
        int count = 0;
        int OldSize = s.size();
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                count++;
            }
        }
        s.resize(s.size() + 2 * count); //�����䵽�ո��滻Ϊ%20��Ĵ�С
        int NewSize = s.size();         //��ʱ��s.size()�Ѿ���OldSize+2*count��
        
        //����˫ָ��Ӻ���ǰ�������
        for(int i=OldSize-1, j=NewSize-1; i<j; i--,j--) //i<j -> i==j����ѭ��������
        {
            if(s[i] != ' ')
            {
                s[j] = s[i];
            }
            else ///s[i] == ' '
            {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};
