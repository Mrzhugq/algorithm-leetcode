//����ת���Ժ�ת���壬������ת�����ȷ�ת���壨����û���𡣹�����

class Solution 
{
public:
    string reverseLeftWords(string s, int n) 
    {
        
        reverse(s.begin(), s.begin() + n);  //[ )
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

//abcdefg
//ba gfedc
//cdefgab

