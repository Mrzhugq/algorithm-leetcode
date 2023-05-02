//˼·����ȥ����ո����巴ת��Ȼ�󵥸���ת���ʣ��ռ�O(1)
//ע�⣬ȥ������ո�ʱ��Ҫ��erase��ʹ����ʱ�����O(N^2)�ˣ���Ϊ����erase���ǰѺ��渲�ǵ�ǰ��Ĺ���
//      ����ʹ��˫ָ��+resize

class Solution 
{
private:
    void reverse(string &s, int start, int end) //��ת����[start, end]
    {
        for(int i=start,j=end; i<j; i++,j--)
        {
            swap(s[i], s[j]);
        }
    }
    void removeExtraSpaces(string &s) //����˫ָ��ȥ������ո�(����erase)
    {
        int fastIndex = 0;
        int slowIndex = 0;
        while(s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') //ȥ��ǰ��ո�
        {
            fastIndex++;
        }
        //ȥ���м����ո� �� �������Ŀո������ո�ȥ�����꣬������һ���ո�
        for( ; fastIndex < s.size(); fastIndex++)
        {
            if(fastIndex - 1 > 0 && s[fastIndex-1] == s[fastIndex] && s[fastIndex] == ' ')
            {
                continue;
            }
            else
            {
                s[slowIndex] = s[fastIndex];
                ++slowIndex;
            }
        }
        //ȥ������һ���ո�(ֻ���ж�һ�����һ���ַ��Ƿ��ǿո�)
        if(slowIndex - 1 > 0 && s[slowIndex - 1] == ' ')
        {
            s.resize(slowIndex - 1);
        }
        else
        {
            s.resize(slowIndex);
        }

    }
public:
    string reverseWords(string s)
    {
        removeExtraSpaces(s);         //ȥ������ո�
        reverse(s, 0, s.size() - 1);  //���巴ת

        for(int i=0; i<s.size(); i++) //������������[i,j-1]
        {
            int j = i;
            while(j < s.size() && s[j] != ' ')//���ҵ��ʼ�Ŀո�
            {
                j++;
            }
            reverse(s, i, j - 1);
            i = j;
        }

        // int start = 0, end = 0;       //��ת�������ʵ���ʼ�ͽ���λ��
        // for( ; end < s.size(); end++)
        // {
        //     if(s[end] == ' ')
        //     {
        //         reverse(s, start, end-1);
        //         start = end + 1;
        //     }
        // }
        // reverse(s, start, s.size() - 1); //��ת���һ��©���ĵ���
        return s;
    }
};


