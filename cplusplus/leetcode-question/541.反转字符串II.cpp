//����Ҫ�̶�����һ��һ��ȥ�����ַ�����ʱ��Ҫ������forѭ���ı��ʽ����������

class Solution 
{
public:
    string reverseStr(string s, int k) 
    {
        for(int i=0; i<s.size(); i += (2 * k)) //iÿ��һ��2*k�Ϳ����ҵ�ÿ��Ҫ��ת��ʼ��������
        {
            if(i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k); // [ ���� )
            }
            else //ʣ���ַ�����k������ʣ���ַ�ȫ����ת
            {
                reverse(s.begin() + i, s.begin() + s.size());
                //reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
